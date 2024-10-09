#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Lire_ln(FILE *FSource) {
    int count = 0;
    int c;
    while (true) {
        c = fgetc(FSource);
        if (c == EOF) {
            rewind(FSource);
            fseek(FSource, -count, SEEK_END);
            count++;
            break;
        } else if (c == '\n') {
            fseek(FSource, -count - 2, SEEK_CUR);
            break;
        } else {
            count++;
        }
    }
    char *p = calloc(sizeof(char), (count + 1));
    p[count] = '\0';
    for (int i = 0; i < count; i++) p[i] = fgetc(FSource);
    fgetc(FSource);
    return p;
}
long int Fact(int n) {
    long int f = 1;
    for (int i = 1; i <= n; i++) f = f * i;

    return f;
}
int main() {
    FILE *Fsource = fopen("Source.txt", "r");
    FILE *FResult = fopen("Result.txt", "w");
    while (!feof(Fsource)) {
        char *ligne = Lire_ln(Fsource);
        int A = (int)ligne[0] - '0';
        int B = (int)ligne[2] - '0';
        int k = Fact(A) * Fact(B);  // % (A + B);
        if (A <= k && B >= k) {
            char s[100];
            itoa(k, s, 10);
            printf("%s \n", s);
            fputs(s, FResult);
            fputc('\n', FResult);
        }
        free(ligne);
    }

    fclose(Fsource);
    fclose(FResult);
    return 0;
}