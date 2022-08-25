#include <bits/stdc++.h>
#include <shared_mutex>
#include <thread>
#include <chrono>

class ReadWriteContainer
{

public:
    void readBlock()
    {
        std::shared_lock shLock(lock);
        std::cout << "Reading : " << count << std::endl;
    }

    void writeBlock()
    {
        std::unique_lock unLock(lock);
        count++;
        std::cout << "Writing : " << count << std::endl;
    }

private:
    std::shared_mutex lock;
    int count = 0;
};

void readThreadFun(ReadWriteContainer* rw)
{
    while(true)
    {
        rw->readBlock();
        std::cout << "Reader thread sleeping ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void writeThreadFun(ReadWriteContainer* rw)
{
    while(true)
    {
        rw->writeBlock();
        std::cout << "Writer thread sleeping ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    ReadWriteContainer* rw = new ReadWriteContainer();
    std::thread p1(readThreadFun, rw);
    std::thread p2(writeThreadFun, rw);
    p1.join();
    p2.join();
    return 0;
}