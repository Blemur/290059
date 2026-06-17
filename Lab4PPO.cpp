#include <iostream>
#include <string>
using namespace std;

//===================
//Interfejs
//===================
class IPrzedstawialny {
    public:
    virtual string przedstawSie() = 0;
};

//===========
//Class Osoba
//===========

class Osoba{
    //==============
    //zmienne classy
    //==============
    protected:
    string imie;
    string nazwisko;
    //==============
    //funkcje classy
    //==============
    public:
    void setImie(string _imie)         { if(_imie.length() > 2)    imie = _imie; }
    void setNazwisko(string _nazwisko) { if(_nazwisko.length() > 1) nazwisko = _nazwisko; }
    string getNazwisko()               { return nazwisko; }
    virtual void drukuj()              { cout << " OSOBA - imie: " << imie << " nazwisko: " << nazwisko; }
};

//=============
//Class Student
//=============

class Student : public Osoba, public IPrzedstawialny{
    //==============
    //zmienne classy
    //==============
    private:
    string nr_index;
    //==============
    //funkcje classy
    //==============
    public:
    void setNr_Index(string _nr_index) { if(_nr_index.length() > 1) nr_index = _nr_index; }
    virtual void drukuj()              { cout << "STUDENT - imie: " << imie << " nazwisko: " << nazwisko << " index: " << nr_index; }
    string przedstawSie()              { return " STUDENT - " + imie + " " + nazwisko + " index: " + nr_index; }
};

//================
//Class Pracownik
//================

class Pracownik : public Osoba{
    //==============
    //zmienne classy
    //==============
    private:
    string nr_pracownika;
    //==============
    //funkcje classy
    //==============
    public:
    void setNr_Pracownika(string _nr_pracownika) { if(_nr_pracownika.length() > 1) nr_pracownika = _nr_pracownika; }
    virtual void drukuj()                        { cout << " PRACOWNIK - imie: " << imie << " nazwisko: " << nazwisko << " nr: " << nr_pracownika; }
};

//====================
//Class ListaObecnosci
//====================

class ListaObecnosci{
    //==============
    //zmienne classy
    //==============
    private:
    Student *tabOsob[10];
    bool tabObecnosci[10];
    int licznik;
    string nazwaZajec;
    Pracownik prowadzacy;
    //==============
    //funkcje classy
    //==============
    public:
    ListaObecnosci();
    void ustawZajecia(string, string, string, string);
    void drukujNazwe();
    bool dodajOsobe(Student*);
    bool ustawObecnosc(string, int);
    void drukujListeObecnosci();
    //-------------------------
    void drukujListeOsob();
    void zmianaDanych_Edycja(int, string, string, string);
    void zmianaDanych_Usuwanie(int);
    int getLicznik();
};

//==========================
//Class InterfejsUzytkownika
//==========================

class InterfejsUzytkownika{
    //==============
    //zmienne classy
    //==============
    private:
    ListaObecnosci listy[10];
    int ileList;
    int aktualnaLista;
    Student *tabOsob;
    int iluStudentow;
    //==============
    //funkcje classy
    //==============
    public:
    InterfejsUzytkownika();
    void setTablicaOsob(Student*);
    void petla();
};

//####################################################################################

//========================
//Działania funkcji classy
//========================

//===================
//Funkcja z interfejsem
//===================
void drukuj(IPrzedstawialny* obj){
    cout << "\n" << obj->przedstawSie();
}

//==============
//ListaObecnosci
//==============
ListaObecnosci::ListaObecnosci() {
    licznik = 0;
    nazwaZajec = "";
    for(int i = 0; i < 10; i++) {
        tabOsob[i] = NULL;
        tabObecnosci[i] = false;
    }
}

void ListaObecnosci::ustawZajecia(string _nazwaZajec, string _imie, string _nazwisko, string _nr) {
    nazwaZajec = _nazwaZajec;
    prowadzacy.setImie(_imie);
    prowadzacy.setNazwisko(_nazwisko);
    prowadzacy.setNr_Pracownika(_nr);
}

void ListaObecnosci::drukujNazwe() {
    cout << nazwaZajec;
    prowadzacy.drukuj();
}

bool ListaObecnosci::dodajOsobe(Student *osoba) {
    if(licznik < 10) {
        tabOsob[licznik] = osoba;
        tabObecnosci[licznik] = false;
        licznik++;
        return true;
    } else {
        cout << "\nError! Lista jest pelna.";
        return false;
    }
}

