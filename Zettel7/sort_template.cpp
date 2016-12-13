#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// a) function checking if given container is sorted (arbitrary type and sort-functor)
template <typename ElementType, typename LessThanFunctor>
bool check_sorted(vector<ElementType> const & v, LessThanFunctor less_than){
	bool is_sorted = true; // is turned false if two neighboring elements are unsorted
	if (v.size() == 0 || v.size() == 1){
		is_sorted = true; // containers with 0 or 1 elements are sorted by definition
	}
	else {
		for (int k = 0; k < v.size() - 1; k++){
			if (!less_than(v[k], v[k+1])){ // if two neighbors are not sorted
				is_sorted = false;
				break;
			}
		}
	}
	return is_sorted;
}

// b) Function of a) using forward iterators
template <typename Iterator, typename LessThanFunctor>
bool check_sorted(Iterator begin, Iterator end, LessThanFunctor less_than){
	bool is_sorted = true; // is turned false if two neighboring elements are unsorted
	if (begin == end){
		is_sorted = true; // empty container is sorted by definition
	}
	else {
		Iterator next = begin;
		next++; // next points to element succeeding begin
		for (; next != end; begin++, next++){
			if (!less_than(*begin, *next)){
				is_sorted = false;
				break;
			}
		}
	}
	return is_sorted;
}

// c) Implementation of "Insertion sort" as in Lecture

template <typename ElementType, typename LessThanFunctor>
void insertion_sort(vector<ElementType> & v, LessThanFunctor less_than){
	for (int k = 1; k<v.size(); k++){
		ElementType current = v[k]; // Element to be sorted
		int j = k; // position of gap
		while (j>0){
			if (less_than(current, v[j-1])){ // if current element is not yet in the right gap
				v[j] = v[j-1]; // copy precedent element into v[j]
			}
			else {
				break;
			}
			j--;
		}
		v[j] = current; // insert current element into found gap
	}
}

// d) Implementation of "Insertion sort" using bidirectional iterators

template <typename Iterator, typename LessThanFunctor>
void insertion_sort(Iterator begin, Iterator end, LessThanFunctor less_than){
	Iterator iter = begin; // Initialization of a moving iterator
	iter++;
	for (; iter != end; iter++){
		auto current = *iter; //Element to be sorted
		Iterator gap = iter;  // Iterator pointing to position of gap
		while(gap != begin){
			Iterator next_to_gap = gap; // Iterator pointing to position
			next_to_gap--;				// precendent to gap
			if (less_than(current, *next_to_gap)){ // if current element is not at ccrect position
				*gap = *next_to_gap;	// copy element next to gap into gap
			}
			else {
				break;
			}
			gap--;
		}
		*gap = current; // copy current element into cell that gap is pointing at
	}
}	

int main() {
	//ad a) sort and shuffle 10 times to check if "check_sorted" works
	vector<double> v = {1.0,-2,-2,5.4,45,-2.9,4,6.23};
	for (int k = 0; k < 10; k++){
		sort(v.begin(),v.end(),[] (double a, double b){ // sort descendingly
			return (a > b || a == b);
		});
		assert(check_sorted(v,[] (double a, double b){ // check if sorted descendingly
			return (a > b || a == b);
		}));
		random_shuffle(v.begin(),v.end());			// shuffle and check again
		assert(!check_sorted(v,[] (double a, double b){
			return (a > b || a == b);
		}));
	}

	// ad b) same checks as in a)
	vector<double> w = {1.0,-2,-2,5.4,45,-2.9,4,6.23};
	for (int k = 0; k < 10; k++){
		sort(w.begin(),w.end(),[] (double a, double b){ // sort descendingly
			return (a > b || a == b);
		});
		assert(check_sorted(w.begin(), w.end(),[] (double a, double b){
			return (a > b || a == b);
		}));
		random_shuffle(w.begin(),w.end());
		assert(!check_sorted(w.begin(), w.end(),[] (double a, double b){
			return (a > b || a == b);
		}));
	}

	// ad c) same checks but with insertion_sort instead of sort
	vector<double> x = {1.0,-2,-2,5.4,45,-2.9,4,6.23};
	for (int k = 0; k < 10; k++){
		insertion_sort(x, [] (double a, double b){
			return (a > b || a == b);
		});
		assert(check_sorted(x,[] (double a, double b){
			return (a > b || a == b);
		}));
		random_shuffle(x.begin(),x.end());
		assert(!check_sorted(x,[] (double a, double b){
			return (a > b || a == b);
		}));
	}

	// ad d) same checks but with insertion_sort (iterator version) instead of sort
	vector<double> y = {1.0,-2,-2,5.4,45,-2.9,4,6.23};
	for (int k = 0; k < 10; k++){
		insertion_sort(y.begin(), y.end(), [] (double a, double b){
			return (a > b || a == b);
		});
		assert(check_sorted(y.begin(),y.end(),[] (double a, double b){
			return (a > b || a == b);
		}));
		random_shuffle(y.begin(),y.end());
		assert(!check_sorted(y.begin(), y.end(),[] (double a, double b){
			return (a > b || a == b);
		}));
	}


	return 0;
}


// a)

