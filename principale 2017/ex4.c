//!! not tested at all

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
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
        } else
            count++;
    }
    char *p = calloc(sizeof(char), (count + 1));
    p[count] = '\0';
    for (int i = 0; i < count; i++) p[i] = fgetc(FSource);
    fgetc(FSource);
    return p;
}

void afficher(int *M[100][10], char *TM[10][100], int N, int nl) {
    for (int j = 1; j <= N; j++) {
        printf(" %c :", TM[j]);
        FILE *F = fopen("Chemin.txt", "r+");
        for (int i = 0; i <= nl; i++) {
            char *ch = Lire_ln(F);
            if (M[i][j] > 0) printf("%s \n", ch);
        }

        fclose(F);
    }
}

void Remplir(char *TM[10][100], int N) {
    while (true) {
        printf("donner le nombre de mots a chercher");
        int N;
        scanf("%d", &N);
        if (N >= 1 && N <= 10) {
            break;
        }
    };
    for (int i = 0; i <= N; i++) {
        char ch[100];
        while (true) {
            printf("donner le mot N %d :", i);
            scanf("%s", &ch);
            if (strlen(TM[i]) > 0 && Alpha(TM[i])) break;
        }
        strcpy(TM[i], ch);
    }
}
bool Alpha(char ch[]) {
    int i = 0;
    while (true) {
        i++;
        if (!(isalpha(strupr(ch[i])) || (i == strlen(ch)))) break;
    }
}
void FormerMatrice(int M[100][10], char TM[10][100], int N, int nl, FILE *F) {
    rewind(F);
    while (feof(F)) {
        char* Ch;
        //? associer ???
        nl ++;
        for (int i = 0; i < N; i++)
        {
            //??
            int nb = 0;
            
        }
        
    }
};

int main() {
    char TM[10][100] = {"one", "two",   "three", "four", "five",
                        "six", "seven", "eight", "nine", "ten"};
    int Matrice[100][10];

    FILE *F = fopen("Chemin.txt", "r+");

    fclose(F);
    return 0;
}