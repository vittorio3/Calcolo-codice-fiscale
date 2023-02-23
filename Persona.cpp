#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
#include <string>
#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// funzioni per prendere gli input

char*Persona::GetSesso() { return &Sesso; }
char* Persona::GetNome(void) { return Nome; }
char* Persona::GetCognome(void) { return Cognome; }
int* Persona::Get_Anno_Mese_Giorno(const int z) { return &AnnoMeseGiorno[z];}
char* Persona::GetPaeseDiNascita(void) { return PaeseDiNascita; }
//


char* Persona::CalcoloCodiceFiscale()
{
	FILE* p = fopen("charFiscale", "w+");
	if (!p) {
		cout << "File non aperto"; return NULL;
	}
	
	CostruttoreTabella(); // chiamo il costruttore della tabella
	CostruttoreTabellaCharPosizioneDispari();//costruisce char dispari
	CostruttoreTabellaCharPosizionePari();//Costruisce tabella char pari
	CostruttoreTabellaRestoVentiSei();// costruttore tabella dei char per %26

	RemoveDoubleLettere(Cognome); // sistem cognome 

	// cognome
	if (ReturnNumCons(Cognome) >= 3)
	{
		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (Cognome[i] != 'a' && Cognome[i] != 'e' && Cognome[i] != 'i' && Cognome[i] != 'o' && Cognome[i] != 'u')
			{
				fprintf(p, "%c", Cognome[i]);
				t++;
			}
		}
	}
	
	else if (ReturnNumCons(Cognome) >= 2 && ReturnNumVoc(Cognome) >= 1)
	{
		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t <=1)
			{
				if (Cognome[i] != 'a' && Cognome[i] != 'e' && Cognome[i] != 'i' && Cognome[i] != 'o' && Cognome[i] != 'u')
				{
					fprintf(p, "%c", Cognome[i]);
					t++;
				}
			}
			else
			{
				int in = 0;
				while (1) {
					if (Cognome[in] == 'a' || Cognome[in] == 'e' || Cognome[in] == 'i' || Cognome[in] == 'o' || Cognome[in] == 'u')
					{
						fprintf(p, "%c", Cognome[in]);
						t++;
						break;
					}
					else in++;
				}
			}

		}
	}
	else if (ReturnNumCons(Cognome) == 1 && ReturnNumVoc(Cognome) >= 2)
	{
		
		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t < 1)
			{
				if (Cognome[i] != 'a' && Cognome[i] != 'e' && Cognome[i] != 'i' && Cognome[i] != 'o' && Cognome[i] != 'u')
				{
					fprintf(p, "%c", Cognome[i]);
					t++;
				}
			}
			else
			{
				int in = 0;
				while (t<3) {
					if (Cognome[in] == 'a' || Cognome[in] == 'e' || Cognome[in] == 'i' || Cognome[in] == 'o' || Cognome[in] == 'u')
					{
						fprintf(p, "%c", Cognome[in]);
						t++;
					}
					in++;
				}
			}

		}
	}
	else if (ReturnNumCons(Cognome) == 1 && ReturnNumVoc(Cognome) == 1)
	{

		int t = 0; int n = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t < 1)
			{

				if (Cognome[i] != 'a' && Cognome[i] != 'e' && Cognome[i] != 'i' && Cognome[i] != 'o' && Cognome[i] != 'u')
				{
					fprintf(p, "%c", Cognome[i]);
					t++;
				}
			}
			else if (t < 2)
			{

				if (Cognome[n] == 'a' || Cognome[n] == 'e' || Cognome[n] == 'i' || Cognome[n] == 'o' || Cognome[n] == 'u')
				{
					fprintf(p, "%c", Cognome[n]);
					t++;
				}
				n++;
			}
			else if (t == 2)
			{

				fprintf(p, "x");
				t++;
			}
		}

	}else return NULL;

	// Nome
	RemoveDoubleLettere(Nome); // sistemo il nome
	
	if (ReturnNumCons(Nome) >= 3)
	{
		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (Nome[i] != 'a' && Nome[i] != 'e' && Nome[i] != 'i' && Nome[i] != 'o' && Nome[i] != 'u')
			{
				fprintf(p, "%c", Nome[i]);
				t++;
			}
		}
	}

	else if (ReturnNumCons(Nome) == 2 && ReturnNumVoc(Nome) >= 1)
	{
		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t <= 1)
			{
				if (Nome[i] != 'a' && Nome[i] != 'e' && Nome[i] != 'i' && Nome[i] != 'o' && Nome[i] != 'u')
				{
					fprintf(p, "%c", Nome[i]);
					t++;
				}
			}
			else
			{
				int in = 0;
				while (1) {
					if (Nome[in] == 'a' || Nome[in] == 'e' || Nome[in] == 'i' || Nome[in] == 'o' || Nome[in] == 'u')
					{
						fprintf(p, "%c", Nome[in]);
						t++;
						break;
					}
					else in++;
				}
			}

		}
	}
	else if (ReturnNumCons(Nome) == 1 && ReturnNumVoc(Nome) >= 2)
	{

		int t = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t < 1)
			{
				if (Nome[i] != 'a' && Nome[i] != 'e' && Nome[i] != 'i' && Nome[i] != 'o' && Nome[i] != 'u')
				{
					fprintf(p, "%c", Nome[i]);
					t++;
				}
			}
			else
			{
				int in = 0;
				while (t < 3) {
					if (Nome[in] == 'a' || Nome[in] == 'e' || Nome[in] == 'i' || Nome[in] == 'o' || Nome[in] == 'u')
					{
						fprintf(p, "%c", Nome[in]);
						t++;
					}
					in++;
				}
			}

		}
	}
	else if (ReturnNumCons(Nome) == 1 && ReturnNumVoc(Nome) == 1)
	{

		int t = 0; int n = 0;
		for (int i = 0; t < 3; i++)
		{
			if (t < 1)
			{

				if (Nome[i] != 'a' && Nome[i] != 'e' && Nome[i] != 'i' && Nome[i] != 'o' && Nome[i] != 'u')
				{
					fprintf(p, "%c", Nome[i]);
					t++;
				}
			}
			else if (t < 2)
			{

				if (Nome[n] == 'a' || Nome[n] == 'e' || Nome[n] == 'i' || Nome[n] == 'o' || Nome[n] == 'u')
				{
					fprintf(p, "%c", Nome[n]);
					t++;
				}
				n++;
			}
			else if (t == 2)
			{

				fprintf(p, "x");
				t++;
			}
		}

	}
	else return NULL;
	// setto nome e cognome perfetto
	if (AnnoMeseGiorno[0] > 99)return NULL;
	if(AnnoMeseGiorno[0]<=9)
	fprintf(p, "0%d", AnnoMeseGiorno[0]);
	else fprintf(p, "%d", AnnoMeseGiorno[0]);

	// annno di nascita 
	

	// NOTA NOTA NOTA 
	//RICORDA CHE LA FUNZIONE GET ANNO MESE GIORNO
	// return int*p
	// quindi se ritorna un puntatore a v[1]
	// rispetto a quel puntatore p[0]==V[1]
	// questo avviene nel main()
	
	int i = 0;

	while(i<12)
	{
		if (AnnoMeseGiorno[1] == DodiciMesi[i].Mese)
			fprintf(p, "%c", DodiciMesi[i].CharRelativo);
		i++;
	}
	// Setto il char relativo al mese

	if (Sesso == 'f')fprintf(p, "%d", AnnoMeseGiorno[2] + 40);
	else if (Sesso == 'm')fprintf(p, "%d", AnnoMeseGiorno[2]);
	else return NULL;
	// inserimento della data di nascita (giorno)

	FILE* f = fopen("C:\\Users\\User\\Desktop\\tabella nomi city.txt", "r");
	if (!f) {
		cout << "File non trovato";
		return NULL;
	}

	for (int i = 0; PaeseDiNascita[i] != '\0'; i++)if(PaeseDiNascita[i]!='_')PaeseDiNascita[i] -= 32; // da minusc a maiusc
	char Buffer[100];
	char CodiceCatastale[5];
	int QualeRiga = 0;


	do{
		fgets(Buffer, 100, f);

		for (int za = 0; Buffer[za] != '\0'; za++)
			if (Buffer[za] == ' ')Buffer[za] = '_';
			else if (Buffer[za] == '\n')Buffer[za] = '\0';
		
		int n;
		if (!strcmp(PaeseDiNascita,Buffer))
		{
			fclose(f);
			FILE* d = fopen("C:\\Users\\User\\Desktop\\tabella codici.txt", "r");
			if (!d)
			{
				cout << "Tentativo di lettura fallito";
				return NULL;
			}
			while (QualeRiga >= 0)
			{
				fscanf(d, "%s", CodiceCatastale);
				QualeRiga--;
			}
			fclose(d);
			break;
		}
		else QualeRiga++;
	} while (1);

	fprintf(p, "%s", CodiceCatastale);

	// Inserimento codice catastale


	
	rewind(p);

	fgets(this->CodiceFiscale, 100, p);

	CodiceFiscale[11] += 32;

	int ModSei = 0;

	int kp; int posizione = 1;
	for (kp = 0; CodiceFiscale[kp] != '\0'; kp++)
	{
		
		if (!(posizione % 2))
		{
			for (int na = 0; na < 36; na++)
			{
				if (TabellaCharPosizonePari[na].CharRelativo == CodiceFiscale[kp])
				{
					// printf("%c:2=%d\n", CodiceFiscale[kp], TabellaCharPosizonePari[na].Mese);
					ModSei += (TabellaCharPosizonePari[na].Mese);
					break;
				}
			}
		}
		else
		{
			for (int na = 0; na < 36; na++)
			{
				if (TabellaCharPoszioneDispari[na].CharRelativo == CodiceFiscale[kp])
				{
					// printf("%c:3=%d\n", CodiceFiscale[kp], TabellaCharPoszioneDispari[na].Mese);
					ModSei += (TabellaCharPoszioneDispari[na].Mese);
					break;
				}
			}
		}
		
		posizione++;
	}
	// printf("%d\n", ModSei); test
	int zysz = ModSei % 26;

	// printf("%s\n ", CodiceFiscale); test
	// printf("%d %26= %d",ModSei,zysz); test

	

	for (int a = 0; a < 26; a++)
	{
		if (zysz == TabellaRestoChar[a].Mese)
		{
			fseek(p, 0, SEEK_CUR);
			fprintf(p, "%c", TabellaRestoChar[a].CharRelativo);
			break;
		}
	}
	// codice controllo
	rewind(p);
	
	fgets(CodiceFiscale, 100, p);
	
	CodiceFiscale[17] = '\0';
	CodiceFiscale[0] -= 32;
	CodiceFiscale[1] -= 32;
	CodiceFiscale[2] -= 32;
	CodiceFiscale[3] -= 32;
	CodiceFiscale[4] -= 32;
	CodiceFiscale[5] -= 32;
	CodiceFiscale[8] -= 32;
	CodiceFiscale[15] -= 32;

	// da minusc a maiuscc sapendo
	// che distanza da ASCII a ascii = ASCII+=32

	fclose(p);

	return CodiceFiscale; 
	

}

