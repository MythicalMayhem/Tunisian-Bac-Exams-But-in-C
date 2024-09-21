#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
char *Lire_Ligne(FILE *f, char **p) {
    int c;
    int count = 0;
    for (;;) {
        c = fgetc(f);
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            count++;
            break;
        }
        ++count;
    }
    char *s = malloc(sizeof(char) * count);
    if (feof(f)) {
        rewind(f);
        fseek(f, -count, SEEK_END);
        count++;
    } else {
        fseek(f, -count - 1, SEEK_CUR);
    }
    fgets(s, sizeof(char) * count, f);
    getc(f);  // for the \n
 
    *p = s;
    return s;
}

void main() {
    FILE *Finv = fopen("Invites.txt", "r");

    while (!feof(Finv)) {
        char *ret;
        Lire_Ligne(Finv, &ret);
        printf("%s \n", ret);
        free(ret);
        // getLine(Finv, s, lineLength);
    }
    // for last line

    // getLine(Finv, s, lineLength);
    fclose(Finv);
}

// * if file pointer exceeds EOF things start buggin