#include <stdio.h>
#include <stdbool.h>

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
        bool isNum = search("0123456789", ch[i]) != -1;
        int code = ch[i];
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

char *Extraire_Tab_Ch(int T[], int N)
{
    char ch[N];

    for (int i = 0; i < N; i++)
    {
        ch[i] = T[i] + 48;
    }
    ch[N] = '\0';
    return ch;
}

void main()
{

    int T[] = {0, 1, 0, 1, 0, 1, 0, 1};
    char ch[] = Extraire_Tab_Ch(T, sizeof(T) / sizeof(T[0]));
    printf("%s", ch);
    // convb10(ch, b);
}
