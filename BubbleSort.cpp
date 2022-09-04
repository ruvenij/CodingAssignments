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

    printArray(arr);

    for (int i = 0; i < (arr.size() - 1); i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < (arr.size() - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                isSwapped = true;

                tempToSwap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempToSwap;
            }
        }

        if (not isSwapped)
        {
            break;
        }
    }

    printArray(arr);

    return 0;
}