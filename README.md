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

$(δ − µ^2_{i, i-1}) * \|b*_i\|^2 \leq \|$b*_{i+1}\|^2$
for all i < n.

b* here is the aforementioned 