bool ListaObecnosci::ustawObecnosc(string nazwisko, int wybor) {
    bool znaleziono = false;
    for(int i = 0; i < licznik; i++) {
        if(tabOsob[i]->getNazwisko() == nazwisko) {
            if(wybor == 1) {
                tabObecnosci[i] = true;
            } else {
                tabObecnosci[i] = false;
            }
            znaleziono = true;
        } 
    }
    return znaleziono;
}

void ListaObecnosci::drukujListeObecnosci() {
    if(licznik == 0) {
        cout << "\nBrak osob na tej liscie.\n";
        return;
    }
    cout << "\n###| Lista Obecnosci |###";
    for(int i = 0; i < licznik; i++) {
        cout << "\n" << i+1 << ": ";
        tabOsob[i]->drukuj();
        cout << " - ";
        if(tabObecnosci[i]) {
            cout << "Obecny";
        } else {
            cout << "Nieobecny";
        }
    }
    cout << "\n";
}

void ListaObecnosci::drukujListeOsob() {
    cout << "\n###| Lista Osob |###";
    for(int i = 0; i < licznik; i++) {
        cout << "\n" << i << ": ";
        tabOsob[i]->drukuj();
    }
}

void ListaObecnosci::zmianaDanych_Edycja(int wybor, string nrIndex, string imie, string nazwisko) {
    if(wybor < licznik && wybor > -1) {
        tabOsob[wybor]->setNr_Index(nrIndex);
        tabOsob[wybor]->setImie(imie);
        tabOsob[wybor]->setNazwisko(nazwisko);
    } else {
        cout << "\nError! Poza lista... ";
    }
}

void ListaObecnosci::zmianaDanych_Usuwanie(int wybor) {
    if(wybor < licznik && wybor > -1) {
        for(int i = wybor; i < licznik - 1; i++) {
            tabOsob[i] = tabOsob[i+1];
            tabObecnosci[i] = tabObecnosci[i+1];
        }
        tabOsob[licznik-1] = NULL;
        tabObecnosci[licznik-1] = false;
        licznik--;
    } else {
        cout << "\nError! Poza lista... ";
    }
}

int ListaObecnosci::getLicznik() {
    return licznik;
}

//====================
//InterfejsUzytkownika
//====================
InterfejsUzytkownika::InterfejsUzytkownika() {
    iluStudentow = 0;
    tabOsob = NULL; 
    ileList = 0;
    aktualnaLista = -1;
}

void InterfejsUzytkownika::setTablicaOsob(Student *tab) {
    tabOsob = tab;
}

