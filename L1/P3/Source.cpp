#include <cstdio>
#include <cstring>
#include <algorithm>

void readWords(char *s) {
    scanf("%[^\n]s", s);
}

void printWords(char s[][256], int n) {
    for(int i = 1; i <= n; i++) {
        printf("%s \n", s[i]);
    }
}

void sortWords(char *s) {
    char word[10][256], *p;
    int n = 0;
    p = strtok(s, " ");
    while(p) {
        n++;
        strcpy(word[n], p);
        p = strtok(NULL, " ");
    }
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(strlen(word[i]) < strlen(word[j])) {
                std::swap(word[i], word[j]);
            } else if(strlen(word[i]) == strlen(word[j])) {
                if(strcmp(word[i], word[j]) > 0) {
                    std::swap(word[i], word[j]);
                }
            }
        }
    }
    printWords(word, n);
}

int main () {
    int n;
    char s[256];
    readWords(s);
    sortWords(s);
    return 0;
}