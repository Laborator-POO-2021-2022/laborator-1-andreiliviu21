#include <iostream>
#include <cstring>
using namespace std;

class Angajat {
    int varsta;
    char nume[20];
    char CNP[14];
    int salariu;
public:
    Angajat() {
        varsta = 0;
        strcpy_s(nume, "");
        strcpy_s(CNP, "");
        salariu = 0;
    }
    Angajat(int v, char n[], char C[], int s) {
        varsta = v;
        strcpy_s(nume, n);
        strcpy_s(CNP, C);
        salariu = s;
    }
    void afisare() { // afiseaza atributele clasei
        cout << "Varsta = " << varsta << endl;
        cout << "Nume = " << nume << endl;
        cout << "CNP = " << CNP << endl;
        cout << "Salariu = " << salariu << endl;
    } 
    void modif(int v,char n[], char C[], int s) {    // modifica atributele clasei
        varsta = v;
        strcpy_s(nume, n);
        strcpy_s(CNP, C);
        salariu = s;
    } 
    int getVarsta() {   // returneaza varsta
        return varsta;
    }
    char* getNume() {   // returneaza numele
        return nume;
    } 
    char* getCNP() {    // returneaza CNP-ul
        return CNP;
    } 
    int getSalariu(){   // returneaza salariul
        return salariu;
    } 
};

int main() {
    Angajat obj1;
    Angajat obj2(20, (char *) "Livian", (char *) "5012468750123", 3200);

    cout << "Salariul angajatului obj2 este: " << obj2.getSalariu() << " Lei" << endl;
    cout << "Numele angajatului obj2 este: " << obj2.getNume() << endl;

    cout << endl << "Am modificat datele obiectului 1" << endl;
    obj1.modif(27, (char *) "Andrei", (char *) "5103298765120", 4500);
    cout << "Datele angajatului obj1: " << endl;
    obj1.afisare();

    Angajat vector[3];
    vector[0].modif(18, (char *) "Viorel", (char *) "1054987653120", 2100);
	vector[1].modif(29, (char *) "Marcel", (char *) "1111245768510", 8100);
	vector[2].modif(40, (char *) "Costica", (char *) "1365289453121", 8100);
    
    for( int i = 0; i < 2; i ++)
	{
		for ( int j = i + 1; j < 3; j++)
		{
			if(strcmp(vector[i].getNume(),vector[j].getNume()) > 0)
			{
				Angajat aux;
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}

    cout << endl << "Angajati sortati dupa nume: \n"; 
    for( int i = 0; i < 3; i ++) {
        cout << endl;
		vector[i].afisare();
	}

    
    Angajat maxim;
    maxim = vector[0];
    for( int i = 1; i < 3; i ++) {
        if(maxim.getSalariu() < vector[i].getSalariu())
		{
			maxim = vector[i];
            
		}
	}

    cout << endl << "Angajatii cu salariu maxim:" << endl;
    for( int i = 0; i < 3; i ++) {
        if(maxim.getSalariu() == vector[i].getSalariu())
		{
			vector[i].afisare();
            cout << "\n";
		}
	}
    

    return 0;
}