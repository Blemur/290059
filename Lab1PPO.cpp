#include <iostream>
#include <string>
using namespace std;


void DodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize);
void UstawObecnosc(string *tabNazwisko, bool *tabObecnosci, string nazwisko, bool obecnosc);
void drukujListe(string *tabNazwisko, bool *tabObecnosci);


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
        cout << "\n### 2. Ustaw Obecnosc   ###";
        cout << "\n### 3. Drukuj liste     ###";
        cout << "\n### 4. Zakoncz Program  ###";
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
            cout << "\n### Wybrano Dodaj Osobe ###";
            cout << "\nPodaj imie: ";
            cin >> imie;
            cout << "\nPodaj nazwisko: ";               
            cin >> nazwisko;
            cout << "\nPodaj index";
            cin >> nrIndex;

            DodajOsobe(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size);

            break;
        //====================
        //Ustawianie obecnosci
        //====================
        case 2:
            cout << "\n### Wybrano Dodaj Osobe ###";
            cout << "\nPodaj imie: ";
            cin >> imie;
            cout << "\nPodaj nazwisko: ";               
            cin >> nazwisko;
            cout << "\nPodaj index: ";
            cin >> nrIndex;
            break;
        //================
        //Drukowanie listy
        //================
        case 3:
            break;
        //===================
        //Zamkniecie programu
        //===================
        case 4:
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

void DodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize){
    for(int i=0; i < tabSize; i++){
        if(tabNrIndex[i] == 0){
            tabNrIndex[i] = nrIndex;
            tabImie[i] = imie;
            tabNazwisko[i] = nazwisko;
        }
    }
}