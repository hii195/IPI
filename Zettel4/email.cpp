#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Declarations
bool is_email(string s);
bool is_invalid(char c);


int main(){
	
	// Sanity check:
	//valid addresses
	assert(is_email("a@b.e"));
	assert(is_email("0@..e"));
	assert(is_email(".@b.e"));
	assert(is_email("a@b.0a"));
	assert(is_email("-@b.e"));
	assert(is_email("a@_.e"));

	//invalid addresses
	assert(!is_email("a@b:e"));
	assert(!is_email("a@b@.e"));
	assert(!is_email("ab.e"));
	assert(!is_email("a@be"));
	assert(!is_email("!@b.e"));
	assert(!is_email("a@.e"));
	assert(!is_email("a@b."));
	assert(!is_email("a@b.?"));




	return 0;
}
// Function to evaluate if given character is invalid
bool is_invalid(char c){
	bool result = false;
	int letter = c; //Get the ordinal value of character
		if (('a' <= letter) && (letter <= 'z')){}	// a-z?
		else if (('A' <= letter) && (letter <= 'Z')){}	// A-Z?
		else if (('0' <= letter) && (letter <= '9')){}	// 0-9?
		else if ((letter == '.') || (letter == '_') || (letter == '-') || 
			letter == '@'){}	// Special characters ?
		else {
			result = true;  // Do nothing except if entering this branch
		}
	return result;

}

// Function to check whether given string is valid email address

/* Note: I intentionally refused to insert return-statements in 
the middle of the code. While that slightly worsens its efficiency,
it will be harder for bugs to remain unfound!
*/

bool is_email(string s){
	bool result = true;
	int length = s.size();

	// Are there only allowed characters in string?
	bool found_invalid = false;
	for (int i = 0; i<length;i++){
		if (is_invalid(s[i])){
			found_invalid = true;
			break;
		}
	}
	if (found_invalid == true){
		result = false;
	}

	// Is there exactly one @-character?
	if (s.find('@') == string::npos){ // no such character?
		result = false;
	}
	if (s.find('@') != s.rfind('@')){ // are there at least two of them?
		result = false;  
	} 

	// Is there at least one point on the right of "@" ?
	int position_at = s.find('@');
	bool found_dot = false;
	for (int i = position_at + 1; i<length; i++){
		if (s[i] == '.'){
			found_dot = true;
			break;
		}
	}
	if (found_dot == false){
		result = false;
	}

	//Is there at least one valid character on the left of "@" ?
	if (position_at == 0){
		result = false;
	}

	//Is there at least one valid character between @ an last "." ?
	int position_last_dot = s.rfind('.');
	if (position_last_dot - position_at <= 1){
		result = false;
	}

	// Is there at least one non-"."-character on the right of the last "." ?
	if (position_last_dot == length - 1){
		result = false;
	}

	return result;
}