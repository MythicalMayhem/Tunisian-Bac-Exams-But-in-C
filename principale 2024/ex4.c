#include <ctype.h>
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
int Calcul_Score(char *ch) {  // Saber -> 45
    int s = 0;
    char *k = ch;
    for (; *k != '\0'; k++) {
        s = s + (int)(toupper((char)*k)) - 64;
    }
    printf("name  = %s ", ch);
    printf("score = %d  \n", s);
    return s;
}

int Max_Score(struct Inv T[], int N) {
    int Max = T[0].score;
    for (int i = 0; i < N; i++)
        if (T[i].score > Max) Max = T[i].score;
    return Max;
};
void Affiche_Gangnats(struct Inv T[], int N) {
    int Max = Max_Score(T, N);
    for (int i = 0; i < N; i++)
        if (T[i].score == Max) printf("le gangnat est %s", T[i].nom);
}
void TransfertNoms(struct Inv T[], int *N) {
    FILE *Finv = fopen("Invites.txt", "r");
    FILE *Ftr = fopen("Triangulaire.dat", "wb");
    *N = 0;

    while (!feof(Finv)) {
        struct Inv E;
        Lire_Ligne(Finv, &E.nom);
        E.score = Calcul_Score(E.nom);
        if (Triangulaire(E.score)) {
            T[*N] = E;
            fwrite(&E, sizeof(E), 1, Ftr);
            *N = *N + 1;
        }
    }
    fclose(Ftr);
    fclose(Finv);
}
void main() {
    struct Inv T[50];
    int N = 0;
    TransfertNoms(T, &N);
    Affiche_Gangnats(T, N);
}

// pass an adress as a pointer -> it becomes a pointer