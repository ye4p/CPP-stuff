#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

static int count = 0;
std::mutex ctr_mutex;
void inc()
{
    for (int i = 0; i < 2'000'000; i++)
    {
        count++;
    }
}

void inc_par()
{
    ctr_mutex.lock();
    for (int i = 0; i < 1'000'000; i++)
    {
        count++;
    }
    ctr_mutex.unlock();
}

int main()
{

    auto start = std::chrono::steady_clock::now();
    // std::thread t1(inc_par);
    // std::thread t2(inc_par);

    // t1.join();
    // t2.join();

    inc();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "counter: " << count << " time took: " << elapsed.count() << "ms\n";
    return 0;
}