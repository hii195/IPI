#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/*Funktion, die ein Kartendeck mit "size" Karten erstellt.
  durch die Einführung der Variablen size kann dieses Programm 
  einfacher auf andere Situationen erweitert werden.
*/
vector<int> init_deck(int size){
  vector<int> deck;
  for (int i=0; i<size; i++){
    deck.push_back(i);
  }
  return deck;
}

/*Es wurde hier bewusst eine void Funktion und nicht 
  eine vector<int> Funktion erstellt, und stattdessen mit 
  einer Referenz gearbeitet um Laufzeit durch den Kopiervorgang
  zu sparen. Es scheint außerdem sinnvoll ein gemischtes 
  Kartendeck direkt zu überschreiben anstatt die ungemischte 
  Version noch weiter gespeichert zu halten.
*/
void shuffle(vector<int> & cards, bool out){
  vector<int> shuffled_deck;
  for (int i = 0; i < cards.size()/2; ++i) {
    if (out) {
      shuffled_deck.push_back(cards[i]);
      shuffled_deck.push_back(cards[cards.size()/2+i]);
    }
    else {      
      shuffled_deck.push_back(cards[cards.size()/2+i]);
      shuffled_deck.push_back(cards[i]);
    }
  }
  cards=shuffled_deck;
}

/*Funktion, die prüft, ob sich ein Kartendeck in der
  geordneten Anordnung befindet.
*/
bool check_deck(vector<int> cards){
  vector<int> stddeck = init_deck(cards.size());
  for (int i=0; i<cards.size(); i++){
    if (cards[i] == stddeck[i])
      continue;
    else
      return false;
    }
  return true;
}

int main(){
  //Erstellung des Kartendecks
  vector<int> deck = init_deck(52);
  assert(check_deck(deck));

  shuffle(deck, true);
  //Laufvariable, die zählt wie häufig gemischt wurde
  int n=1;
  /*Schleife, die so lange läuft, bis sich das Kartendeck durch
  Out-Shuffles wieder im Ausgangszustand befindet.*/
  while (!check_deck(deck)) {
    shuffle(deck, true);
    n++;
  }
  cout << "Needed shuffles for Out-Shuffle: " << n << endl;
  n=1;
  shuffle(deck, false);
  /*Schleife, die so lange läuft, bis sich das Kartendeck durch 
  In-Shuffles wieder im Ausgangszustand befindet.*/
  while (!check_deck(deck)) {
    shuffle(deck, false);
    n++;
  }
  cout << "Needed shuffles for In-Shuffle: " << n << endl;
}