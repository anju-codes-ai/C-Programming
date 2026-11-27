
#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int largest, second;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    second = -999999;

    for(i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    if(second == -999999)
    {
        printf("Second largest element does not exist");
    }
    else
    {
        printf("Second largest element = %d", second);
    }

    return 0;
}
