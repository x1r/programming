#include <iostream>

void shellSort(int *array, int size)
{
    int step = size / 2;
    while (step > 0)
    {
        for (int i = 0; i < (size - step); i++)
        {
            int j = i;
            while (j >= 0 && array[j] > array[j + step])
            {
                std::swap(array[j], array[j + step]);
                j--;
            }
        }
        step = step / 2;
    }
}

void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        int *tmpArray = new int[right - left + 1];
        int firstIndex = left;
        int secondIndex = middle + 1;
        int index = 0;
        while (firstIndex <= middle && secondIndex <= right)
        {
            if (array[firstIndex] < array[secondIndex])
            {
                tmpArray[index] = array[firstIndex];
                firstIndex++;
            }
            else
            {
                tmpArray[index] = array[secondIndex];
                secondIndex++;
            }
            index++;
        }
        while (firstIndex <= middle)
        {
            tmpArray[index] = array[firstIndex];
            firstIndex++;
            index++;
        }
        while (secondIndex <= right)
        {
            tmpArray[index] = array[secondIndex];
            secondIndex++;
            index++;
        }
        for (int i = 0; i < index; i++)
        {
            array[left + i] = tmpArray[i];
        }
        delete[] tmpArray;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array1[10] = {123, 1223, 324, 534, 6756, 45, 354, 23456, 356, 64};
    printf("Before sorting: ");
    printArray(array1, 10);
    mergeSort(array1, 0, 9);
    printf("After sorting:  ");
    printArray(array1, 10);
    int array2[10] = {123, 1223, 324, 534, 6756, 45, 354, 23456, 356, 64};
    printf("Before sorting: ");
    printArray(array2, 10);
    shellSort(array2, 10);
    printf("After sorting:  ");
    printArray(array2, 10);
    return 0;
}