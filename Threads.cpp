#include <bits/stdc++.h>
#include <pthread.h>

constexpr int32_t ThreadCount = 5;

void* printHelloWorld(void* number)
{
    intptr_t threadIndex = (intptr_t) number;
    std::cout << "Hello World with thread : " << threadIndex << std::endl;
    pthread_exit((void*)0);
    return (void*)0;
}

int main()
{
    pthread_t threadContainer[ThreadCount];

    for (int i = 0; i < ThreadCount; i++)
    {
        intptr_t index = i;
        int ret = pthread_create(&threadContainer[i], nullptr, printHelloWorld, (void*)index);
        std::cout << "Ret : " << ret << std::endl;
    }
    
    return 0;
}