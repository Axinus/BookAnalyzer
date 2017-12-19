// ------------------------------------- Biblioteki -------------------------------------
#include <stdio.h>

// --------------------------------------- STALE ----------------------------------------


// ---------------------------------- Naglowki funkcji ----------------------------------


// ------------------------------------- Biblioteki -------------------------------------
int main(int argc, char *argv[])
{
	

	int num;
	FILE *fptr;
	char c;

	if ((fptr = fopen("testowy_tekst.txt", "r")) == NULL) {
		printf("Error! opening file");
		exit(1);
	}

	while ((c = fgetc(&fptr)) != EOF) {
		printf("%c", c);
	}

	fclose(fptr);


	getchar();

	return 0;
}
// -------------------------------------- Funkcje ---------------------------------------
