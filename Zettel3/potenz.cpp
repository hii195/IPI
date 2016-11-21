#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

//calculating sqare of a number
double sq(double x){
  return x*x;
}

//recursive method to calculate powers of x
double power(double x, int n){
  assert(n>0);
  double ans;

  (n==1) ?
    ans = x :
    ((n%2 == 0) ?
      /*
        if the result for n beeing equal would be calculated 
        as power(x,n/2)*power(x,n/2), the power function would 
        be executed twice, this is exactly what we are trying to avoid
        to reduce the running time of the calculation, by only calculating
        it once and using the result instead of the function itself
        to calculate the square.
      */
      ans = sq(power(x,n/2)):
      ans = x*power(x,n-1));
    return ans;
}

/*
  function that prints the relevant parameters to compare 
  the two methods of calculating powers of x
  The comparison between our own function and std::pow was done by 
  printing the results instead of using the assert() function, because
  of the differences described below. This would crash the program for 
  certain inut values.
*/
void testing(double x, int n, int i){
  cout << "test no." << to_string(i) << ":" << endl;
  cout << "to calculate: " << to_string(x) << "^" << to_string(n) << endl;
  cout << "result of own function: " << to_string(power(x,n)) << endl;
  cout << "result of std::pow():   " << to_string(std::pow(x,n)) << endl;
  cout << "difference:             " << to_string(power(x,n)-std::pow(x,n)) << endl;
  cout << endl;
}

int main(){

  testing(2,2,1);
  testing(10,10,4);
  testing(3.141592,10,2);
  testing(42,13,5);
  testing(42,42,6);
  testing(314,100,7);
  testing(2.71828182846,42,8);
  testing(3.141592,42,3);
  /*
    interestingly the results for big powers of big or non integer 
    numbers are NOT equal. This is most likely due to the fact, that 
    the std::pow() function works with floats instead of doubles
  */  
  return 0;
}