#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Inv {
    char *nom;
    int score;
};

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

bool Triangulaire(int Nb) {
    int N = 1;
    while (N * (N + 1) / 2 < Nb) N++;
    return (N * (N + 1) / 2 == Nb);
};
int Calcul_Score(char *ch) {
    int s = 0;
    for (; *ch != '\0'; ch++) s = s + (int)*ch - 64;
    return s;
}

int Max_Score(struct Inv T[], int N) {
    int Max = T[0].score;
    for (int i = 0; i < N; i++)
        if (T[i].score > Max) Max = T[i].score;
    return Max;
};
void Affice_Gangnats(struct Inv T[], int N) {
    int Max = Max_Score(T, N);
    for (int i = 0; i < N; i++)
        if (T[i].score = Max) printf("le gangnat est %s", T[i].nom);
}
void TransfertNoms(struct Inv T[], int N) {
    FILE *Finv = fopen("Invites.txt", "r");
    while (!feof(Finv)) {
        char *ret;
        Lire_Ligne(Finv, &ret);
        printf("%d ", strlen(ret));

        struct Inv E;
        E.nom = ret;
        E.score = Calcul_Score(E.nom);

        if (Triangulaire(E.score)) {
        }

        printf("%s \n", E.nom, E.score);
        free(ret);
    }
    fclose(Finv);
}

// * if file pointer exceeds EOF things start buggin