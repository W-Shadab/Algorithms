#include <stdio.h>
#include <conio.h>

void main()

{

int weight[10], profit[10];
float ratio[10], capacity, totalProfit = 0;
int n, i, j, temp;
float tempRatio;
clrscr();

printf("Enter Number of items: ");
scanf("%d" , &n);

printf("Enter Total Capacity: ");
scanf("%f" , &capacity);

for(i = 0; i < n; i++)
    {
        printf("Enter weight, and profit: ");
        scanf(" %d %d",
              &weight[i], &profit[i]);

    }


for(i = 0; i < n; i++)
{
    ratio[i] = (float)profit[i] / weight[i];
}

for(i = 0; i < n-1; i++)
{
    for(j = i+1; j < n; j++)
    {
        if(ratio[i] < ratio[j])
        {
            /* Swap ratio */
		tempRatio = ratio[i];
		ratio[i] = ratio[j];
		ratio[j] = tempRatio;

            /* Swap weight */
		temp = weight[i];
		weight[i] = weight[j];
		weight[j] = temp;

            /* Swap profit */
		temp = profit[i];
		profit[i] = profit[j];
		profit[j] = temp;
        }
    }
}

for(i = 0; i < n; i++)
{
    if(weight[i] <= capacity)
    {
        totalProfit += profit[i];
        capacity -= weight[i];
    }
    else
    {
        totalProfit += profit[i] * capacity / weight[i];
        break;
    }
}

printf("Maximum Profit = %f", totalProfit);

getch();
}