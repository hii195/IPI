//Packages
#include <iostream>
#include <cstring>
#include <cassert>

// Declarations
int weekday2001(int day,int month,int year);
int floorDiv(int a, int b);
int abs(int a);
int sgn(int a);
int floorMod(int a, int b);
int weekday(int day, int month, int year);
int weekday1(int day, int month, int year);

	/*
	Code for the days of the week:
	0 for Monday
	1 for Tuesday
	etc.
	*/

int main (){

	// Exercise a)

	// Some sanity checks
	assert(2 == weekday2001(7,6,2006));
	assert(5 == weekday2001(24,2,2001));
	// Wrong result expected for the following 
	//(as commentary after I checked and proceeded with further
	// subtasks)
	//assert(5 == weekday2001(21,11,1964));
	//assert(4 == weekday2001(13,5,1492));
	

	// Exercise c)

	/* Durch die Implementierung von floorMod wird erreicht,
	dass der Rest immer nichtnegativ ist, auch bei negativen
	Divisionen. Die %-Funktion wird bei ungleichen Vorzeichen
	von Zähler und Nenner dagegen negativ, liegt aber in der
	selben Restklasse wie das Resultat der floorMod-Funktion,
	d.h. result_% + nenner = result_floorMod
	*/	


	// Exercise d)

	assert(4 == weekday(3,2,2012)); // Friday
	assert(2 == weekday(29,2,2012)); // Wednesday
	assert(2 == weekday(28,11,2012)); // Wednesday
	assert(5 == weekday(5,1,2013)); // Saturday
	assert(3 == weekday(7,3,2013)); // Thursday
	assert(6 == weekday(24,12,2017)); // Sunday
	assert(5 == weekday(8,1,2000)); // Saturday
	assert(0 == weekday(28,2,2000)); // Monday  
	assert(5 == weekday(11,11,2000)); // Saturday
	assert(0 == weekday(19,2,1900)); // Monday
	assert(2 == weekday(1,8,1900)); // Wednesday
	assert(0 == weekday(28,2,1600)); // Monday
	assert(2 == weekday(27,9,1600)); // Wednesday
	assert(2 == weekday(1,3,1600)); // Wednesday
	assert(5 == weekday(27,2,2100)); // Saturday
	assert(2 == weekday(31,3,2100));  // Wednesday

	/* remark : Die auf dem Zettel vorgeschlagene 
	Homepage akzeptiert keine 29. Februare trotz Schaltjahr
	*/


	// Exercise e)

	/*
	Die Schaltjahresregelung ist zyklisch in 400 Jahresschritten,
	deshalb kann von yearsPassed - 2001 ein Vielfaches von 400
	addiert werden. Wählt man 5*400=2000, so ist yearsPassed
	für Jahre nach 1583 (Einführung greg. Kalender) immer positiv
	und damit gilt truncating division = floor division. Auch
	die Folgegrößen daysPassed und weekday sind dann so beschaffen,
	dass mit den Standard-Tools das Richtige herauskommt.
	*/

	assert(4 == weekday1(3,2,2012)); // Friday
	assert(2 == weekday1(29,2,2012)); // Wednesday
	assert(2 == weekday1(28,11,2012)); // Wednesday
	assert(5 == weekday1(5,1,2013)); // Saturday
	assert(3 == weekday1(7,3,2013)); // Thursday
	assert(6 == weekday1(24,12,2017)); // Sunday
	assert(5 == weekday1(8,1,2000)); // Saturday
	assert(0 == weekday1(28,2,2000)); // Monday  
	assert(5 == weekday1(11,11,2000)); // Saturday
	assert(0 == weekday1(19,2,1900)); // Monday
	assert(2 == weekday1(1,8,1900)); // Wednesday
	assert(0 == weekday1(28,2,1600)); // Monday
	assert(2 == weekday1(27,9,1600)); // Wednesday
	assert(2 == weekday1(1,3,1600)); // Wednesday
	assert(5 == weekday1(27,2,2100)); // Saturday
	assert(2 == weekday1(31,3,2100));  // Wednesday





	return 0;

}







