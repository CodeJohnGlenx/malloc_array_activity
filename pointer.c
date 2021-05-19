#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sort.c"

int binary_search(int search, int *array, int array_length)
{
    int left = 0, right = array_length - 1, mid = (left + right) / 2;
    for(;left <= right; mid = (left + right) / 2)
        if (search == *(array + mid))
            return mid;
        else if (search < *(array + mid))
            right = mid - 1;
        else if (search > *(array + mid))
            left = mid + 1;
    return -1;
}

void main()
{
    int size, *x, i, value, found;
    char try_again;
    printf(">>\n");
    printf("How many values you want to enter? ");
    scanf("%d", &size);
    x = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        printf("Enter value for (x + %d): ", i);
        scanf("%d", (x + i));
    }

    insertion_sort(x, size);

    input:
        printf("\n\nEnter Key: ");
        scanf("%d", &value);

    printf("\n");
    found = binary_search(value, x, size);
    for (i = 0; i < size; i++)
        printf("(x + %d): %d\n", i, *(x + i));
    if (found != -1)
        printf("\n%d is located at (x + %d)", value, found);
    else
        printf("\n%d is not found", value);

    printf("\n\nDo you want to enter key again (y/n)? ");
    scanf(" %c", &try_again);

    if (tolower(try_again) == 'y')
        goto input;

    printf("\n<<");
}