void InterfejsUzytkownika::petla() {
    if(tabOsob == NULL) {
        cout << "Blad krytyczny: Interfejs nie otrzymal zrodla danych!";
        return;
    }

    //================
    //Zmienne programu
    //================
    bool CzyProgramOdpalony = true;
    int wybor = 0;
    string imie, nazwisko, nrIndex, nazwaZajec, nrPracownika;

    //==============
    //Pętla programu
    //==============
    do {
        //==================
        //Interfejs programu
        //==================
        cout << "\n#######################################";
        cout << "\n### 1. Dodaj Prowadzacego i Zajecia ###";
        cout << "\n### 2. Wybierz / Przelacz Zajecia   ###";
        cout << "\n### 3. Dodaj Osobe                  ###";
        cout << "\n### 4. Zmien Dane Osoby             ###";
        cout << "\n### 5. Ustaw Obecnosc               ###";
        cout << "\n### 6. Drukuj liste                 ###";
        cout << "\n### 7. Zakoncz Program              ###";
        cout << "\n#######################################";
        
        if(aktualnaLista != -1) {
            cout << "\n[Wybrane zajecia: ";
            listy[aktualnaLista].drukujNazwe();
            cout << "]";
        } else {
            cout << "\n[Nie wybrano zadnych zajec]";
        }
        
        cout << "\nPodaj numer: ";
        cin >> wybor;
        cout << "\n";

        switch (wybor) {
        //===============
        //Tworzenie zajec
        //===============
        case 1:
            if(ileList < 10) {
                cout << "\n###| Nowe Zajecia |###";
                cout << "\nPodaj nazwe zajec: "; cin >> nazwaZajec;
                cout << "\nPodaj imie prowadzacego: "; cin >> imie;
                cout << "\nPodaj nazwisko prowadzacego: "; cin >> nazwisko;
                cout << "\nPodaj numer pracownika: "; cin >> nrPracownika;
                
                listy[ileList].ustawZajecia(nazwaZajec, imie, nazwisko, nrPracownika);
                aktualnaLista = ileList;
                ileList++;
            } else {
                cout << "\nError! Maksymalna ilosc zajec.";
            }
            break;
        //=======================
        //Wybieranie/zmiana zajec
        //=======================
        case 2:
            if(ileList == 0) {
                cout << "\nBrak utworzonych zajec.";
            } else {
                cout << "\n###| Wybierz Zajecia |###";
                for(int i = 0; i < ileList; i++) {
                    cout << "\n" << i << ": ";
                    listy[i].drukujNazwe();
                }
                cout << "\nPodaj numer zajec: ";
                cin >> wybor;
                if(wybor >= 0 && wybor < ileList) {
                    aktualnaLista = wybor;
                } else {
                    cout << "\nBledny numer zajec.";
                }
            }
            break;

        //===============
        //Dodawanie osoby
        //===============
        case 3:
            if(aktualnaLista == -1) {
                cout << "\nError! Najpierw wybierz lub dodaj zajecia.";
                break;
            }
            if(iluStudentow >= 10) {
                cout << "\nError! Baza studentow jest pelna (max 10).";
                break;
            }
            cout << "\n###| Wybrano Dodaj Osobe |###";
            cout << "\nPodaj imie: "; cin >> imie;
            cout << "\nPodaj nazwisko: "; cin >> nazwisko;
            cout << "\nPodaj index: "; cin >> nrIndex;

            tabOsob[iluStudentow].setImie(imie);
            tabOsob[iluStudentow].setNazwisko(nazwisko);
            tabOsob[iluStudentow].setNr_Index(nrIndex);
            
            if(listy[aktualnaLista].dodajOsobe(&tabOsob[iluStudentow])) {
                iluStudentow++;
            }
            break;

        //=============
        //Zmiana Danych
        //=============
        case 4:
            if(aktualnaLista == -1) {
                cout << "\nError! Najpierw wybierz lub dodaj zajecia.";
                break;
            }
            if(listy[aktualnaLista].getLicznik() == 0) {
                cout << "\nError! Brak osob na wybranej liscie. Nie mozna modyfikowac danych.";
                break;
            }
            cout << "\n###| Zmiana Danych Osoby |###";
            cout << "\n#######################################";
            cout << "\n### Wpisz 1 aby edytowac dane osoby ###";
            cout << "\n### Wpisz 2 aby usunac osobe z bazy ###";
            cout << "\n#######################################";
            cout << "\nWpisz [1|2]: ";
            cin >> wybor;
            
            switch (wybor) {
                case 1:
                    listy[aktualnaLista].drukujListeOsob();
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;
                    cout << "\nPodaj imie: "; cin >> imie;
                    cout << "\nPodaj nazwisko: "; cin >> nazwisko;
                    cout << "\nPodaj index: "; cin >> nrIndex;
                    listy[aktualnaLista].zmianaDanych_Edycja(wybor, nrIndex, imie, nazwisko);
                    break;
                case 2:
                    listy[aktualnaLista].drukujListeOsob();
                    cout << "\nPodaj nr z listy do usuniecia: ";
                    cin >> wybor;
                    listy[aktualnaLista].zmianaDanych_Usuwanie(wybor);
                    break;
                default:
                    cout << "\nWpisano bledna liczbe. Powrot...";
                    break;
            }
            break;

        //====================
        //Ustawianie obecnosci
        //====================
        case 5:
            if(aktualnaLista == -1) {
                cout << "\nError! Najpierw wybierz lub dodaj zajecia.";
                break;
            }
            if(listy[aktualnaLista].getLicznik() == 0) {
                cout << "\nError! Brak osob na wybranej liscie. Nie mozna sprawdzic obecnosci.";
                break;
            }
            cout << "\n###| Ustawianie Obecnosci |###";
            cout << "\nPodaj nazwisko osoby: ";
            cin >> nazwisko;
            cout << "\nCzy ta osoba jest obecna? [T: 1 | N: 2]: ";
            cin >> wybor;
            if(!listy[aktualnaLista].ustawObecnosc(nazwisko, wybor)) {
                cout << "\nError! Nie znaleziono osoby o takim nazwisku.";
            }
            break;

        //================
        //Drukowanie listy
        //================
        case 6:
            if(aktualnaLista == -1) {
                cout << "\nError! Najpierw wybierz lub dodaj zajecia.";
                break;
            }
            listy[aktualnaLista].drukujListeObecnosci();
            break;

        //===================
        //Zamkniecie programu
        //===================
        case 7:
            CzyProgramOdpalony = false;
            break;

        default:
            cout << "\nWpisano bledna liczbe. Powrot do menu...";
            break;
        }
    } while(CzyProgramOdpalony);
}

//####################################################################################

int main() {
    Student tabOsob[10];
    InterfejsUzytkownika ui;

    ui.setTablicaOsob(tabOsob);
    ui.petla();

    return 0;
}