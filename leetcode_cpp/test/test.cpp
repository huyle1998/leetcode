//#define test1
//#define test2
//#define cplusplus_com_reference_atomic_atomic_atomic
//#define listing_5_4
//#define listing_9_1
#define volatile_example

#ifdef test1 

#include <iostream>
#include <string>
#include <memory>

class Rectangle {
private:
	uint32_t length;
	uint32_t breadth;

public:
	Rectangle(uint32_t LENGTH, uint32_t BREADTH) :length(LENGTH), breadth(BREADTH) {}
	~Rectangle() {}

	uint32_t area() {
		return length * breadth;
	}
};

int main() {
	Rectangle* rec_ptr0 = new Rectangle(1, 2);
	std::unique_ptr<Rectangle> rec_ptr1 = std::make_unique<Rectangle>(3, 5);
	std::unique_ptr<Rectangle> rec_ptr2(new Rectangle(5, 6));
	std::unique_ptr<Rectangle> rec_ptr3(nullptr);
	rec_ptr3.reset(new Rectangle(6, 7));
	std::unique_ptr<Rectangle> rec_ptr4(std::move(rec_ptr1));
	if (rec_ptr1.get()) {
		std::cout << "Area of rec_ptr1: " << rec_ptr1->area() << std::endl;
	}
	std::shared_ptr<Rectangle> rec_ptr5(rec_ptr0);
	std::shared_ptr<Rectangle> rec_ptr6 = rec_ptr5;
	std::shared_ptr<Rectangle> rec_ptr7 = rec_ptr5;
	std::shared_ptr<Rectangle> rec_ptr8 = rec_ptr5;

	std::cout << "use_count() rec_ptr5 = " << rec_ptr5.use_count() << std::endl;
	std::cout << "use_count() rec_ptr6 = " << rec_ptr6.use_count() << std::endl;
	std::cout << "use_count() rec_ptr7 = " << rec_ptr7.use_count() << std::endl;
	std::cout << "use_count() rec_ptr8 = " << rec_ptr8.use_count() << std::endl;

	return 0;
}

#endif 

#ifdef test2 

#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

std::vector<int> data;
std::atomic<bool> data_ready(false);

void reader_thhread() {
	while (!data_ready.load())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	std::cout << "the answer is " << data[0] << std::endl;
	data_ready = false;
}

void writer_thread() {
	data.push_back(12);
	data_ready = true;
}

int main() {

	return 0;
}

#endif 

#ifdef cplusplus_com_reference_atomic_atomic_atomic

// constructing atomics
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector
#include <chrono>

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int id) {
	while (!ready.load()) {
		std::this_thread::yield();
	}      // wait for the ready signal
	for (volatile int i = 0; i < 256; ++i) {
		std::this_thread::sleep_for(std::chrono::microseconds(1));
	}
	if (!winner.test_and_set()) {
		std::cout << "thread #" << id << " won!\n";
	}
};

int main()
{
	std::vector<std::thread> threads;
	std::cout << "spawning 10 threads that count to 256...\n";
	for (int i = 10; i > 0; i--) {
		threads.push_back(std::thread(count1m, i));
	}
	ready = true;
	for (auto& th : threads) {
		th.join();
	}
	return 0;
}

#endif // cplusplus.com/reference/atomic/atomic/atomic/

#ifdef listing_5_4

#include <atomic>
#include <thread>
#include <assert.h>

std::atomic<bool> x(false), y(false);
std::atomic<int> z(0);

void write_x() {
	x.store(true, std::memory_order_seq_cst);
}

void write_y() {
	y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y() {
	while (!x.load(std::memory_order_seq_cst));
	if (y.load(std::memory_order_seq_cst)) {
		++z;
	}
}

void read_y_then_x() {
	while (!y.load(std::memory_order_seq_cst));
	if (x.load(std::memory_order_seq_cst)) {
		++z;
	}
}

int main() {
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	assert(z.load() != 0);
}

#endif // listing_5_4

#ifdef listing_9_1

#include <thread>
#include <atomic>
#include <functional>
#include <vector>


template<typename T>
class thread_safe_queue
{
public:
	thread_safe_queue();
	~thread_safe_queue();

private:

};

class thread_pool
{
private:
	std::atomic_bool done;
	thread_safe_queue<std::function<void()> > work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;

	void woker_thread() {
		while (!done)
		{
			std::function<void()> task;
			if (work_queue.try_pop(task)) {
				task();
			}
			else {
				std::this_thread::yield();	// take a small break
			}
		}
	}

public:
	thread_pool() :done(false), joiner(threads) {
		uint8_t const thread_count = std::thread::hardware_concurrency();
		try
		{
			for (uint8_t i = 0; i < thread_count; ++i) {
				threads.push_back(std::thread(&thread_pool::woker_thread, this));
			}
		}
		catch (...)
		{
			done = true;
			throw;
		}
	};
	~thread_pool() {
		done = true;
	};

	template <typename funcType>
	void submit(funcType f) {
		work_queue.push(std::function<void()>(f));
	}
};


int main() {

	return 0;
}

#endif // listing_9_1

#ifdef volatile_example

#include <thread>
#include <iostream>
#include <chrono>

#define timeOutSecond 10

void thread1(int* adderess) {
	int* sciReg = adderess;
	int cnt = 0;
	while (true)
	{
		if (*sciReg != 0x00) {
			std::cout << "thread1 reaches non-zero register.\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (++cnt > timeOutSecond) {
			std::cout << "thread 1 is time out, finish task. \n";
			break;
		}
	}
}

void thread2(int* adderess) {
	int* sciReg = adderess;
	int cnt = 0;
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (cnt == 5) {
			*sciReg = 0x1;
		}
		if (++cnt > timeOutSecond) {
			std::cout << "thread 2 is time out, finish task. \n";
			break;
		}
	}
}

int main() {
	int* sciReg = new int(0x0000);
	std::thread T1(thread1, sciReg);
	std::thread T2(thread2, sciReg);
	T1.detach();
	T2.detach();
	std::cin.get();
	return 0;
}

#endif // volatile_example
