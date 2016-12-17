#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Berechnung von s2n nach gegebener Formel
float s2n(float sn){
  return sqrt(2.0f-sqrt(4.0f-sn*sn));
}

//n-Fache Hintereinanderausführung von s2n()
float multiple_s2n(float sn, int n){
  float ret=sn;
  for (int i=0; i<n; i++){
    ret = s2n(ret);
  }
  return ret;
}

//Berechnung von s2n nach gegebener Formel
float t2n(float tn){
  return 2.0f/tn*(sqrt(4.0f+tn*tn)-2.0f);
}

//n-Fache Hintereinanderausführung von t2n()
float multiple_t2n(float tn, int n){
  float ret=tn;
  for (int i=0; i<n; i++){
    ret = t2n(ret);
  }
  return ret;
}

//Berechnung von s2n nach gegebener Formel
double s2n(double sn){
  return sqrt(2.0f-sqrt(4.0f-sn*sn));
}

//n-Fache Hintereinanderausführung von s2n()
double multiple_s2n(double sn, int n){
  double ret=sn;
  for (int i=0; i<n; i++){
    ret = s2n(ret);
  }
  return ret;
}

//Berechnung von s2n nach gegebener Formel
double t2n(double tn){
  return 2.0f/tn*(sqrt(4.0f+tn*tn)-2.0f);
}

//n-Fache Hintereinanderausführung von t2n()
double multiple_t2n(double tn, int n){
  double ret=tn;
  for (int i=0; i<n; i++){
    ret = t2n(ret);
  }
  return ret;
}

//-------------------
//Berechnung von s2n nach besserer Formel float
float s2n_better(float sn){
  return sn/(sqrt(2+sqrt(4-sn*sn)));
}

//n-Fache Hintereinanderausführung von s2n_better()
float multiple_s2n_better(float sn, int n){
  float ret=sn;
  for (int i=0; i<n; i++){
    ret = s2n_better(ret);
  }
  return ret;
}

//Berechnung von s2n nach besserer Formel double
double s2n_better(double sn){
  return sn/(sqrt(2+sqrt(4-sn*sn)));
}

//n-Fache Hintereinanderausführung von s2n_better()
double multiple_s2n_better(double sn, int n){
  double ret=sn;
  for (int i=0; i<n; i++){
    ret = s2n_better(ret);
  }
  return ret;
}

//Berechnung von t2n nach besserer Formel float
float t2n_better(float tn){
  return 2*tn/(2+sqrt(4+tn*tn));
}

//n-Fache Hintereinanderausführung von t2n_better()
float multiple_t2n_better(float tn, int n){
  float ret=tn;
  for (int i=0; i<n; i++){
    ret = s2n_better(ret);
  }
  return ret;
}

//Berechnung von t2n nach besserer Formel double
double t2n_better(double tn){
  return 2*tn/(2+sqrt(4+tn*tn));
}

//n-Fache Hintereinanderausführung von t2n_better()
double multiple_t2n_better(double tn, int n){
  double ret=tn;
  for (int i=0; i<n; i++){
    ret = s2n_better(ret);
  }
  return ret;
}


int main(){
  cout << std::setprecision(16);
  //Ausgabe von Interationsnummer, Ergebnis und Abweichung von Pi
  cout << "s2n(float):" << endl;
  for (int i=1; i<14; i++){
    cout << i 
         << " " 
         <<  2.0f*pow(2.0f,i)*multiple_s2n(sqrt(2.0f),i)
         << "    "
         << M_PI - 2.0f*pow(2.0f,i)*multiple_s2n(sqrt(2.0f),i)
         << endl;
    
  }
  cout << endl;
  cout << "t2n(float):" << endl;
  for (int i=1; i<14; i++){
    cout << i 
         << " " 
         << 2.0f*pow(2.0f,i)*multiple_t2n(2.0f,i)
         << "    "
         << M_PI - 2.0f*pow(2.0f,i)*multiple_t2n(2.0f,i)
         << endl;
  }
  cout << endl;
  cout << "s2n(double):" << endl;
  for (int i=1; i<16; i++){
    cout << 2.0*i 
         << " " 
         <<  2.0*pow(2.0,2.0*i)*multiple_s2n(sqrt(2.0),2.0*i)
         << "    "
         << M_PI - 2.0*pow(2.0,2.0*i)*multiple_s2n(sqrt(2.0),2.0*i)
         << endl;
  }
  cout << endl;
  cout << "t2n(double):" << endl;
  for (int i=1; i<16; i++){
    cout << 2.0*i 
         << " " 
         << 2.0*pow(2.0,2.0*i)*multiple_t2n(2.0,2.0*i)
         << "    "
         << M_PI - 2.0*pow(2.0,2.0*i)*multiple_t2n(2.0,2.0*i)  
         << endl;
  }
  cout << endl;
  cout << "s2n_better(float):" << endl;
  for (int i=1; i<14; i++){
    cout << i 
         << " " 
         <<  2.0f*pow(2.0f,i)*multiple_s2n_better(sqrt(2.0f),i)
         << "    "
         << M_PI - 2.0f*pow(2.0f,i)*multiple_s2n_better(sqrt(2.0f),i)
         << endl;
    
  }
  cout << endl;
  cout << "t2n_better(float):" << endl;
  for (int i=1; i<14; i++){
    cout << i 
         << " " 
         << pow(2.0f,i)*multiple_t2n_better(2.0f,i)
         << "    "
         << M_PI - pow(2.0f,i)*multiple_t2n_better(2.0f,i)
         << endl;
  }
  cout << endl;
  cout << "s2n_better(double):" << endl;
  for (int i=1; i<16; i++){
    cout << 2.0*i 
         << " " 
         <<  2.0*pow(2.0,2.0*i)*multiple_s2n_better(sqrt(2.0),2.0*i)
         << "    "
         << M_PI - 2.0*pow(2.0,2.0*i)*multiple_s2n_better(sqrt(2.0),2.0*i)
         << endl;
  }
  cout << endl;
  cout << "t2n_better(double):" << endl;
  for (int i=1; i<16; i++){
    cout << 2.0*i 
         << " " 
         << pow(2.0,2.0*i)*multiple_t2n_better(2.0,2.0*i)
         << "    "
         << M_PI - pow(2.0,2.0*i)*multiple_t2n_better(2.0,2.0*i)  
         << endl;
  }
  cout << endl;
  
  return 0;
}