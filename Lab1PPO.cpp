#include <iostream>
#include <string>
using namespace std;

void dodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize);

void zmianaDanychOsoby_Edycja(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize, int wybor);

void zmianaDanychOsoby_Usuwanie(int *tabNrIndex, string *tabImie, string *tabNazwisko, int tabSize, int wybor);

void ustawObecnosc(string *tabNazwisko, bool *tabObecnosci, string nazwisko, bool obecnosc, int tabSize);

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
    bool tabObecnosci[size];     //obecnosc
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
        tabObecnosci[i] = false;
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
        cout << "\n###########################";
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
        //=================
        //ZmianaDanychOsoby
        //=================        
        case 2:
            cout << "\n###| Zmiana Danych Osoby |###";
            cout << "\n#######################################";
            cout << "\n### Wpisz 1 aby edytowac dane osoby ###";
            cout << "\n### Wpisz 2 aby usunac osobe z bazy ###";
            cout << "\n#######################################";
            cout << "\nWpisz [1|2]: ";
            cin >> wybor;
                switch (wybor)
                {
                case 1:
                    drukujListeOsob(tabNrIndex, tabImie, tabNazwisko, size);
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;
                    cout << "\nPodaj imie: ";
                    cin >> imie;
                    cout << "\nPodaj nazwisko: ";               
                    cin >> nazwisko;
                    cout << "\nPodaj index: ";
                    cin >> nrIndex;
                    zmianaDanychOsoby_Edycja(tabNrIndex, tabImie, tabNazwisko, nrIndex, imie, nazwisko, size, wybor);
                    break;
                case 2:
                    drukujListeOsob(tabNrIndex, tabImie, tabNazwisko, size);
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;

                    zmianaDanychOsoby_Usuwanie(tabNrIndex, tabImie, tabNazwisko, size, wybor);
                    break;
                default:
                    cout << "\nWpisano bledna liczbe";
                    cout << "\nPowrot do menu...";
                    break;
                }
            break;
        //====================
        //Ustawianie obecnosci
        //====================
        case 3:
            cout << "\n###| Ustawianie Obecnosci |###";
            drukujListeOsob(tabNrIndex, tabImie, tabNazwisko, size);
            cout << "\nPodaj nazwisko osoby: ";
            cin >> nazwisko;
            cout << "\nCzy ta osoba jest obecna? [T: 1 | N: 2]: ";
            cin >> wybor;
            if(wybor == 1){
                obecnosc = true;
                ustawObecnosc(tabNazwisko, tabObecnosci, nazwisko, obecnosc, size);
            }else if(wybor == 2){
                obecnosc = false;
                ustawObecnosc(tabNazwisko, tabObecnosci, nazwisko, obecnosc, size);
            }else{
                cout << "Error! Nieprawidlowy numer... ";
            }
            break;
        //================
        //Drukowanie listy
        //================
        case 4:
            drukujListeObecnosci(tabImie, tabNazwisko, tabObecnosci, size);
            break;
        //===================
        //Zamkniecie programu
        //===================
        case 5:
            CzyProgramOdpalony = false;
            break;

        default:
            cout << "\nWpisano bledna liczbe";
            cout << "\nPowrot do menu...";
            break;
        }
    }
    while(CzyProgramOdpalony);

    //###########################################

    return 0; //koniec main()
}

//###########################################

void dodajOsobe(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize){
    if(nrIndex == 0){
        cout << "\nError! Nie mozna nadac indexu o nr 0. Powrot do menu... ";
    }
    else{
        for(int i=0; i < tabSize; i++){
            if(tabNrIndex[i] == 0){
                tabNrIndex[i] = nrIndex;
                tabImie[i] = imie;
                tabNazwisko[i] = nazwisko;
                break;
            }
        }
    }
}

void zmianaDanychOsoby_Edycja(int *tabNrIndex, string *tabImie, string *tabNazwisko, int nrIndex, string imie, string nazwisko, int tabSize, int wybor){
        if(wybor <= tabSize && wybor > -1 && tabNrIndex != 0){
            tabNrIndex[wybor] = nrIndex;
            tabImie[wybor] = imie;
            tabNazwisko[wybor] = nazwisko;
        }
        else{
            cout << "\nError! Poza lista... ";
        }
}

void zmianaDanychOsoby_Usuwanie(int *tabNrIndex, string *tabImie, string *tabNazwisko, int tabSize, int wybor){
    if(wybor <= tabSize && wybor > -1){
        for(int i = wybor; i < tabSize-1; i++){
            tabNrIndex[i] = tabNrIndex[i+1];
            tabImie[i] = tabImie[i+1];
            tabNazwisko[i] = tabNazwisko[i+1];
        }
        tabNrIndex[tabSize-1] = 0;
        tabImie[tabSize-1] = "brak";
        tabNazwisko[tabSize-1] = "brak";
    }
    else{
        cout << "\nError! Poza lista... ";
    }
}

void ustawObecnosc(string *tabNazwisko, bool *tabObecnosci, string nazwisko, bool obecnosc, int tabSize){
    for(int i = 0; i < tabSize; i++){
        if(tabNazwisko[i] == nazwisko){
            tabObecnosci[i] = obecnosc;
        } 
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
                cout << "Obecny\\Obecna";
            }
            else{
                cout << "Nieobecny\\Nieobecna";
            }
        } 
    }
}