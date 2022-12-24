#include <iostream>
#include <queue>

#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>


std::condition_variable data_ready_event;
std::mutex data_mutex;
std::queue<int> data_queue;


void prepare_data_thread() {
    for (int i = 0; i < 10; i++) {
        //std::lock_guard<std::mutex> lk(data_mutex);
        data_mutex.lock();
        data_queue.push(i);
        data_mutex.unlock();
        std::cout << "\npushed " << i << " into data_queue \n";
        data_ready_event.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


void process_data_thread() {
    while (true) {
        std::unique_lock<std::mutex> lk(data_mutex);
        data_ready_event.wait(lk, []{return !data_queue.empty();});
        std::cout << "processing data i = " << data_queue.front() << std::endl;
        data_queue.pop();
        lk.unlock();
    }
}


int main()
{
    std::thread prepare_woker(prepare_data_thread);
    std::thread process_worker(process_data_thread);
    prepare_woker.detach();
    process_worker.detach();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}
