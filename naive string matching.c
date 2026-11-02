#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char text[100], pattern[50];
    int i, j, n, m, found = 0;

    clrscr();

    printf("Enter text: ");
    gets(text);

    printf("Enter pattern: ");
    gets(pattern);

    n = strlen(text);
    m = strlen(pattern);

    for(i = 0; i <= n-m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(text[i+j] != pattern[j])
                break;
        }

        if(j == m)
        {
            printf("Pattern found at index %d", i);
            found = 1;
        }
    }

    if(found == 0)
        printf("Pattern not found");

    getch();
}