int Persona::ReturnNumCons(char* V) // ritorna il numero consonanti 
{
	int n = 0;
	for (int i = 0; V[i] != '\0'; i++)
	{
		if (V[i] != 'a' && V[i] != 'e' && V[i] != 'i' && V[i] != 'o' && V[i] != 'u')
			n++;
	}
	return n;
}

int Persona::ReturnNumVoc(char* V) // ritorna il numeri di vocali
{
	int n = 0;
	for (int i = 0; V[i] != '\0'; i++)
	{
		if (V[i] == 'a' || V[i] == 'e' || V[i] == 'i' || V[i] == 'o' || V[i] == 'u')
			n++;
	}
	return n;
}


void Persona::RemoveDoubleLettere(char*V) // togli le lettere che compaiono due volte
{
	NodeInChar* List = NULL;
	int i = 0; int z;
	for ( z = 0; V[z] != '\0'; z++);
	
	while (i<=z)
	{
		AddLastNode(&List, V[i]);
		i++;
	}

	i = 0;
	while (i <= z)
	{
		DelDetCharMag1(&List, V[i]);
		i++;
	}
	
	i = 0;
	NodeInChar* p = List;
	while (p)
	{
		V[i] = p->Val;
		p = p->next;
		i++;
	}
	
	return;
	
}
void Persona::DelDetCharMag1(NodeInChar**l, char v)
{
	NodeInChar* s;
	int n = 0;
	while (*l)
	{
		if ((*l)->Val == v)
		{
			if (n)
			{
				s = *l;
				*l = s->next;
				free(s);
			}
			n++;
		}
		l = &(*l)->next;
	}
}


