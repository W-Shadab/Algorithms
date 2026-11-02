#include <stdio.h>
#include <conio.h>

int a[20], x[20], n, target;

void printSubset()
{
    int i;

    printf("{ ");

    for(i = 0; i < n; i++)
    {
        if(x[i] == 1)
            printf("%d ", a[i]);
    }

    printf("}\n");
}

void sumofsubsets(int k, int sum)
{
    if(sum == target)
    {
        printSubset();
        return;
    }

    if(k == n || sum > target)
        return;

    x[k] = 1;
    sumofsubsets(k + 1, sum + a[k]);

    x[k] = 0;
    sumofsubsets(k + 1, sum);
}

void main()
{
    int i;

    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets are:\n");

    sumofsubsets(0, 0);

    getch();
}