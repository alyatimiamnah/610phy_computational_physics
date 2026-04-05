#include <vector>
#include <iostream>

using namespace std;
void Q2() {

  // (a) Define a vector with the following momentum values:
  vector<double> numbers;

  // 1.5, -0.3, 0.8, 2.2, 0.0
  // store them using push_back()
       numbers.push_back(1.5);
       numbers.push_back(-0.3);
       numbers.push_back(0.8);
       numbers.push_back(2.2);
       numbers.push_back(0.0);


  // (b) Print all momentum values using a for loop

       for(int i=0 ;i< numbers.size(); i++){
         std::cout<<"numbers"<<numbers[i]<<std::endl;



  // (c) Using a for loop:


  // if momentum < 0, skip it using continue


if(numbers[i] < 0){
  continue;}
  // if momentum == 0, stop the loop using break
if(numbers[i] == 0)
  {break;}
  // otherwise:
 if(numbers[i]>=1.0){std::cout<<"Accepted track"<<std::endl;
 }
  //   print "Accepted track" if momentum >= 1.0
  //   print "Rejected track" if momentum < 1.0
 if(numbers[i] <1.0)
   {std::cout<<"Rejected track"<<std::endl;}

}
