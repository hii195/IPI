#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Declarations


int main (){
	// a) Read in encrypted file
	ifstream infile("encrypted_text.txt");
	string text;
	string line;
	while (infile){
		getline(infile,line);
		text += line + "\n";
	}

	// b) count frequency of letters
	map<char, int> counts;
	for (char & current : text){
		if (isalpha(current)){
			char current_lower = tolower(current); //treat upper case letters like lowers
			counts[current_lower]++;	
		}
		
	}

	
	// c) sort counts in an ascending way by switching key and value of counts
	map<int, char> sorted;
	for (auto iter = counts.begin(); iter != counts.end(); iter++){
		sorted[(*iter).second] = (*iter).first;
	}

	// frequency of english letters
	vector<char> letters = {'z', 'j', 'q', 'x', 'k', 'v', 'b', 'y', 
	'g', 'p', 'w', 'f', 'm', 'c', 'u', 'l', 'd', 'r', 'h', 's', 
	'n', 'i', 'o', 'a', 't', 'e'};

	// d) decryption table: match the k-th-most frequently found letter to letters[k]
	map<char, char> decrypt;
	int k = 0;
	for (auto iter = sorted.begin(); iter != sorted.end(); iter++){
		char current_letter = (*iter).second;
		//create entry in decrypt for lower- and upper-case letter
		decrypt[current_letter] = letters[k];
		decrypt[toupper(current_letter)] = toupper(letters[k]);
		k++;
	}

	// e) decryption of given text and creation of output file
	for (char & iter : text){
		if (isalpha(iter)){
			iter = decrypt[(iter)];
		}
	}

	ofstream outfile("decrypted_text.txt");
	outfile << text;
	

	return 0;
}