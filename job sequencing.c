#include <stdio.h>
#include <conio.h>

void main()
{
    char job[10], tempJob;
    int deadline[10], profit[10], slot[10];
    int n, i, j, max = 0, temp;
    int totalProfit = 0;

    clrscr();

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter job, deadline and profit: ");
        scanf(" %c %d %d",
              &job[i], &deadline[i], &profit[i]);

        if(deadline[i] > max)
            max = deadline[i];
    }

    /* Sort jobs by descending profit */
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(profit[i] < profit[j])
            {
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                tempJob = job[i];
                job[i] = job[j];
                job[j] = tempJob;
            }
        }
    }

    /* Initialize slots */
    for(i = 0; i < max; i++)
    {
        slot[i] = -1;
    }

    /* Assign jobs to slots */
    for(i = 0; i < n; i++)
    {
        for(j = deadline[i]-1; j >= 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                break;
            }
        }
    }

    /* Calculate total profit */
    printf("\nSelected Jobs: ");

    for(i = 0; i < max; i++)
    {
        if(slot[i] != -1)
        {
            printf("%c ", job[slot[i]]);
            totalProfit += profit[slot[i]];
        }
    }

    printf("\nTotal Profit = %d", totalProfit);

    getch();
}