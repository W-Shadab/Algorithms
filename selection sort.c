#include <stdio.h>
#include <conio.h>

void main()
{
int a[50], n, i, j, temp, min;

clrscr();

printf("Enter Number of Elements: ");
scanf("%d", &n);

printf("Enter Your Array: ");

for (i=0; i<n; i++)
{
	scanf("%d", &a[i]);
}

for (i=0; i<n-1; i++)
{
	min = i;


	for (j=i+1; j<n; j++)
	{
		if (a[j] < a[min])
		
		min = j;
	}

temp = a[i];
a[i] = a[min];
a[min] = temp;
}
printf("Sorted Array: ");

for(i=0; i<n; i++)
{
    printf("%d ", a[i]);
}
getch();

}
