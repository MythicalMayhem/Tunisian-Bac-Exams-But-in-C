#include <stdio.h>
#include <stdbool.h>

void sous_chaine(char parent[], char child[], int from, int length)
{
    for (int i = 0; i < length; i++)
    {
        child[from + i] = parent[from + i];
    }
}

int search(char *haystack, char needle)
{
    int i = 0;
    int size = sizeof(haystack) / sizeof(haystack[0]);
    while (i < size)
    {
        if (haystack[i] == needle)
        {
            return i;
        }
        i++;
    }

    return -1;
}

int convb10(char *ch, int b)
{
    int s = 0;
    int p = 1;
    for (int i = sizeof(ch) / sizeof(ch[0]) - 1; i > -1; i--)
    {
        int code = ch[i];
        bool isNum = search("0123456789", ch[i]) != -1;
        printf("%d %c \n", code, ch[i]);
        if (isNum)
        {
            s = s + (code - 48) * p;
        }
        else
        {
            s = s + (code - 55) * p;
        }
        p = p * b;
    }
    return s;
}

bool verifSaisie(int T[], int N)
{
    int i = 0;
    bool test = true;
    while (true)
    {
        if ((T[i] != 0) && (T[i] != 1))
        {
            test = false;
        }
        i++;
        if ((!test) || (i == N - 1))
        {
            break;
        }
    }

    return test;
}
void Extraire_Tab_Ch(char ch[], int T[], int N)
{
    for (int i = 0; i < N; i++)
    {
        ch[i] = T[i] + 48;
    }
    ch[N] = '\0';
}

// ! this is untested (unlike the other functions 
bool verif(int T[], int N)
{
    if ((N % 10 != 0) || !(verifSaisie(T, N)))
    {
        return false;
    }
    else
    {
        char ch[N];
        Extraire_Tab_Ch(ch, T, N);
        short j = 0;
        while (true)
        {
            char ch1[7];
            sous_chaine(ch, ch1, 1 + j, 7);
            int conved = convb10(ch1, 2);
            //* got no idea what this thing does i just translated the bih from the pdf got no sweat to think about it again lol
            bool test = ((ch[0 + j] == '0') && (ch[7 + j] == '9') && (conved <= 90) && (conved >= 65));
            if ((j == N) || !test)
            {
                return test;
            }
        }
    }
}
void main()
{
    int T[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; //...?
    int N = sizeof(T) / sizeof(T[0]);
    verif(T, N);
    printf("g  %d", verif(T, N));
}
