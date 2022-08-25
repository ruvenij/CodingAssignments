#include <bits/stdc++.h>

void printHelloWorld(int index, const std::string& value)
{
    std::cout << "Printing values : " << index << " = " << value << std::endl;
}

int main()
{
    int threadCount = 5;
    std::vector<std::thread> threadsContainer;

    for (int i = 0; i < threadCount; i++)
    {
        std::string val = "Thread : " + std::to_string(i);
        threadsContainer.push_back(std::thread(printHelloWorld, i, val));
    }

    for (auto& th : threadsContainer)
    {
        th.join();
    }

    return 0;
}