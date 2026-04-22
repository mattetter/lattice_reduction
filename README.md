# Lenstra-Lenstra-Lovász Lattice Basis Reduction

This project is an implementation of the Lenstra-Lenstra-Lovász (LLL) lattice basis reduction algorithm in C++ using a custom-built Matrix class. 

## Background

LLL is a somewhat niche algorithm which can be used in breaking weak forms of RSA as well as playing a potential role in the lattice-based cryptography that may eventually replace RSA. 
This algorithm was selected primarily as a way to explore matrix operations while reiforcing some recently learned concepts surrounding the Gram-Schmidt algorithm. I also have a personal interest in cryptography and LLL has potential in that space. 

## Lattices

A lattice is an infinite set of n-dimensional points arranged at regular intervals in n-dimensional space. A basis of a given lattice is a set of linearly-independent n-vectors which can be combined with integer coefficients to give the coordinates of any point in the lattice. That relationship goes both ways. A lattice is also defined by its bases. The lattice corresponding to a particular basis is the set of all points reachable using integer numbers of its vectors. 

The key for this project is that the same lattice can be described by many different bases. Some are "better" than others: bases with shorter, more perpendicular vectors make downstream computations easier. LLL takes a basis as input and efficiently produces a better one. 

## LLL Breakdown

LLL takes in a basis 'B' and generates a new basis that covers the same lattice as B while satisfying two conditions that make the output easier to work with than B:

1. **Reduced size:** The size of the Gram-Schmidt projection coefficients will be smaller. From Kalbach and Chinburg; 

'|µi,j | ≤ 1/2 whenever i > j.'

2. **Lovász condition:** The vectors of the Gram_Schmidt orthogonalization of the new basis will not step down in size more than 1/2 of the size of the previous vector. That is,

$(δ − µ^2_{i, i-1}) * ||b*_i||^2 \leq ||b*_{i+1}||^2$
for all i < n.

b* here is the aforementioned set of orthogonal vectors of the new basis. They are used as intermediate step in the algorithm.

The algorithm iterates through the vectors of B and for each vector does a size-reduction and then a Lovász check. If the vector fails that check (the corresponding orthogonalization is too much smaller than the previous one) then the offending vector B[i] is swapped with the previous one B[i-1] and the algorithm rewinds back to process vector i-1. 

The algorithm is guaranteed to finish in polynomial time.


## Running the Demo

After cloning the repo run the following command to compile and run the demo. 

```
 g++ app/main.cpp code/matrix.cpp code/lll.cpp -o demo &&  ./demo 
 
 ```
 ### Demo Output

This runs the algorithm on first a 3x3 basis and then a 6x6 basis. It shows the basis in it's orginal state then after reducing. The byproducts of the algorithm μ and b* are also shown as a way to visually check that the algorithm worked. In the before for both bases we can clearly see that some of the coeficient values for mu are > 0.5, violating condition 1 from above, and the values of ||b_star_i||^2 are not uniform at all, easily violating condition 2 (the Lovász condition) shown above. Essentially the values of ||b_star_i||^2 cannot step down more than δ, which I have set to 0.75 here. 

```
==================================
 LLL Latice Basis Reduction Demo

Example with 3x3 basis

Before
----------------------------------
Basis: 
5.00 3.00 9.00 
2.00 -1.00 8.00 
4.00 3.00 7.00 

mu
0.00 0.00 0.00 
0.69 0.00 0.00 
0.80 -0.15 0.00 

Squared lengths of b* vectors:
115.00
14.73
0.07
----------------------------------

After
----------------------------------
Basis: 
-1.00 0.00 -2.00 
-2.00 -1.00 0.00 
1.00 -2.00 -1.00 

mu
0.00 0.00 0.00 
0.40 0.00 0.00 
0.20 -0.10 0.00 

Squared lengths of b* vectors:
5.00
4.20
5.76
----------------------------------
==================================
Example with 6x6 basis

Before
----------------------------------
Basis: 
2.00 -9.00 9.00 4.00 9.00 1.00 
7.00 7.00 7.00 7.00 6.00 7.00 
5.00 5.00 4.00 5.00 5.00 5.00 
1.00 7.00 1.00 1.00 1.00 8.00 
1.00 2.00 3.00 4.00 5.00 6.00 
7.00 8.00 9.00 10.00 11.00 12.00 

mu
0.00 0.00 0.00 0.00 0.00 0.00 
0.39 0.00 0.00 0.00 0.00 0.00 
0.27 0.71 0.00 0.00 0.00 0.00 
-0.12 0.60 0.30 0.00 0.00 0.00 
0.30 0.46 1.44 0.62 0.00 0.00 
0.66 1.33 1.92 0.63 0.94 0.00 

Squared lengths of b* vectors:
264.00
240.81
1.47
27.01
2.79
0.14
----------------------------------

After
----------------------------------
Basis: 
0.00 0.00 -1.00 0.00 -1.00 0.00 
-1.00 -1.00 0.00 -1.00 1.00 -1.00 
1.00 1.00 -3.00 1.00 2.00 1.00 
-2.00 -1.00 0.00 1.00 -1.00 3.00 
0.00 -1.00 1.00 -4.00 -1.00 3.00 
-4.00 3.00 0.00 0.00 1.00 0.00 

mu
0.00 0.00 0.00 0.00 0.00 0.00 
-0.50 0.00 0.00 0.00 0.00 0.00 
0.50 -0.33 0.00 0.00 0.00 0.00 
0.50 -0.33 -0.12 0.00 0.00 0.00 
0.00 0.22 -0.42 0.44 0.00 0.00 
-0.50 0.33 0.12 0.36 -0.26 0.00 

Squared lengths of b* vectors:
2.00
4.50
16.00
14.75
22.14
21.35
----------------------------------
```

