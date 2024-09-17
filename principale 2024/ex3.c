#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double Puiss(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return a * Puiss(a, n - 1);
}

//  double res = RacineN(2, 3); //    1.259921
double RacineN(int M, int n)
{
    double X = (double)M / (double)2;
    while (true)
    {
        double Xpred = X;
        double first = (double)1 / (double)n;
        double second = (double)(n - 1) * (double)X;
        double third = (double)M / Puiss(Xpred, n - 1);
        X = first * (second + third);
        if (fabs(Xpred - X) <= 0.0001)
        {
            break;
        }
    }
    return X;
}
// int d = Facteur(1000); //5
int Facteur(int M)
{
    int d = 2;
    while (true)
    {
        if (M % d == 0)
        {
            M = (int)((float)M / (float)d);
            printf("%d \n", M);
        }
        else
        {
            d++;
        }
        if (M == 1)
        {
            break;
        }
    }
    return d;
}

int NRond(int M)
{
    int P = Facteur(M);
    int N = 1;
    while (P <= RacineN(M, N + 1))
    {
        printf("%lf \n", RacineN(M, N));
        N++;
    }
    if (N == 1)
    {
        return -1;
    }
    return N;
}
void main()
{
    printf("%d", NRond(432)); // 5
    printf("%d", NRond(21));  //-1
}