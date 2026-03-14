#include <iostream>
#include <string>
using namespace std;


void dodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize);

void zmianaDanychOsoby(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize, int wybor);

void ustawObecnosc(string *tabNazwisko, bool *tabObecnosci, string nazwisko, bool obecnosc);

void drukujListeObecnosci(string *tabImie, string *tabNazwisko, bool *tabObecnosci, int tabSize);

//Lista osob do zmiany danych
void drukujListeOsob(int *tabNrIndex, string *tabImie, string *tabNazwisko, int tabSize);


int main(){
    //================
    //Zmienne programu
    //================

    //=============================
    bool CzyProgramOdpalony = true; //dzialanie programu
    const int size = 10;          //wielkosc tablic
    int wybor = 0;              //pomocnicza zmienna do wyborow
    //=============================
    bool tabObecnosc[size];     //obecnosc
    bool obecnosc;
    //=============================
    int nrIndex;                //index
    int tabNrIndex[size];
    //=============================
    string imie;                //imie
    string tabImie[size];
    //=============================
    string nazwisko;            //nazwisko
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
        cout << "\nPodaj numer: ";
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
            cout << "\nPodaj index: ";
            cin >> nrIndex;

            dodajOsobe(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size);

            break;
        //===============
        //ZmianaDanychOsoby
        //===============        
        case 2:
            cout << "\n###| Zmiana Danych Osoby |###";
            drukujListeOsob(tabNrIndex, tabImie, tabNazwisko, size);
            cout << "\nPodaj nr z listy: ";
            cin >> wybor;
            cout << "\nPodaj imie: ";
            cin >> imie;
            cout << "\nPodaj nazwisko: ";               
            cin >> nazwisko;
            cout << "\nPodaj index: ";
            cin >> nrIndex;
            zmianaDanychOsoby(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size, wybor);
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
            drukujListeObecnosci(tabImie, tabNazwisko, tabObecnosc, size);
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

void zmianaDanychOsoby(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize, int wybor){
        if(wybor <= tabSize && wybor > -1){
            tabNrIndex[wybor] = nrIndex;
            tabImie[wybor] = imie;
            tabNazwisko[wybor] = nazwisko;
        }
}

void drukujListeOsob(int *tabNrIndex, string *tabImie, string *tabNazwisko, int tabSize){
    cout << "\n###| Lista Osob |###";
        for(int i = 0; i < tabSize; i++){
        if(tabNrIndex[i] != 0){
            cout << "\n" << i << ": " << tabNrIndex[i] << " " << tabImie[i] << " " << tabNazwisko[i];
        } 
    }
}

void drukujListeObecnosci(string *tabImie, string *tabNazwisko, bool *tabObecnosci, int tabSize){
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