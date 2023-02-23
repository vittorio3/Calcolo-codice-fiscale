#pragma once

typedef struct NodeInChar {
	char Val;
	struct NodeInChar* next;
};

typedef struct TabellaMesi {
	int Mese;
	char CharRelativo;
};

class Persona{
private:
	char Sesso;
	char Nome[30];
	char Cognome[30];
	int AnnoMeseGiorno[3];
	char PaeseDiNascita[30];
	char CodiceFiscale[30];
public:
	char*GetSesso();
	char* GetNome();  // prendi nome
	char* GetCognome(); // prendi cognome
	int*Get_Anno_Mese_Giorno(const int); // prendi anno mese giorno
	char* GetPaeseDiNascita(); // prendi paese 
	//
	char* CalcoloCodiceFiscale();  // calcola e ritorna codice fiscale
	
	// funzioni usate da calcoloodicefiscale
	int ReturnNumCons(char*);// ritorna numero consonanti
	int ReturnNumVoc(char*);//ritorna numero vocali
	void RemoveDoubleLettere(char*); // Sistemata funzione matto=mato assisis=asi

	// funzioni sulle liste

	void AddLastNode(NodeInChar**, char);//fz(x)che aggiunge nodi in coda
	NodeInChar* NewNode(char);//fz(x) che crea nuovo nodo
	void DelDetCharMag1(NodeInChar**, char);//fz(x) che elimina un det char che compare >1
	int PrintList(NodeInChar*);//fz(x) che stampa la lista

	// Tabelle

	TabellaMesi DodiciMesi[12];  // tabella guess che mese 
	void CostruttoreTabella();

	TabellaMesi TabellaCharPoszioneDispari[36]; // tabella cifre posizione pari
	void CostruttoreTabellaCharPosizioneDispari();

	TabellaMesi TabellaCharPosizonePari[36]; // tabella cifre posizioni dispari
	void CostruttoreTabellaCharPosizionePari();

	TabellaMesi TabellaRestoChar[26]; // guess resto per %26
	void CostruttoreTabellaRestoVentiSei();

};

