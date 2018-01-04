#define _CRT_SECURE_NO_WARNINGS
// ------------------------------------- Biblioteki -------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
// Potrzebyny jest <regex.h> -- koniecznie !!!
      

// --------------------------------------- STALE ----------------------------------------
const int ROZMIAR_BUFORA = 100; // O ile zwiekszamy rozmair tablicy za kazdym jej przepelnieniem



// ---------------------------------- Naglowki funkcji ----------------------------------
void wyczyscKonsole();
char ** odczytajPlik(char *nazwaPliku);
int iloscZdanWLinii(char *tekst);



// ------------------------------------- Biblioteki -------------------------------------
int main(int argc, char *argv[])
{
	SetConsoleCP(GetACP()); // kodowanie pliku: ANSI // sprawdzic autoamtyczne !!! ???
	SetConsoleOutputCP(GetACP());

	// Zmienne
	char nazwaPliku[100]; // mozna zrobic to dynamicznie !!! ???
	


	// Program
	printf("Witaj w programie BookAnalyzer\n");
	printf("Podaj nazwe pliku do odczytu: ");
	scanf("%s", nazwaPliku);
	strcat(nazwaPliku, ".txt");

	wyczyscKonsole();
	getchar();

	printf("Wybrales plik: %s\n\n", nazwaPliku);



	// Odczyt z pliku
	char **liniaTekstu = odczytajPlik(nazwaPliku);
	
	if (!liniaTekstu) {
		fprintf(stderr, "Nie mozna zbudowac struktury danych\n");
		exit(1);
	}



	// Iteracja po tablicy ze stringami
	for (int i = 0; i < liniaTekstu[i] != NULL; i++)
	{
		printf("\n\n%s", liniaTekstu[i]);
	}



	// --------------------------- PROBY obliczen ---------------------------------------
	int iloscZdan = 0;
	int a = 0;

	for (int i = 0; i < liniaTekstu[i] != NULL; i++)
	{
		printf("\n\n%s", liniaTekstu[i]);
		
		//int dlugosc = strlen(linie[i]);
		//printf("\nDlugosc linii: %d", dlugosc);

		printf("\nIlosc zdan w linii: %d\n", iloscZdanWLinii(liniaTekstu[i]));
		iloscZdan = iloscZdan + iloscZdanWLinii(liniaTekstu[i]);

		for (char * p = strchr(liniaTekstu[i], 'a'); p != NULL; p = strchr(p + 1, 'a')) {
			printf("Litera 'a' znajduje sie na pozycji: %d\n", p - liniaTekstu[i]);
			a++;
		}
	}
	printf("\n\nCalkowita ilosc zdan: %d",iloscZdan);
	printf("\n\nCalkowita ilosc a w tekscie: %d", a);
	printf("\n\n Skonczylem");



	getchar();
	return 0;
}
// -------------------------------------- Funkcje ---------------------------------------
// ------------------------------------- Interfejs --------------------------------------
void wyczyscKonsole()
{
	system("@cls||clear");
}
// --------------------------------------- Plik -----------------------------------------
char ** odczytajPlik(char *nazwaPliku) {
	// Otwarcie pliku
	FILE *f = fopen(nazwaPliku, "r");
	if (!f) {
		fprintf(stderr, "Nie moge otworzyc pliku");
		return NULL;
	}


	int wielkoscTablicy = 0;

	// Alokacja miejsca dla wielkoscTablicy wskaznikow
	// tutaj sa linie, ale my chcemy docelowo zdania
	//char ** lines = (char **)malloc(wielkoscTablicy * sizeof(char *)); // Tutaj wedlug Dudy pierwszy element tablicy a nie typ zmiennej
	//char ** lines = (char **)realloc(NULL, wielkoscTablicy * sizeof(char *));
	char ** lines = NULL;
														   // Bufor dla pojedynczego slowa
	char buf[10000]; // Bufor dla kazdej linii
	int i = 0;

	// Zczytanie slow

	


	while (fgets(buf, 10000, f))
	{
		// Alokacja pamieci
		if (i == wielkoscTablicy) {
			
			wielkoscTablicy += ROZMIAR_BUFORA;

			char ** nowaTablica = (char **)realloc(lines, wielkoscTablicy * sizeof(char *));
			if (!nowaTablica) {
				fprintf(stderr, "Nie mozna zalokowac pamieci");
				exit(1);
			}
			lines = nowaTablica;
		}


		//printf("Mam w buforze: %s", buf);
		//printf("Dlugosc bufora: %d\n\n", strlen(buf));

		// Zastepuje znak konca linii znakiem konca stringu
		buf[strlen(buf)-1] = '\0';


		// Get length of buf
		int slen = strlen(buf);

		// Zalokowanie miejsca dla stringa (odpowiednio dlugiego)
		// Nowy rozmiar stringa // po ucieciu zbednego miejsca
		char *str = (char *)malloc(slen * sizeof(char));

		// Kopiuj string z bufora do stringa docelowego
		strcpy(str, buf);

		// Dolacz string docelowy do struktury zaczytanych danych
		lines[i] = str;

		i++;
	}


	//*len = i; // Ustaw dlugosc tablicy
	if (i == wielkoscTablicy) {
		char **ostatecznaTablica = (char **)realloc(lines, (wielkoscTablicy +1)*sizeof(char *));

		if (!ostatecznaTablica) {
			fprintf(stderr, "Nie mozna zroibc realloc \n");
			exit(1);
		}
		lines = ostatecznaTablica;
	}
	
	lines[i] = NULL; // NULL na koncu tablicy po to zeby nie zwracac rozmiaru refenrecja


	

	return lines;
}
// ------------------------------------- Obliczenia -------------------------------------
int iloscZdanWLinii(char *tekst) {
	//printf("\nPrzekazalem tekst: %s", tekst);
	char *p = tekst;
	int iloscZdanWeFragmencie = 0;
	
	while ((p = strstr(p, ".")) != NULL)
	{
		iloscZdanWeFragmencie++;
		p++;
	}

	return iloscZdanWeFragmencie;
}