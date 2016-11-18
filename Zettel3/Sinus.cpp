//Windows Headerdateien
#include <iostream>
#include <cmath>

//Konstantendefinition
#define PI 3.14159265359

//Zu a) der Winkel bis zu der die Abweichung genügen klein ist betträgt 4 Grad
//Der Konstante x_0 wird der Wert 4 zugeornet
#define x_0 4

//Funktionsdeklaration
double taylor_sin(double x);
double pump_sin(double sin_third);
double my_sin(double x);
double DegToRad(double angle);
double reduceRad(double x);

//Programmeinstiegspunkt
int main()
{
	//Hier wird nichts ausgeführt
	//Berechnete Werte siehe unten
	return 0;
}

//Funktionsdefinition
//Winkel wir vom Grad ins Bogenmaß umgerechnet
double DegToRad(double angle)
{
	return angle / 180 * 2 * PI;
}

//Berechnung des Sinus durch Taylornäherung erster Ordnung
double taylor_sin(double x)
{
	return x - x*x*x / 6;
}

//Bestimmung von sin(x) als Funktion von sin(x/3)
double pump_sin(double sin_third)
{
	return (3 - 4 * sin_third*sin_third)*sin_third;
}

//Rekursive bestimmung von sin(x) durch pump_sin mit berechnung des Rekursionsanfangs durch taylor_sin
double my_sin(double x)
{
	//Reduzierung von x ins intervall [-pi,pi]
	x = reduceRad(x); //d)
	double value;
	//Abfrage ob x bereits genügend klein
	x <= DegToRad(x_0) && x >= -1 * DegToRad(x_0) ?
		//Rekursionsanfang
		value = taylor_sin(x) :
		//Rekursionsschritt
		value = pump_sin(my_sin(x / 3));

	return value;
}


//Berechnung von x mod 2*pi, sodass Ergebniss in [-Pi,Pi] 
double reduceRad(double x)
{
	double value;
	x > PI ?
		//Rekursionsschritt A
		value = reduceRad(x - 2 * PI) : 
		x <  -1 * PI ?
			//Rekursionschritt B
			value = reduceRad(x + 2 * PI) :
			//Rekursionsanfang
			value = x;
	return value;
}

 /*Tabelle a) |sin(x) - taylor_sin(x)|
 Format:
 Winkel[°] - Differenz |sin(x) - taylor_sin(x)|
 5 - 1.3E-6
 10 - 4.3E-5
 20 - 0.0013
 45 - 0.075
 90 - 2.0
 135 - 11.7
 180 - 35.1
 225 - 73.9
 270 - 130.1
 315 - 209.6

 Tabelle d) |sin(x) - taylor_sin(x)|
 Format:
 Winkel[°] - Differenz |sin(x) - my_sin(x)|
 5 - 1.6E-8
 10 - 5.0E-7
 20 - 1.6E-7
 45 - 1.13E-14
 90 - 4.8E-6
 135 - 1.1E-14
 180 - 4.1E-13
 225 - 1.1E-14
 270 - 4.8E-6
 315 - 1.13E-14
 */