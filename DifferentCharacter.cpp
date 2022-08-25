#include <bits/stdc++.h>

int getXorValue(const std::string& word)
{
    int xorValue = word[0];
    for (int i = 1; i < word.size(); i++)
    {
        xorValue ^= word[i];
    }

    return xorValue;
}

int getAsciiSum(const std::string& word)
{
    int sum = 0;
    for (int i = 0; i < word.size(); i++)
    {
        sum += word[i];
    }

    return sum;
}

int main()
{   
    int firstValue = getXorValue("abc");
    int secondValue = getXorValue("bdca");

    char differentChar = firstValue ^ secondValue;

    std::cout << differentChar << std::endl;

    int firstSum = getAsciiSum("abc");
    int secondSum = getAsciiSum("bdca");

    differentChar = secondSum - firstSum;

    std::cout << differentChar << std::endl;

    return 0;
}