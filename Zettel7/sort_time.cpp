#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

// pass-by-reference, weil v verändert werden soll
int insertion_sort(vector<double> & v){
  int ret=0;
  for(int k=1; k<v.size(); ++k){
  double current = v[k]; // Element, das jetzt einsortiert wird
  int j = k; // Anfangsposition der Lücke
  while(j > 0){
    ret++;
    if(current < v[j-1]){
      v[j] = v[j-1]; // Lücke eine Position nach links
    }
    else
      break; // Lücke jetzt an richtiger Position
    --j;
    }
    v[j] = current; // Element in die Lücke einfügen
  }
  return ret;
}

double insertion_sort_best_time(int n){
  // fülle Array der Größe n mit zufällig angeordneten Daten
  vector<double> v(n);
  for(int k=0; k<n; ++k){
    v[k] = k;
  }

  // bestimme Anfangs- und Endzeit für das Sortieren
  auto start = chrono::high_resolution_clock::now();
  insertion_sort(v);
  auto stop = chrono::high_resolution_clock::now();
  // berechne die Zeitdauer (in Sekunden) und gib sie zurück
  chrono::duration<double> diff = stop - start;
  return diff.count();
}

double insertion_sort_worst_time(int n){
  // fülle Array der Größe n mit zufällig angeordneten Daten
  vector<double> v(n);
  for(int k=0; k<n; ++k){
    v[k] = n-k;
  }

  // bestimme Anfangs- und Endzeit für das Sortieren
  auto start = chrono::high_resolution_clock::now();
  insertion_sort(v);
  auto stop = chrono::high_resolution_clock::now();
  // berechne die Zeitdauer (in Sekunden) und gib sie zurück
  chrono::duration<double> diff = stop - start;
  return diff.count();
}

double insertion_sort_typical_time(int n){
  // fülle Array der Größe n mit zufällig angeordneten Daten
  vector<double> v(n);
  for(int k=0; k<n; ++k){
    v[k] = k;
  }
  random_shuffle(v.begin(), v.end());

  // bestimme Anfangs- und Endzeit für das Sortieren
  auto start = chrono::high_resolution_clock::now();
  insertion_sort(v);
  auto stop = chrono::high_resolution_clock::now();
  // berechne die Zeitdauer (in Sekunden) und gib sie zurück
  chrono::duration<double> diff = stop - start;
  return diff.count();
}

double std_sort_time(int n){
  // fülle Array der Größe n mit zufällig angeordneten Daten
  vector<double> v(n);
  for(int k=0; k<n; ++k){
    v[k] = k;
  }
  random_shuffle(v.begin(), v.end());

  // bestimme Anfangs- und Endzeit für das Sortieren
  auto start = chrono::high_resolution_clock::now();
  sort(v.begin(), v.end());
  auto stop = chrono::high_resolution_clock::now();
  // berechne die Zeitdauer (in Sekunden) und gib sie zurück
  chrono::duration<double> diff = stop - start;
  return diff.count();
}


void printtimes_best(int n){
  cout << "---------------------------" << endl;
  cout << "best time, n= " << n << ":" << endl;
  cout << min(min(insertion_sort_best_time(n),insertion_sort_best_time(n)),insertion_sort_best_time(n)) << endl;
}
void printtimes_typical(int n){
  cout << "---------------------------" << endl;
  cout << "typical time, n= " << n << ":" << endl;
  cout << min(min(insertion_sort_typical_time(n),insertion_sort_typical_time(n)),insertion_sort_typical_time(n)) << endl;
}
void printtimes_worst(int n){
  cout << "---------------------------" << endl;
  cout << "worst time, n= " << n << ":" << endl;
  cout << min(min(insertion_sort_worst_time(n),insertion_sort_worst_time(n)),insertion_sort_worst_time(n)) << endl;
}

void printtimes_std(int n){
  cout << "---------------------------" << endl;
  cout << "std time, n= " << n << ":" << endl;
  cout << min(min(std_sort_time(n),std_sort_time(n)),std_sort_time(n)) << endl;  
}

int main(){
  /*
  Compiler Optimierung
  printtimes_best(10000000);
  printtimes_best(25000000);
  printtimes_best(50000000);
  printtimes_best(75000000);
  printtimes_best(100000000);

  printtimes_typical(5000);
  printtimes_typical(10000);
  printtimes_typical(15000);
  printtimes_typical(20000);
  printtimes_typical(25000);
  
  printtimes_worst(5000);
  printtimes_worst(10000);
  printtimes_worst(15000);
  printtimes_worst(20000);
  printtimes_worst(25000);

  printtimes_std(500000);
  printtimes_std(1000000);
  printtimes_std(1500000);
  printtimes_std(2000000);
  printtimes_std(2500000);
  */
  printtimes_best(50000000);
  printtimes_best(100000000);
  printtimes_best(250000000);
  printtimes_best(500000000);
  printtimes_best(750000000);

  printtimes_typical(20000);
  printtimes_typical(40000);
  printtimes_typical(60000);
  printtimes_typical(80000);
  printtimes_typical(100000);
  
  printtimes_worst(20000);
  printtimes_worst(40000);
  printtimes_worst(60000);
  printtimes_worst(80000);
  printtimes_worst(100000);

  printtimes_std(500000);
  printtimes_std(1000000);
  printtimes_std(1500000);
  printtimes_std(2000000);
  printtimes_std(2500000);

  return 0;
}