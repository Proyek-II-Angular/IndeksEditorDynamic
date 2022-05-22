#include <iostream>
#include <stdio.h>

using namespace std;

void Find(char c[], int counter, list Text)
{
    addr P;
    int i = 0,
        cocok = 0;
    P = first(Text);
    char arr[3] = {'d', 'a', 'n'};
    if (P == Nil)
    {
        printf("Text Tidak DItemukan!");
    }
    else
    {
        while (P != Nil)
        {
            if (info(P) == c[i])
            {
                i++;
                cocok++;
                printf("Ditemukan = %c\n", info(P));
                if (cocok == counter)
                {
                    P = next(P);
                    for (int j = 0; j < counter; j++)
                    {
                        delbe(&Text, P);
                    }
                    P = prev(P);
                    for (int k = 0; k < 3; k++)
                    {
                        insaf(&Text, arr[k], P);
                        P = next(P);
                    }
                }
            }
            else
            {
                i = 0;
                cocok = 0;
            }
            P = next(P);
        }
    }
}

int main()
{
    list L;
    addr P;

    crlt(&L);
    char arr[3] = {'d', 'a', 'n'};
    insfi(&L, 'd');
    insla(&L, 'a');
    insla(&L, 'n');
    insla(&L, 'h');
    insla(&L, 'i');
    insla(&L, 'n');
    insla(&L, 'g');
    insla(&L, 'a');
    insla(&L, 'p');

    P = first(L);
    P = next(P);
    cout << endl;
    printli(L);
    cout << endl;
    Find(arr, 6, L);
    printli(L);
    return 0;
}
