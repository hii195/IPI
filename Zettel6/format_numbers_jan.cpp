#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "format_numbers.hpp"

using namespace std;

int roundn(double n){
  if (n-floor(n)<0.5)
    return floor(n);
  return floor(n+1);
}

vector<int> vec_to_int(vector<double> v){
  transform(v.begin(), v.end(), v.begin(), roundn);
}

int main(){
  vector<double> v1={1.1 , 2.6, 6.5};
  vector<int> v2;
  v2=vec_to_int(v1);
  //cout << v2.front() << endl;
  return 0;
}
