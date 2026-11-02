#include <stdio.h>
#include <conio.h>

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[high];
    i = low-1;

    for(j=low; j<high; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i+1;
}

void quickSort(int a[], int low, int high)
{
    int pi;

    if(low < high)
    {
        pi = partition(a, low, high);

        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

void main()
{
    int a[50], n, i;

    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n-1);

    printf("Sorted array: ");

    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }

    getch();
}