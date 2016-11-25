#include <iostream>
#include <cmath>
using namespace std;

//function that tests whether the input is a square number
bool is_square(int n){
  if ( n%4 != 0 && n%4 != 1){
    return false;
  }
  else {
    double root = sqrt(n);
    bool ret = root == floor(root); 
    return ret;
  }
}

/*
function, that goes through all the possible 
combinations of numbers between 1 and the input value
and prints the combination of numbers if they are a 
pythagorean triplet
*/
void pythagorean_triple(int bmax){
  for (int b=1; b<=bmax; b++){
    for (int a=b; a<=bmax; a++){
      if (is_square(a*a+b*b)){
        cout << b << "  " << a << "  " << sqrt(a*a+b*b) << endl;
      }
    }
  }
}

int main(){
  pythagorean_triple(400);
  return 0;
}