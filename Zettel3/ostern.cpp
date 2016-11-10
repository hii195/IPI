#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string easter(int year){
  //calculating constants as in given algorithm
  int a = year%19;
  int b = year%4;
  int c = year%7;
  int k = year/100;
  int p = (8*k+13)/25;
  int q = k/4;
  int m = (15+k-p-q)%30;
  int d = (19*a+m)%30;
  int n = (4+k-q)%7;
  int e = (2*b+4*c+6*d+n)%7;
  int x = 22+d+e;
  int z;
  /*
    case differentiation for value z, that has to be 
    50 if x=57, 
    49 if x=56 and d=28 and a>10, 
    equal to x otherwise
  */
  (x==57 || (x==56 && d==28 && a>10) ) ? 
    (x==57 ? 
      z = 50 : 
      z = 49 ) : 
    z = x;
  
  string date;
  /*
    case differentiation for the output value, that has to be
    "z. Maerz" if z<32
    "(z-31). April" otherwise
  */
  ( z<32 ?
    date = to_string(z) + ". Maerz" : 
    date = to_string(z-31) + ". April");
  
  return "Ostern ist am " + date;
}


int main(){
  //testing functionality
  assert(easter(1583)=="Ostern ist am 10. April");
  assert(easter(1602)=="Ostern ist am 7. April");
  assert(easter(2016)=="Ostern ist am 27. Maerz");
  assert(easter(2718)=="Ostern ist am 7. April");
  assert(easter(2998)=="Ostern ist am 8. April");
  assert(easter(3141)=="Ostern ist am 20. April");
  assert(easter(6283)=="Ostern ist am 15. April");
  assert(easter(6626)=="Ostern ist am 2. April");
  assert(easter(8314)=="Ostern ist am 12. April");
  assert(easter(1000000)=="Ostern ist am 16. April");
  return 0;
}