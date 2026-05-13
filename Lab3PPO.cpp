#include <iostream>
#include <string>
using namespace std;

//===========
//Class osoba
//===========

class Osoba{
    //==============
    //zmienne classy
    //==============
    private:
    string imie;
    string nazwisko;
    string nr_index;
    //==============
    //funkcje classy
    //==============
    public:
    void setImie(string);
    string getImie();
    void setNazwisko(string);
    string getNazwisko();
    void setNr_Index(string);
    string getNr_Index();
};

//####################################################################################

//========================
//Działania funkcji classy
//========================

//====
//Imie
//====
void Osoba::setImie(string _imie){
    if(_imie.length() > 2){
        imie = _imie;
    }
}
string Osoba::getImie(){
    return imie;
}
//========
//Nazwisko
//========
void Osoba::setNazwisko(string _nazwisko){
    if(_nazwisko.length() > 1){
        nazwisko = _nazwisko;
    }
}
string Osoba::getNazwisko(){
    return nazwisko;
}
//=========
//Nr_indexu
//=========
void Osoba::setNr_Index(string _nr_index){
    if(_nr_index.length() > 1){
        nr_index = _nr_index;
    }
}
string Osoba::getNr_Index(){
    return nr_index;
}

//####################################################################################


void dodajOsobe(Osoba *tabOsob, string nrIndex, string imie, string nazwisko, int size);

void zmianaDanychOsoby_Edycja(Osoba *tabOsob, string nrIndex, string imie, string nazwisko, int size, int wybor);

void zmianaDanychOsoby_Usuwanie(Osoba *tabOsob, bool *tabObecnosci, int size, int wybor);

void ustawObecnosc(Osoba *tabOsob, bool *tabObecnosci, string nazwisko, bool obecnosc, int size);

void drukujListeObecnosci(Osoba *tabOsob, bool *tabObecnosci, int size);

//Lista osob do zmiany danych
void drukujListeOsob(Osoba *tabOsob, int size);

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
    string nrIndex;                //index
    //=============================
    string imie;                //imie
    //=============================
    string nazwisko;            //nazwisko
    //=============================
    Osoba osoba1;               //osoba pomocniczna
    Osoba tabOsob[size];        //tablica osob
    //=============================

    //====================
    //Przygotowanie tablic
    //====================

    osoba1.setImie("brak");
    osoba1.setNazwisko("brak");
    osoba1.setNr_Index("000");

    for(int i = 0; i < size; i++){
        tabObecnosci[i] = false;
        tabOsob[i] = osoba1;
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

            dodajOsobe(tabOsob, nrIndex, imie, nazwisko, size);

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
                    drukujListeOsob(tabOsob, size);
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;
                    cout << "\nPodaj imie: ";
                    cin >> imie;
                    cout << "\nPodaj nazwisko: ";               
                    cin >> nazwisko;
                    cout << "\nPodaj index: ";
                    cin >> nrIndex;
                    zmianaDanychOsoby_Edycja(tabOsob, nrIndex, imie, nazwisko, size, wybor);
                    break;
                case 2:
                    drukujListeOsob(tabOsob, size);
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;

                    zmianaDanychOsoby_Usuwanie(tabOsob, tabObecnosci, size, wybor);
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
            drukujListeOsob(tabOsob, size);
            cout << "\nPodaj nazwisko osoby: ";
            cin >> nazwisko;
            cout << "\nCzy ta osoba jest obecna? [T: 1 | N: 2]: ";
            cin >> wybor;
            if(wybor == 1){
                obecnosc = true;
                ustawObecnosc(tabOsob, tabObecnosci, nazwisko, obecnosc, size);
            }else if(wybor == 2){
                obecnosc = false;
                ustawObecnosc(tabOsob, tabObecnosci, nazwisko, obecnosc, size);
            }else{
                cout << "Error! Nieprawidlowy numer... ";
            }
            break;
        //================
        //Drukowanie listy
        //================
        case 4:
            drukujListeObecnosci(tabOsob, tabObecnosci, size);
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

void dodajOsobe(Osoba *tabOsob, string nrIndex, string imie, string nazwisko, int size){
    if(nrIndex == "0"){
        cout << "\nError! Nie mozna nadac indexu o nr 0. Powrot do menu... ";
    }
    else{
        for(int i=0; i < size; i++){
            if(tabOsob[i].getNr_Index() == "000"){
                tabOsob[i].setNr_Index(nrIndex);
                tabOsob[i].setImie(imie);
                tabOsob[i].setNazwisko(nazwisko);
                break;
            }
        }
    }
}

void zmianaDanychOsoby_Edycja(Osoba *tabOsob, string nrIndex, string imie, string nazwisko, int size, int wybor){
        if(wybor <= size && wybor > -1){
            if(tabOsob[wybor].getNr_Index() != "000"){
                tabOsob[wybor].setNr_Index(nrIndex);
                tabOsob[wybor].setImie(imie);
                tabOsob[wybor].setNazwisko(nazwisko);
            }
        }
        else{
            cout << "\nError! Poza lista... ";
        }
}

void zmianaDanychOsoby_Usuwanie(Osoba *tabOsob, bool *tabObecnosci, int size, int wybor){
    if(wybor <= size && wybor > -1){
        for(int i = wybor; i < size-1; i++){
            tabOsob[i].setNr_Index(tabOsob[i+1].getNr_Index());
            tabOsob[i].setImie(tabOsob[i+1].getImie());
            tabOsob[i].setNazwisko(tabOsob[i+1].getNazwisko());
            tabObecnosci[i] = tabObecnosci[i+1];
        }
        tabOsob[size-1].setNr_Index("000");
        tabOsob[size-1].setImie("brak");
        tabOsob[size-1].setNazwisko("brak");
        tabObecnosci[size-1] = false;
    }
    else{
        cout << "\nError! Poza lista... ";
    }
}

void ustawObecnosc(Osoba *tabOsob, bool *tabObecnosci, string nazwisko, bool obecnosc, int size){
    for(int i = 0; i < size; i++){
        if(tabOsob[i].getNazwisko() == nazwisko){
            tabObecnosci[i] = obecnosc;
        } 
    }
}

void drukujListeOsob(Osoba *tabOsob, int size){
    cout << "\n###| Lista Osob |###";
        for(int i = 0; i < size; i++){
        if(tabOsob[i].getNr_Index() != "000"){
            cout << "\n" << i << ": " << tabOsob[i].getNr_Index() << " " << tabOsob[i].getImie() << " " << tabOsob[i].getNazwisko();
        } 
    }
}

void drukujListeObecnosci(Osoba *tabOsob, bool *tabObecnosci, int size){
    cout << "\n###| Lista |###";
    for(int i = 0; i < size; i++){
        if(tabOsob[i].getNazwisko() != "brak"){
            cout << "\n" << i+1 << ": " << tabOsob[i].getImie() << " " << tabOsob[i].getNazwisko() << " - ";
            if(tabObecnosci[i]){
                cout << "Obecny\\Obecna";
            }
            else{
                cout << "Nieobecny\\Nieobecna";
            }
        } 
    }
}