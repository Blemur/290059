#include <iostream>
#include <string>
using namespace std;


void dodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize);

void zmianaDanychOsoby(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize);

void ustawObecnosc(string *tabNazwisko, bool *tabObecnosci, string nazwisko, bool obecnosc);

void drukujListe(string *tabImie, string *tabNazwisko, bool *tabObecnosci, int tabSize);


int main(){
    //================
    //Zmienne programu
    //================

    //=============================
    bool CzyProgramOdpalony = true;
    const int size = 10;
    //=============================
    bool tabObecnosc[size];
    bool obecnosc;
    //=============================
    int nrIndex;    
    int tabNrIndex[size];
    //=============================
    string imie;
    string tabImie[size];
    //=============================
    string nazwisko;
    string tabNazwisko[size];
    //=============================

    //====================
    //Przygotowanie tablic
    //====================

    for(int i = 0; i < size; i++){
        tabObecnosc[i] = false;
        tabNrIndex[i] = 0;
        tabImie[i] = "brak";
        tabNazwisko[i] = "brak";
    }

    //==============
    //Pętla programu
    //==============

    do{

        //==================
        //Interfejs programu
        //==================

        cout << "\n###########################";
        cout << "\n### 1. Dodaj Osobe      ###";
        cout << "\n### 2. Zmien Dane Osoby ###";
        cout << "\n### 3. Ustaw Obecnosc   ###";
        cout << "\n### 4. Drukuj liste     ###";
        cout << "\n### 5. Zakoncz Program  ###";
        cout << "\n#############################";
        cout << "\nPodaj numer:";
        int wybor = 0;
        cin >> wybor;
        cout << "\n";

        //===============================
        //wybieranie mozliwosciu programu
        //===============================

        switch (wybor)
        {
        //===============
        //Dodawanie osoby
        //===============        
        case 1:
            cout << "\n###| Wybrano Dodaj Osobe |###";
            cout << "\nPodaj imie: ";
            cin >> imie;
            cout << "\nPodaj nazwisko: ";               
            cin >> nazwisko;
            cout << "\nPodaj index";
            cin >> nrIndex;

            dodajOsobe(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size);

            break;
        //===============
        //ZmianaDanychOsoby
        //===============        
        case 2:
            cout << "\n###| Zmiene Danych Osoby |###";
            cout << "\nPodaj index osoby: ";
            cin >> imie;
            cout << "\nPodaj nazwisko: ";               
            cin >> nazwisko;
            cout << "\nPodaj index";
            cin >> nrIndex;

            dodajOsobe(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size);

            break;
        //====================
        //Ustawianie obecnosci
        //====================
        case 3:
            break;
        //================
        //Drukowanie listy
        //================
        case 4:
            drukujListe(tabImie, tabNazwisko, tabObecnosc, size);
            break;
        //===================
        //Zamkniecie programu
        //===================
        case 5:
            CzyProgramOdpalony = false;
            break;

        default:
            break;
        }
    }
    while(CzyProgramOdpalony);

    //###########################################

    return 0; //koniec main()
}

//###########################################

void dodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize){
    for(int i=0; i < tabSize; i++){
        if(tabNrIndex[i] == 0){
            tabNrIndex[i] = nrIndex;
            tabImie[i] = imie;
            tabNazwisko[i] = nazwisko;
            break;
        }
    }
}

void drukujListe(string *tabImie, string *tabNazwisko, bool *tabObecnosci, int tabSize){
    cout << "\n###| Lista |###";
    for(int i = 0; i < tabSize; i++){
        if(tabNazwisko[i] != "brak"){
            cout << "\n" << i+1 << ": " << tabImie[i] << " " << tabNazwisko[i] << " - ";
            if(tabObecnosci[i]){
                cout << "Jest";
            }else{
                cout << "Brak";
            }
        } 
    }

}