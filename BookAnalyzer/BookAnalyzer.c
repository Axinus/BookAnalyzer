// ------------------------------------- Biblioteki -------------------------------------
#include <stdio.h>
#include <stdlib.h>
// --------------------------------------- STALE ----------------------------------------


// ---------------------------------- Naglowki funkcji ----------------------------------
char ** loadfile(char * filename, int *len);


// ------------------------------------- Biblioteki -------------------------------------
int main(int argc, char *argv[])
{
	if (argc == 1) {
		fprintf(stderr, "Wprowadz nazwe pliku do odczytu");
		exit(1);
	}

	// Load file into data structure
	int length = 0;
	char **words = loadfile(argv[1], &length);

	// Display the first 100 lines



	getchar();

	return 0;
}
// -------------------------------------- Funkcje ---------------------------------------
char ** loadfile(char *filename, int *len) {
	// Otwarcie pliku
	FILE *f = fopen(filename, "r");
	if (!f) {
		fprintf(stderr, "Nie moge otworzyc pliku");
		return NULL;
	}


	// Alokacja miejsca dla 100 wskaznikow
	// tutaj sa linie, ale my chcemy docelowo zdania
	char ** lines = (char **)malloc(100 * sizeof(char *)); // Tutaj wedlug Dudy pierwszy element tablicy a nie typ zmiennej

														   // Bufor dla pojedynczego slowa
	char buf[1000];

	int i = 0;
	// Zczytanie slow
	while (fgets(buf, 1000, f))
	{
		if (i == 100) {
			realloc(lines, 200 * sizeof(char *));
		}


		// Trim of newline char // nieobowiazkowe !!! SPRAWDZIC
		buf[strlen(buf)] = '\0';

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
}