#include <bits/stdc++.h>

void printArray(const std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " -> ";
    }

    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int start, int end)
{
    int pivot = arr[end];
    int currentIndex = start;
    int tempToSwap;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            if (i == currentIndex) continue;

            std::cout << "Pivot : " << pivot << " Swap " << arr[currentIndex] << " with " << arr[i] << std::endl;
            tempToSwap = arr[currentIndex];
            arr[currentIndex] = arr[i];
            arr[i] = tempToSwap;
            currentIndex++;
        }
    }

    std::cout << currentIndex << " Swap " << arr[currentIndex] << " with " << arr[end] << std::endl;
    tempToSwap = arr[currentIndex];
    arr[currentIndex] = arr[end];
    arr[end] = tempToSwap;

    return currentIndex;
}

void quickSort(std::vector<int>& arr, int start, int end)
{
    if (start >= end) 
        return;

    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main()
{
    std::vector<int> arr = {4, 7, 3, 8, 1, 9, 3};
    printArray(arr);

    quickSort(arr, 0, 6);

    printArray(arr);

    return 0;
}