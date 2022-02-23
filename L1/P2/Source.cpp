#include <cstdio>

int convert(const char* s) {
    int numar = 0;
    int i;
    for (i = 0; s[i] && s[i] != '\n'; i++)
        numar = numar * 10 + (s[i] - '0');
    return numar;
}

bool solve(int &rezultat) {
    FILE* fisier = fopen("/Users/victorgrosu/Desktop/Faculta/Sem II/OOP/oop-2022/L1/P2/in.txt", "r");
    if (fisier == NULL) {
        printf("Nu exista fisierul");
        return false;
    }
    char sir[100];
    int suma = 0;
    while (fgets(sir, sizeof(sir), fisier) != NULL) {
        suma += convert(sir);
    }
    fclose(fisier);
    rezultat = suma;
    return true;
}

int main() {
    int rezultat;
    if (solve(rezultat) == true)
        printf("%d", rezultat);
    else
        printf("Eroare");
    return 0;
}