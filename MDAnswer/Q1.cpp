nah@ALFA-Computers:/mnt/c/Users/ألفا للحاسبات/Computational_Physics_Course/ComputationalCourse/Tutorial/C++$ cat Q1.cpp
    #include <iostream>
#include <cmath>
using namespace std;

void Q1() {

  // (a) Define the following variables:

  // charge = -1
  int charge = -1;
  // mass = 0.000511
  double m = 0.000511;
  // momentum = 2.0
  double p = 2.0;


  // (b) Print the particle information

  std::cout<<"charge "<<charge<<std::endl;
  std::cout<<"mass "<< m <<std::endl;
  std::cout<<"momentum"<< p <<std::endl;

  // (c) Calculate the energy:
  // E = sqrt(p^2 + m^2)
  double E;
  E =sqrt( p*p + m*m );


  // (d) Print the energy
    std::cout<<" energy "<< E <<std::endl;


  // (e) Using if / else:
  // print "Charged particle" if charge != 0
  // otherwise print "Neutral particle"

    if(charge != 0){
      std::cout<<"Chargeed particle " <<std::endl;
    }
    else    {std::cout<<"otherwise"<<std::endl;
    }

}
