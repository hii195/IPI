#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "sort_versions.hpp"
#include <algorithm>

using namespace std;

/*
function to turn version-string into a vector with the numbers 
in the respective places
*/
vector<int> split_version(string version){
  // develop current number
  string current_number = "";
  vector<int> output;
  int i = 0;
  while (i < version.length()){
    if (version[i] != '.'){
      current_number += version[i];
    }
    else {
      output.push_back(atoi(current_number.c_str()));
      current_number = "";
    }
    i++;
  }
  output.push_back(atoi(current_number.c_str())); // Add last number to output

  return output;
}


/*
function, that returns true if version v1 is smaller than version v2
*/
bool version_less(string v1, string v2){
  vector<int> vers1 = split_version(v1);
  vector<int> vers2 = split_version(v2);

  //going through the levels of the version number
  for (int i=0; i<vers1.size(); i++){
    if (vers1[i] < vers2[i])
      return true;
  }
  return false;
}



int main(){
  sort(versions.begin(), versions.end(), version_less);
  cout << "Versions: " << endl;
  for (auto it=versions.begin(); it!=versions.end(); ++it)
    cout << *it << endl;

  return 0;
}

