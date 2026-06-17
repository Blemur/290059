#include <iostream>
#include <string>
using namespace std;

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
    string getImie()                   { return imie; }
    void setNazwisko(string _nazwisko) { if(_nazwisko.length() > 1) nazwisko = _nazwisko; }
    string getNazwisko()               { return nazwisko; }
};

//=============
//Class Student
//=============

class Student : public Osoba{
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
    string getNr_Index()               { return nr_index; }
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
    //==============
    //funkcje classy
    //==============
    public:
    ListaObecnosci();
    void dodajOsobe(Student*);
    void ustawObecnosc(string, int);
    void drukujListeObecnosci();
    //-------------------------
    void drukujListeOsob();
    void zmianaDanych_Edycja(int, string, string, string);
    void zmianaDanych_Usuwanie(int);
};

//==========================
//Class InterfejsUzytkownika
//==========================

class InterfejsUzytkownika{
    //==============
    //zmienne classy
    //==============
    private:
    ListaObecnosci *lista;
    Student *tabOsob;
    int iluStudentow;
    //==============
    //funkcje classy
    //==============
    public:
    InterfejsUzytkownika();
    void setLista(ListaObecnosci*);
    void setTablicaOsob(Student*);
    void petla();
};

//####################################################################################

//========================
//Działania funkcji classy
//========================

//==============
//ListaObecnosci
//==============
ListaObecnosci::ListaObecnosci() {
    licznik = 0;
    for(int i = 0; i < 10; i++) {
        tabOsob[i] = NULL;
        tabObecnosci[i] = false;
    }
}

void ListaObecnosci::dodajOsobe(Student *osoba) {
    if(licznik < 10) {
        tabOsob[licznik] = osoba;
        tabObecnosci[licznik] = false;
        licznik++;
    } else {
        cout << "\nError! Lista jest pelna.";
    }
}

void ListaObecnosci::ustawObecnosc(string nazwisko, int wybor) {
    for(int i = 0; i < licznik; i++) {
        if(tabOsob[i]->getNazwisko() == nazwisko) {
            if(wybor == 1) {
                tabObecnosci[i] = true;
            } else {
                tabObecnosci[i] = false;
            }
        } 
    }
}

void ListaObecnosci::drukujListeObecnosci() {
    cout << "\n###| Lista Obecnosci |###";
    for(int i = 0; i < licznik; i++) {
        cout << "\n" << i+1 << ": " << tabOsob[i]->getImie() << " " << tabOsob[i]->getNazwisko() << " - ";
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
        cout << "\n" << i << ": " << tabOsob[i]->getNr_Index() << " " << tabOsob[i]->getImie() << " " << tabOsob[i]->getNazwisko();
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

//====================
//InterfejsUzytkownika
//====================
InterfejsUzytkownika::InterfejsUzytkownika() {
    iluStudentow = 0;
    tabOsob = NULL;
    lista = NULL;
}

void InterfejsUzytkownika::setLista(ListaObecnosci *l) {
    lista = l;
}

void InterfejsUzytkownika::setTablicaOsob(Student *tab) {
    tabOsob = tab;
}

void InterfejsUzytkownika::petla() {
    // Sprawdzenie czy main() przekazał nam tablice
    if(tabOsob == NULL || lista == NULL) {
        cout << "Blad krytyczny: Interfejs nie otrzymal zrodla danych!";
        return;
    }

    //================
    //Zmienne programu
    //================
    bool CzyProgramOdpalony = true;
    int wybor = 0;
    string imie, nazwisko, nrIndex;

    //==============
    //Pętla programu
    //==============
    do {
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

        switch (wybor) {
        //===============
        //Dodawanie osoby
        //===============
        case 1:
            cout << "\n###| Wybrano Dodaj Osobe |###";
            cout << "\nPodaj imie: "; cin >> imie;
            cout << "\nPodaj nazwisko: "; cin >> nazwisko;
            cout << "\nPodaj index: "; cin >> nrIndex;

            tabOsob[iluStudentow].setImie(imie);
            tabOsob[iluStudentow].setNazwisko(nazwisko);
            tabOsob[iluStudentow].setNr_Index(nrIndex);
            
            lista->dodajOsobe(&tabOsob[iluStudentow]);
            iluStudentow++;
            break;

        //=============
        //Zmiana Danych
        //=============
        case 2:
            cout << "\n###| Zmiana Danych Osoby |###";
            cout << "\n#######################################";
            cout << "\n### Wpisz 1 aby edytowac dane osoby ###";
            cout << "\n### Wpisz 2 aby usunac osobe z bazy ###";
            cout << "\n#######################################";
            cout << "\nWpisz [1|2]: ";
            cin >> wybor;
            
            switch (wybor) {
                case 1:
                    lista->drukujListeOsob();
                    cout << "\nPodaj nr z listy: ";
                    cin >> wybor;
                    cout << "\nPodaj imie: "; cin >> imie;
                    cout << "\nPodaj nazwisko: "; cin >> nazwisko;
                    cout << "\nPodaj index: "; cin >> nrIndex;
                    lista->zmianaDanych_Edycja(wybor, nrIndex, imie, nazwisko);
                    break;
                case 2:
                    lista->drukujListeOsob();
                    cout << "\nPodaj nr z listy do usuniecia: ";
                    cin >> wybor;
                    lista->zmianaDanych_Usuwanie(wybor);
                    break;
                default:
                    cout << "\nWpisano bledna liczbe. Powrot...";
                    break;
            }
            break;

        //====================
        //Ustawianie obecnosci
        //====================
        case 3:
            cout << "\n###| Ustawianie Obecnosci |###";
            cout << "\nPodaj nazwisko osoby: ";
            cin >> nazwisko;
            cout << "\nCzy ta osoba jest obecna? [T: 1 | N: 2]: ";
            cin >> wybor;
            lista->ustawObecnosc(nazwisko, wybor);
            break;

        //================
        //Drukowanie listy
        //================
        case 4:
            lista->drukujListeObecnosci();
            break;

        //===================
        //Zamkniecie programu
        //===================
        case 5:
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
    Student tabOsob[20]; 

    ListaObecnosci lista1;
    ListaObecnosci lista2;
    
    InterfejsUzytkownika ui;
    
    ui.setTablicaOsob(tabOsob);
    ui.setLista(&lista1);

    ui.petla();

    return 0;
}