In the after you can clearly see that the vectors in the basis are shorter, the values in mu are < 0.5 and the values of ||b_star_i||^2 are much more uniform. 

Optimally we would also test that the reduced basis does in fact cover the same lattice as the original and that the first row of the reduced basis is some approximation of the shortest vector in the lattice. Unfortunately both of those tests are somewhat outside the scope of this project. The number of points reachable in a lattice is infinite and to rigorously demonstrate that we can still reach the whole set would be a project of similar size to this one. 



## Project Details

### Matrix class

This is a very stripped-down matrix class with only the functions that are used in the Gram-Schmidt and LLL algorithms. It's foundation is a 2d matrix using `std::vector<std::vector<double>>`. It supports element access, row access, swapping two rows in the same matrix and 'row i - scalar * row j'. The last is an operation that happens multiple times in the algorithm. I considered adding other operations such as full matrix multiplication, but this project doesn't need it. 

I initially made the dot product of two vectors a part of this class, but it ended up being much cleaner to move that operation out of the matrix class. 

### `gs(B, b_star, mu)`

This uses the Gram-Schmidt algorithm to compute the orthogalization of `B`. It fills `b_star` with the orthogonal vectors and `mu` with the projection coefficients. Since `mu[i][j]` is a projection coefficient of `B[i]` onto `b_star[j]` me is lower triangular. The vectors in `b_star` are also not normalized, unlike in some other applications of Gram-Schmidt as the length of those vectors is important for LLL. 

### `lll(B)`

The motivating algorithm of the project. This modfies `B` in place to produce a reduced basis. Iteratively size-reduces the vectors of B, swapping rows and backtracking when the Lovász condition is not met. 

Possible future improvements to this algorithm might include tracking mu analytically rather than running Gram-Schmidt every time we change `B`. 


## Challenges

The biggest challenge in creating this was simply understanding the math well enough to implement it in C++. Since I began this project in part to  improve my understanding of these concepts this was what I expected going in. I also had my standard new-to-C++ problems involving pointers and discrepancies with header files and the like, but I've experienced these problems enough now to recognize them for what they are when they come up. 

**Translating the math paper to code**
I used the paper by Kalbach and Chinburg linked below both to help me understand the concepts and to give me the structure for the algorithm. The paper has some notational differences to my math classes and mapping things like thier notation for rounding and dot products took some time. I also initially had a couple of small bugs due to failing to account for thier use of 1-indexing. Even the version of Gram-Schmidt used is different from the one I had recently learned, although understanding why the orthogalized vectors needed to be left un-normalized was very helpful for grasping the bigger picture.

**Validation**
Validation turned out to be both much easier and much harder than I expected. Proper validation that this algorithm outputs a basis that describes the same lattice as the original turned out to be so difficult that I quickly decided that it was outside the scope of this project. The next best thing turned out to be simply eyeballing the outputs which was straightforward to implement and rigorous enough to help me catch at least one bug. 

Initial testing produced a 3x3 matrix that looked perfect, but the 6x6 matrices would occasionally have μ values > 0.5 which should not be possible. I added some print statements to the main loop of the lll function and realized that I wasn't updating the mu values after swapping rows, only before moving on to a new row. So the algorithm was doing size reductions using stale data and often the mu values for `B[0]` or `B[1]` would end up out of range. An additional `gs(B, b_star, mu)` call fixed the problem. 


## Reference

Kalbach, A. & Chinburg, T. "LLL Algorithm for Lattice Basis Reduction" (2024). https://arxiv.org/pdf/2410.22196 

I followed the pseudocode in Section 3 in particular.