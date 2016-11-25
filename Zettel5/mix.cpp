#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "text.hpp"

using namespace std;

//Declarations
vector<string> split_words(string s);
string mix(string s);
string split_and_mix(string s);


int main(){
	cout << str1 + "\n\n"
		<< split_and_mix(str1) + "\n\n"
		<< str2 + "\n\n"
		<< split_and_mix(str2) + "\n\n"
		<< str3 + "\n\n"
		<< split_and_mix(str3) + "\n\n"
		<< str4 + "\n\n"
		<< split_and_mix(str4) + "\n\n"
		<< str5 + "\n\n"
		<< split_and_mix(str5) + "\n\n";
	return 0;
} 

//Functions of my own
//a)
vector<string> split_words(string s){
	// develop current word
	string current_word = "";
	vector<string> output;
	int i = 0;
	while (i < s.length()){
		if (s[i] != ' '){
			current_word += s[i];
		}
		else {
			output.push_back(current_word);
			current_word = "";
		}

		i++;
	}
	output.push_back(current_word); // Add last word to output

	return output;
}

//b)
string mix(string s){
	//find indices of first and last letter
	bool first_letter_found = false;
	int index_first;
	int index_last;
	for (int i = 0; i<s.length(); i++){
		if (!isalpha(s[i])){			//ignore non-letters
			continue;
		}
		if (!first_letter_found){
			index_first = i;
			first_letter_found = true;
		}
		index_last = i;		//is constantly overriden -> desired result is last override
	}

	// shuffle between index_first und index_last
	random_shuffle(s.begin()+index_first+1,s.begin()+index_last-1);
	return s;
}

//c)
string split_and_mix(string s){
	vector<string> words = split_words(s);
	string output = "";
	for (int i = 0; i<words.size(); i++){
		output += mix(words[i]) + " ";		//concatinate shuffled words with space
	}
	return output;
}