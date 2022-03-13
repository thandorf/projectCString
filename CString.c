#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CString
{
    char* string;
    int dlugosc;
} CString;

CString* cstring_new(const char* str)
{
    CString* nazwa = malloc(sizeof(CString));
    int dlugoscTymczasowa = strlen(str);
    nazwa->string = malloc(sizeof(char) * dlugoscTymczasowa + 1);
    strcpy(nazwa->string, str);
    nazwa->dlugosc = dlugoscTymczasowa;
    return nazwa;
}

// funckja zwracaj¹ca d³ugoœæ stringa
int zwrotDlugosci(char* str) {
    int dlugoscStringa = strlen(str);
    return dlugoscStringa;
}

// funkcja zmieniaj¹ca dowolny char w stringu
void zmianaZnaku(char* str) {
    char charZmieniajacy[2];
    printf("Podaj znak jaki chcesz wprowadzic: "); 
    scanf("%s", &charZmieniajacy); //pobieranie znaku który chcemy wprowadziæ

    int indexDoZmiany;
    printf("\nPodaj indeks ktory chcesz zmienic: ");
    scanf("%d", &indexDoZmiany); //pobieranie indeksu, który zostanie zmieniony

    char a[100];
    strcpy(a, str);
    a[indexDoZmiany] = charZmieniajacy[0];
    strcpy(str, a);
}

int main(void) {
    printf("Prosze, podaj ciag znakow:\n");
    char* pobranyString[100]; // deklaracja typu zmiennej pobranyString
    scanf("%s", pobranyString); //pobieramy ciag znakow
    CString* zmienna = cstring_new(pobranyString); //tworzymy nowa strukture

    int dl = zwrotDlugosci(pobranyString); //wywolujemy funkcje zwracajaca dlugosc stringa
    printf("Dlugosc ciagu znakow: %d\n", dl);

    zmianaZnaku(pobranyString); //wywolujemy funkcje zmieniajaca stringa
    printf("String po zmianie: %s", pobranyString);

    free(zmienna->string); //zwalniamy pamiêæ
    free(zmienna); //zwalniamy pamiêæ
    return 0;
}

