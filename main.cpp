#pragma warning (disable:4996)
#include <iostream>
#include "Persona.h"

using namespace std;

int main()
{
	cout << "---------------------------------------------------------" << endl;
	cout << "---------------CALCOLO CODICE FISCALE--------------------" << endl;
	cout << "---------------------------------------------------------" << endl << endl;

	Persona tu; 

	cout << "Inserisci il sesso: ";
	cin >> tu.GetSesso();
	cout << "Inserisci il cognome: ";
	cin >> tu.GetCognome();
	cout << "Inserisci il nome: ";
	cin >> tu.GetNome();
	cout << "Ultime due cifre anno di nascita: ";
	cin >> tu.Get_Anno_Mese_Giorno(0)[0];
	cout << "Inserisci mese di nascita: ";
	cin >> tu.Get_Anno_Mese_Giorno(1)[0];
	cout << "Inserisci giorno di nascita: ";
	cin >> tu.Get_Anno_Mese_Giorno(2)[0];
	cout << "Inserisci paese di nascita(2 parole inserire _ al posto degli spazi): ";
	cin >> tu.GetPaeseDiNascita();
	cout << endl << "Codice fiscale: ";
	
	char* Codice = tu.CalcoloCodiceFiscale();

	if (!Codice)cout << "Operazione Fallita";
	else cout << Codice;

	cout << endl<<endl;

	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	system("PAUSE");
}


