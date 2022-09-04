#include <bits/stdc++.h>

void printArray(const std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " -> ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {4, 7, 3, 8, 1, 9, 3};
    int tempToSwap;
    int minPos;

    printArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        minPos = i;
        
        for (int j = (i + 1); j < arr.size(); j++)
        {
            if (arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }

        tempToSwap = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = tempToSwap;
    }

    printArray(arr);

    return 0;
}