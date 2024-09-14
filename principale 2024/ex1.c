#include <stdio.h>
#include <stdbool.h>

bool inconnue(int n)
{
    int d = 2;
    while (n % d != 0 && d <= n / 2)
    {
        d++;
    };
    return d > (int)(n / 2);
};

int main()
{

    for (int j = 2; j < 1200; j++)
    {
        const bool res = inconnue(j);
        if (res)
        {
            printf(" %d\n", j);
        }
    };
    return 0;
}
