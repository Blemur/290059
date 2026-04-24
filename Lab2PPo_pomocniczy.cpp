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

int main(){
    Osoba osoba1;

    osoba1.setImie("Jan");
    cout << osoba1.getImie() << endl;
    osoba1.setNazwisko("Kowalski");
    cout << osoba1.getNazwisko() << endl;
    osoba1.setNr_Index("999999");
    cout << osoba1.getNr_Index() << endl;

    Osoba listaStudentow[10];

    for(int i = 0; i < 10; i++){

    }
}

