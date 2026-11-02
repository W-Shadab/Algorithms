#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int x[20], n;

int place(int k)
{
    int i;

    for(i = 1; i < k; i++)
    {
        if(x[i] == x[k] ||
           abs(x[i] - x[k]) == abs(i - k))
        {
            return 0;
        }
    }

    return 1;
}

void nqueen(int k)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        x[k] = i;

        if(place(k))
        {
            if(k == n)
            {
                for(i = 1; i <= n; i++)
                    printf("Q%d (Row %d, Column %d)\n", i, i, x[i]);

                printf("\n");
            }
            else
            {
                nqueen(k + 1);
            }
        }
    }
}

void main()
{
    clrscr();

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if(n < 1 || n > 19)
    {
        printf("Invalid number of queens");
        getch();
        return;
    }

    nqueen(1);

    getch();
}