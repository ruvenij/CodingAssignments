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
    int holeToFill;

    printArray(arr);

    for (int i = 1; i < arr.size(); i++)
    {
        tempToSwap = arr[i];
        holeToFill = i;
        
        for (int j = (i - 1); j >= 0; j--)
        {
            if (arr[j] > tempToSwap)
            {
                arr[j + 1] = arr[j];
                holeToFill = j;
            }
        }

        arr[holeToFill] = tempToSwap;
    }

    printArray(arr);

    return 0;
}