// functions of my own

//Function to determine weekday,
 // using wrong implementation using truncating division:
int weekday2001(int day, int month, int year){
	//// what day was January 1st of the given year?
	// => taking into account leap year rules
	int yearsPassed = year - 2001;
	int weekdayJanuary1 = (365*yearsPassed + 
		yearsPassed/4 - yearsPassed/100 + yearsPassed/400) % 7;

	////Determine if given year is leap year:
	//leap year if divisible by 4 but not by 100, or if divisible by 400
	bool LeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	

	//// How many days have passed since January 1st?
	int daysPassed = 0;
	(month == 1) // January?
		? daysPassed = day
		: (month == 2) // February?
			? daysPassed = day + 31
			: (month > 2 && LeapYear) // something else and leap year?
				? daysPassed = day + 60 + (153*month - 457)/5
				: daysPassed = day + 59 + (153*month - 457)/5;

	//// Calculation of weekday
		int weekday = (weekdayJanuary1 + daysPassed - 1) % 7;


	return weekday;
}

//Function to determine absolute value of integer
int abs(int a){
	int result = 0;
	(a >= 0)
		? result = a
		: result = -a;
	return result;
}

// Function to determine sign of integer
int sgn(int a){
	int result = 0;
	(a > 0)
		? result = 1
		: (a < 0)
			? result = -1
			: result = 0;
	return result;
}

// Function to round up
int floorDiv(int a, int b){
	// Find out if result is negative (use truncating
	//division if not)
	int result = 0;
	(sgn(a) == sgn(b))
		? result = a/b
		: result = (-abs(a) - abs(b))/abs(b); //subtract 1 from fraction 
											  //and round up
	return result;
}

// Function to calculate the remainder taking into account floorDiv
int floorMod(int a, int b){
	int result = a - b*floorDiv(a,b);
	return result;
}


// Function to determine weekday correctly
int weekday(int day, int month, int year){
	//// what day was January 1st of the given year?
	// => taking into account leap year rules
	int yearsPassed = year - 2001;
	int weekdayJanuary1 = floorMod((365*yearsPassed + 
		floorDiv(yearsPassed,4) - floorDiv(yearsPassed,100) 
		+ floorDiv(yearsPassed,400)),7);

	////Determine if given year is leap year:
	//leap year if divisible by 4 but not by 100, or if divisible by 400
	bool LeapYear = ((floorMod(year,4) == 0) 
					&& (floorMod(year,100) != 0)) 
					|| (floorMod(year,400) == 0);


	//// How many days have passed since January 1st?
	int daysPassed = 0;
	(month == 1) // January?
		? daysPassed = day
		: (month == 2) // February?
			? daysPassed = day + 31
			: (month > 2 && LeapYear) // something else and leap year?
				? daysPassed = day + 60 + floorDiv((153*month - 457),5)
				: daysPassed = day + 59 + floorDiv((153*month - 457),5);

	//// Calculation of weekday
		int weekday = floorMod((weekdayJanuary1 + daysPassed - 1),7);


	return weekday;
}

// Function for weekday without floorDiv and floorMod for subtask e)
int weekday1(int day, int month, int year){
	//// what day was January 1st of the given year?
	// => taking into account leap year rules
	int yearsPassed = year - 1;
	int weekdayJanuary1 = (365*yearsPassed + 
		yearsPassed/4 - yearsPassed/100 + yearsPassed/400) % 7;

	////Determine if given year is leap year:
	//leap year if divisible by 4 but not by 100, or if divisible by 400
	bool LeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	

	//// How many days have passed since January 1st?
	int daysPassed = 0;
	(month == 1) // January?
		? daysPassed = day
		: (month == 2) // February?
			? daysPassed = day + 31
			: (month > 2 && LeapYear) // something else and leap year?
				? daysPassed = day + 60 + (153*month - 457)/5
				: daysPassed = day + 59 + (153*month - 457)/5;

	//// Calculation of weekday
		int weekday = (weekdayJanuary1 + daysPassed - 1) % 7;


	return weekday;
}
