#include <stdio.h>
#include <conio.h>

void main()
{
    int a[50], n, i, key;
    int low, high, mid, found = 0;

    clrscr();

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter the sorted Array: ");

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low+high)/2;

        if(a[mid] == key)
        {
            printf("Element Found at index %d", mid);
            found = 1;
            break;
        }
        else if(a[mid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    if(found == 0)
    {
        printf("Element not found");
    }

    getch();
}