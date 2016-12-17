#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>

std::wstring read_file(std::string filename)
{
    // Datei zum Lesen von wchar_t oeffnen
    std::wifstream infile(filename);

    // Daten einlesen
    std::wstringstream textstream;
    textstream << infile.rdbuf();

    // Inhalt als std::wstring zurueckgeben
    return textstream.str();
}

void write_file(std::string filename, std::wstring const & text)
{
    // Datei zum Schreiben von wchar_t oeffnen
    std::wofstream outfile(filename);

    // Text in Datei schreiben
    outfile << text;
}

struct Character
{
    wchar_t encrypted;
    wchar_t clear;
    int count;
};

int biggest_code(std::wstring const & text){
    int biggest = -1; // so that first comparison always returns true
    for (int k = 0; k < text.size(); k++){
        int current = int(text[k]);
        if (current > biggest){
            biggest = current;
        }
    }
    return biggest;
}

int main()
{
#if defined(_MSC_VER)
    // unter Windows/Visual Studio: locale fuer Deutsch definieren
    std::locale german("de-de");
#elif defined(__APPLE__)
    // unter MacOS: locale fuer Deutsch mit UTF-8 definieren
    std::locale german("de_DE.UTF-8");
#elif defined(__linux__)
    // unter Linux: locale fuer sprachunabhaengiges UTF-8 definieren
    std::locale german("C.UTF-8");
#else
    // sonst: verwende die Spracheinstellungen des Betriebssystems
    std::locale german("");
#endif

    // Konverter zwischen UTF-8 (Zeichentyp in der Datei) und
    // wchar_t (Zeichentyp im Programm) erzeugen
    std::locale codec(german, new std::codecvt_utf8<wchar_t>);

    // Konverter global setzen (er wird ab jetzt von allen
    // Ein-/Ausgabeoperationen in diesem Programm verwendet)
    std::locale::global(codec);

    // Datei einlesen
    std::wstring text = read_file("verschluesselt_utf8.txt");

    // a) biggest character code in text:
    int max = biggest_code(text);
    std::cout << max << "\n";
    
    // b) Initialization of characters vector
    std::vector<Character> characters(max+1); //character[max] is now last element
    for (int k = 0; k<characters.size(); k++){
        characters[k].count = 0;
        characters[k].encrypted = wchar_t(k);
        characters[k].clear = wchar_t(k);
    }
    
    // c) count frequency of literals in text
    for (int k = 0; k<text.size(); k++){
        wchar_t currentLetter = tolower(text[k], german); //transform to lower-case letter
        int currentIndex = int(currentLetter);
        characters[currentIndex].count++;
    }

    // d) sort characters ascendingly according to counts
    sort(characters.begin(), characters.end(), [] (Character a, Character b){
        return (a.count < b.count);
    });

    // e) match sorted characters to litteral frequency in german
    //read in german letter frequency
    std::wstring frequency_german = read_file("buchstaben_haeufigkeit_utf8.txt");
    //matching:
    int counter = 0; //number of matched literals between characters and frequency_german 
    for (auto & letter : characters){
        if (letter.count > 0 && islower(letter.encrypted, german)){ //ignore non-literaks
            letter.clear = frequency_german[counter];
            counter++;
        }
    }


    // f) sort characters back -> sort ascendingly by .encrypted
    sort(characters.begin(), characters.end(), [] (Character a, Character b){
        return int(a.encrypted) < int(b.encrypted);
    });


    // g) decrypt text
    for (int k = 0; k<text.size(); k++){
        bool is_lower_case = islower(text[k], german);
        int letterID = tolower(text[k], german);
        if (is_lower_case){
            text[k] = characters[letterID].clear;
        }
        else {
            wchar_t upper_clear = toupper(characters[letterID].clear, german);
            text[k] = upper_clear;
        }
    }



    // Ergebnis in Datei schreiben
    write_file("entschluesselt.txt", text); 
}