int Persona::PrintList(NodeInChar* l)
{
	int p = 0;
	while (l)
	{
		printf("%c->", l->Val);
		l = l->next;
		p++;
	}
	printf("NULL");
	return p;
}

void Persona::AddLastNode(NodeInChar** l, char v)
{
	while (*l)l = &(*l)->next;
	*l = NewNode(v);
	return;
}
//

NodeInChar* Persona::NewNode(char v)
{
	NodeInChar* p = (NodeInChar*)malloc(sizeof(NodeInChar));
	if (!p) {
		cout << "Malloc Fallita";
		return NULL;
	}
	p->Val = v;
	p->next = NULL;
	return p;
}



////////////////////////////////////////////////////////////////////////////////
/////////// TABELLA MESI INT E SUO CHAR RELATIVO PER MESE //////////////////////
/////////////// NON TOCCARE NON TOCARE NON TOCCARE ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void Persona::CostruttoreTabella()
{
	DodiciMesi[0].Mese =1; // gennaio
	DodiciMesi[0].CharRelativo = 'a'; 

	DodiciMesi[1].Mese = 2; // febbraio
	DodiciMesi[1].CharRelativo = 'b';

	DodiciMesi[2].Mese =3; // marzo
	DodiciMesi[2].CharRelativo = 'c';

	DodiciMesi[3].Mese = 4; // aprile
	DodiciMesi[3].CharRelativo = 'd';

	DodiciMesi[4].Mese = 5; // maggio
	DodiciMesi[4].CharRelativo = 'e';

	DodiciMesi[5].Mese = 6; //giugno
	DodiciMesi[5].CharRelativo = 'h';

	DodiciMesi[6].Mese = 7; //luglio
	DodiciMesi[6].CharRelativo = 'l';

	DodiciMesi[7].Mese = 8; // agosto
	DodiciMesi[7].CharRelativo = 'm';

	DodiciMesi[8].Mese = 9; // settembre
	DodiciMesi[8].CharRelativo = 'p';

	DodiciMesi[9].Mese = 10; // ottobre
	DodiciMesi[9].CharRelativo = 'r';

	DodiciMesi[10].Mese =11; // novembre
	DodiciMesi[10].CharRelativo = 's';

	DodiciMesi[11].Mese = 12; // dicembre
	DodiciMesi[11].CharRelativo = 't';

	return;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//***************************************************************************//

////////////////////////////////////////////////////////////////////////////////
////////////////////TABELLA CHAR DI POSIZIONE DISPARI///////////////////////////
////////////////////E RELATIVI INTERI///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Persona::CostruttoreTabellaCharPosizioneDispari()
{
	TabellaCharPoszioneDispari[0].CharRelativo = '0';
	TabellaCharPoszioneDispari[0].Mese = 1;

	TabellaCharPoszioneDispari[1].CharRelativo = '1';
	TabellaCharPoszioneDispari[1].Mese = 0;

	TabellaCharPoszioneDispari[2].CharRelativo = '2';
	TabellaCharPoszioneDispari[2].Mese = 5;

	TabellaCharPoszioneDispari[3].CharRelativo = '3';
	TabellaCharPoszioneDispari[3].Mese = 7;

	TabellaCharPoszioneDispari[4].CharRelativo = '4';
	TabellaCharPoszioneDispari[4].Mese = 9;

	TabellaCharPoszioneDispari[5].CharRelativo = '5';
	TabellaCharPoszioneDispari[5].Mese = 13;

	TabellaCharPoszioneDispari[6].CharRelativo = '6';
	TabellaCharPoszioneDispari[6].Mese = 15;

	TabellaCharPoszioneDispari[7].CharRelativo = '7';
	TabellaCharPoszioneDispari[7].Mese = 17;

	TabellaCharPoszioneDispari[8].CharRelativo = '8';
	TabellaCharPoszioneDispari[8].Mese = 19;

	TabellaCharPoszioneDispari[9].CharRelativo = '9';
	TabellaCharPoszioneDispari[9].Mese = 21;

	TabellaCharPoszioneDispari[10].CharRelativo = 'a';
	TabellaCharPoszioneDispari[10].Mese = 1;

	TabellaCharPoszioneDispari[11].CharRelativo = 'b';
	TabellaCharPoszioneDispari[11].Mese = 0;

	TabellaCharPoszioneDispari[12].CharRelativo = 'c';
	TabellaCharPoszioneDispari[12].Mese = 5;

	TabellaCharPoszioneDispari[13].CharRelativo = 'd';
	TabellaCharPoszioneDispari[13].Mese = 7;

	TabellaCharPoszioneDispari[14].CharRelativo = 'e';
	TabellaCharPoszioneDispari[14].Mese = 9;

	TabellaCharPoszioneDispari[15].CharRelativo = 'f';
	TabellaCharPoszioneDispari[15].Mese = 13;

	TabellaCharPoszioneDispari[16].CharRelativo = 'g';
	TabellaCharPoszioneDispari[16].Mese = 15;

	TabellaCharPoszioneDispari[17].CharRelativo = 'h';
	TabellaCharPoszioneDispari[17].Mese = 17;

	TabellaCharPoszioneDispari[18].CharRelativo = 'i';
	TabellaCharPoszioneDispari[18].Mese = 19;

	TabellaCharPoszioneDispari[19].CharRelativo = 'j';
	TabellaCharPoszioneDispari[19].Mese = 21;

	TabellaCharPoszioneDispari[20].CharRelativo = 'k';
	TabellaCharPoszioneDispari[20].Mese = 2;

	TabellaCharPoszioneDispari[21].CharRelativo = 'l';
	TabellaCharPoszioneDispari[21].Mese = 4;

	TabellaCharPoszioneDispari[22].CharRelativo = 'm';
	TabellaCharPoszioneDispari[22].Mese = 18;

	TabellaCharPoszioneDispari[23].CharRelativo = 'n';
	TabellaCharPoszioneDispari[23].Mese = 20;

	TabellaCharPoszioneDispari[24].CharRelativo = 'o';
	TabellaCharPoszioneDispari[24].Mese = 11;

	TabellaCharPoszioneDispari[25].CharRelativo = 'p';
	TabellaCharPoszioneDispari[25].Mese = 3;

	TabellaCharPoszioneDispari[26].CharRelativo = 'q';
	TabellaCharPoszioneDispari[26].Mese = 6;

	TabellaCharPoszioneDispari[27].CharRelativo = 'r';
	TabellaCharPoszioneDispari[27].Mese = 8;

	TabellaCharPoszioneDispari[28].CharRelativo = 's';
	TabellaCharPoszioneDispari[28].Mese = 12;

	TabellaCharPoszioneDispari[29].CharRelativo = 't';
	TabellaCharPoszioneDispari[29].Mese = 14;

	TabellaCharPoszioneDispari[30].CharRelativo = 'u';
	TabellaCharPoszioneDispari[30].Mese = 16;

	TabellaCharPoszioneDispari[31].CharRelativo = 'v';
	TabellaCharPoszioneDispari[31].Mese = 10;

	TabellaCharPoszioneDispari[32].CharRelativo = 'w';
	TabellaCharPoszioneDispari[32].Mese = 22;

	TabellaCharPoszioneDispari[33].CharRelativo = 'x';
	TabellaCharPoszioneDispari[33].Mese = 25;

	TabellaCharPoszioneDispari[34].CharRelativo = 'y';
	TabellaCharPoszioneDispari[34].Mese = 24;

	TabellaCharPoszioneDispari[35].CharRelativo = 'z';
	TabellaCharPoszioneDispari[35].Mese = 23;

	return;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//***************************************************************************//

////////////////////////////////////////////////////////////////////////////////
////////////////////TABELLA CHAR DI POSIZIONE PARI///////////////////////////
////////////////////E RELATIVI INTERI///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Persona::CostruttoreTabellaCharPosizionePari()
{
	TabellaCharPosizonePari[0].CharRelativo = '0';
	TabellaCharPosizonePari[0].Mese = 0;

	TabellaCharPosizonePari[1].CharRelativo = '1';
	TabellaCharPosizonePari[1].Mese = 1;

	TabellaCharPosizonePari[2].CharRelativo = '2';
	TabellaCharPosizonePari[2].Mese = 2;

	TabellaCharPosizonePari[3].CharRelativo = '3';
	TabellaCharPosizonePari[3].Mese = 3;

	TabellaCharPosizonePari[4].CharRelativo = '4';
	TabellaCharPosizonePari[4].Mese = 4;

	TabellaCharPosizonePari[5].CharRelativo = '5';
	TabellaCharPosizonePari[5].Mese = 5;

	TabellaCharPosizonePari[6].CharRelativo = '6';
	TabellaCharPosizonePari[6].Mese = 6;

	TabellaCharPosizonePari[7].CharRelativo = '7';
	TabellaCharPosizonePari[7].Mese = 7;

	TabellaCharPosizonePari[8].CharRelativo = '8';
	TabellaCharPosizonePari[8].Mese = 8;

	TabellaCharPosizonePari[9].CharRelativo = '9';
	TabellaCharPosizonePari[9].Mese = 9;

	TabellaCharPosizonePari[10].CharRelativo = 'a';
	TabellaCharPosizonePari[10].Mese = 0;

	TabellaCharPosizonePari[11].CharRelativo = 'b';
	TabellaCharPosizonePari[11].Mese = 1;

	TabellaCharPosizonePari[12].CharRelativo = 'c';
	TabellaCharPosizonePari[12].Mese =2;

	TabellaCharPosizonePari[13].CharRelativo = 'd';
	TabellaCharPosizonePari[13].Mese = 3;

	TabellaCharPosizonePari[14].CharRelativo = 'e';
	TabellaCharPosizonePari[14].Mese = 4;

	TabellaCharPosizonePari[15].CharRelativo = 'f';
	TabellaCharPosizonePari[15].Mese = 5;

	TabellaCharPosizonePari[16].CharRelativo = 'g';
	TabellaCharPosizonePari[16].Mese = 6;

	TabellaCharPosizonePari[17].CharRelativo = 'h';
	TabellaCharPosizonePari[17].Mese = 7;

	TabellaCharPosizonePari[18].CharRelativo = 'i';
	TabellaCharPosizonePari[18].Mese = 8;

	TabellaCharPosizonePari[19].CharRelativo = 'j';
	TabellaCharPosizonePari[19].Mese = 9;

	TabellaCharPosizonePari[20].CharRelativo = 'k';
	TabellaCharPosizonePari[20].Mese = 10;

	TabellaCharPosizonePari[21].CharRelativo = 'l';
	TabellaCharPosizonePari[21].Mese = 11;

	TabellaCharPosizonePari[22].CharRelativo = 'm';
	TabellaCharPosizonePari[22].Mese = 12;

	TabellaCharPosizonePari[23].CharRelativo = 'n';
	TabellaCharPosizonePari[23].Mese = 13;

	TabellaCharPosizonePari[24].CharRelativo = 'o';
	TabellaCharPosizonePari[24].Mese = 14;

	TabellaCharPosizonePari[25].CharRelativo = 'p';
	TabellaCharPosizonePari[25].Mese = 15;

	TabellaCharPosizonePari[26].CharRelativo = 'q';
	TabellaCharPosizonePari[26].Mese = 16;

	TabellaCharPosizonePari[27].CharRelativo = 'r';
	TabellaCharPosizonePari[27].Mese = 17;

	TabellaCharPosizonePari[28].CharRelativo = 's';
	TabellaCharPosizonePari[28].Mese = 18;

	TabellaCharPosizonePari[29].CharRelativo = 't';
	TabellaCharPosizonePari[29].Mese = 19;

	TabellaCharPosizonePari[30].CharRelativo = 'u';
	TabellaCharPosizonePari[30].Mese = 20;

	TabellaCharPosizonePari[31].CharRelativo = 'v';
	TabellaCharPosizonePari[31].Mese = 21;

	TabellaCharPosizonePari[32].CharRelativo = 'w';
	TabellaCharPosizonePari[32].Mese = 22;

	TabellaCharPosizonePari[33].CharRelativo = 'x';
	TabellaCharPosizonePari[33].Mese = 23;

	TabellaCharPosizonePari[34].CharRelativo = 'y';
	TabellaCharPosizonePari[34].Mese = 24;

	TabellaCharPosizonePari[35].CharRelativo = 'z';
	TabellaCharPosizonePari[35].Mese = 25;

	return;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
////////////// COSTRUTTORE TABELLA RESTO //////////////////////////////////////
/////////////// NON NON NON NON NON TOCCARE///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void Persona::CostruttoreTabellaRestoVentiSei()
{
	TabellaRestoChar[0].CharRelativo = 'a';
	TabellaRestoChar[0].Mese = 0;

	TabellaRestoChar[1].CharRelativo = 'b';
	TabellaRestoChar[1].Mese = 1;

	TabellaRestoChar[2].CharRelativo = 'c';
	TabellaRestoChar[2].Mese = 2;

	TabellaRestoChar[3].CharRelativo = 'd';
	TabellaRestoChar[3].Mese = 3;

	TabellaRestoChar[4].CharRelativo = 'e';
	TabellaRestoChar[4].Mese = 4;

	TabellaRestoChar[5].CharRelativo = 'f';
	TabellaRestoChar[5].Mese = 5;

	TabellaRestoChar[6].CharRelativo = 'g';
	TabellaRestoChar[6].Mese = 6;

	TabellaRestoChar[7].CharRelativo = 'h';
	TabellaRestoChar[7].Mese = 7;

	TabellaRestoChar[8].CharRelativo = 'i';
	TabellaRestoChar[8].Mese = 8;

	TabellaRestoChar[9].CharRelativo = 'j';
	TabellaRestoChar[9].Mese = 9;

	TabellaRestoChar[10].CharRelativo = 'k';
	TabellaRestoChar[10].Mese = 10;

	TabellaRestoChar[11].CharRelativo = 'l';
	TabellaRestoChar[11].Mese = 11;

	TabellaRestoChar[12].CharRelativo = 'm';
	TabellaRestoChar[12].Mese = 12;

	TabellaRestoChar[13].CharRelativo = 'n';
	TabellaRestoChar[13].Mese = 13;

	TabellaRestoChar[14].CharRelativo = 'o';
	TabellaRestoChar[14].Mese = 14;

	TabellaRestoChar[15].CharRelativo = 'p';
	TabellaRestoChar[15].Mese = 15;

	TabellaRestoChar[16].CharRelativo = 'q';
	TabellaRestoChar[16].Mese = 16;

	TabellaRestoChar[17].CharRelativo = 'r';
	TabellaRestoChar[17].Mese = 17;

	TabellaRestoChar[18].CharRelativo = 's';
	TabellaRestoChar[18].Mese = 18;

	TabellaRestoChar[19].CharRelativo = 't';
	TabellaRestoChar[19].Mese = 19;

	TabellaRestoChar[20].CharRelativo = 'u';
	TabellaRestoChar[20].Mese = 20;

	TabellaRestoChar[21].CharRelativo = 'v';
	TabellaRestoChar[21].Mese = 21;

	TabellaRestoChar[22].CharRelativo = 'w';
	TabellaRestoChar[22].Mese = 22;

	TabellaRestoChar[23].CharRelativo = 'x';
	TabellaRestoChar[23].Mese = 23;

	TabellaRestoChar[24].CharRelativo = 'y';
	TabellaRestoChar[24].Mese = 24;

	TabellaRestoChar[25].CharRelativo = 'z';
	TabellaRestoChar[25].Mese = 25;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
