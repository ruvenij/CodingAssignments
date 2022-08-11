#include <bits/stdc++.h>

void printHelloWorld(int index, const std::string& value)
{
    std::cout << "Printing values : " << index << " = " << value << std::endl;
}

int main()
{
    std::thread newThread(printHelloWorld, 0, "Ruveni");
    newThread.join();
    return 0;
}