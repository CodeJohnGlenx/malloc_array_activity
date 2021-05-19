void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void insertion_sort(int *array, int array_length)
{
    for (int i = 0; i < array_length; i++)
        for(int j = i; j > 0; j--)
            if (*(array + j) < *(array + j - 1))
                swap((array + j), (array + j - 1));
            else
                break;
}
