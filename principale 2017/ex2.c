#include <stdio.h>
#include <stdlib.h>
char *Nom(double x, int n) {
    char *p = calloc(n, sizeof(char));
    for (int i = 1; i < n + 1; i++) {
        x = x * 2;
        if (x < 1) {
            p[i] = '0';
        } else {
            p[i] = '1';
            x--;
        }
    }
    return p;
}

int main() {
    double x = 0.2;
    int n = 20;
    char *res = Nom(x, n);
    res[n + 1] = '\0';
    res[0] = ' ';
    printf("\n res = %s", res);
    return 0;
}