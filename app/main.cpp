#include <iostream>
#include <iomanip>
#include "../code/lll.h"
#include "../code/matrix.h"

using namespace std;


void print_basis_and_mu(string title, Matrix& B){
    // obtain the intial mu for demo
    Matrix b_star(B.rows(), B.cols());
    Matrix mu(B.rows(), B.rows());
    gs(B, b_star, mu);
      cout<<"\n"<< title<<endl;
    cout<< "----------------------------------"<<endl;
  
    // print everything off
    cout<< "Basis: "<<endl;
    B.print();

    cout<< "\nmu"<<endl;
    mu.print(); 

    cout<< "\nSquared lengths of b* vectors:"<<endl;
    for(int i = 0; i< b_star.rows(); i++){
        cout<<dot(b_star[i], b_star[i])<<endl;
    }
    cout<< "----------------------------------"<<endl;
}

int main(){
    cout<< fixed<< setprecision(2);
    cout<<"=================================="<<endl;
    cout<<" LLL Latice Basis Reduction Demo\n" <<endl;

    Matrix three = {{5, 3, 9},
                    {2, -1, 8},
                    {4, 3, 7}};
    // before and after reduction
    cout<< "Example with 3x3 basis"<< endl;
    print_basis_and_mu("Before", three);
    lll(three);
    print_basis_and_mu("After", three);

    // larger example so we can see what's going on mreo clearly.
    cout<<"=================================="<<endl;
    cout<<"Example with 6x6 basis"<< endl;

    // matrices have to linearly independent!
    Matrix six = {  {2, -9, 9, 4, 9, 1},
                    {7, 7, 7, 7, 6, 7},
                    {5, 5, 4, 5, 5, 5},
                    {1, 7, 1, 1, 1, 8},
                    {1, 2, 3, 4, 5, 6},
                    {7, 8, 9, 10, 11, 12}};
    print_basis_and_mu("Before", six);
    lll(six);
    print_basis_and_mu("After", six);
    return 0;
}
