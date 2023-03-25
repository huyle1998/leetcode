//#define test1
//#define test2
//#define cplusplus_com_reference_atomic_atomic_atomic
//#define listing_5_4
//#define listing_9_1
//#define volatile_example
//#define function_pointer
#define factory_method_pattern

#ifdef test1 

#include <cctype>
#include <sstream>
#include <iomanip>


bool decode(const char* hexStr, unsigned char* plainData, size_t hexStrLen)
{
	if (!hexStrLen)
		hexStrLen = strlen(hexStr);

	std::stringstream hexStringStream;
	hexStringStream >> std::hex;

	for (size_t hexId = 0, binId = 0; hexId < hexStrLen; ++binId) {

		const char tmpStr[3] = { hexStr[hexId++], hexStr[hexId++], 0 };
		if (!isxdigit(tmpStr[0]) || !isxdigit(tmpStr[1]))
			//return false;
			int a;

		hexStringStream.clear();
		hexStringStream.str(tmpStr);

		int tmpValue = 0;

		hexStringStream >> tmpValue;
		plainData[binId] = static_cast<unsigned char>(tmpValue);
	}

	return true;
}

int main() {
	const char* hexStr = "lequanghuy123";
	unsigned char* plaindata = new unsigned char[strlen(hexStr)]();
	size_t len = 0;
	decode(hexStr, plaindata, len);

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


#ifdef function_pointer

#include <iostream>

typedef enum
{
	RIPE_EVT_BOX_CONNECTED,	//!< Box connection established. Box is not ready to accept any command yet. Wait for RIPE_EVT_BOX_STATIC_UPDATE to start communicating the box
	RIPE_EVT_BOX_DISCONNECTED,				//!< Box lost connection, the SDK will attempt to reestablish communication automatically, unless box disconnect request was not issued by the User using RIPEBoxDisconnect() API
	RIPE_EVT_BOX_STATUS_UPDATE,				//!< Box's dynamic status data available. Use RIPEGetBoxStatusData(..) API to access the data. Period of the event is approximately 2 seconds.
	RIPE_EVT_BOX_BATTLOW,		  			//!< NOT SUPPORTED! Box's battery charge is less than 10%, fired every 2 sec (approx) till the battery is restored 
	RIPE_EVT_BOX_TILTED,		  			//!< NOT SUPPORTED! Box's tilted. Fired every 2 sec, till the tilt is physically adjusted. 
	RIPE_EVT_DATA_TRIGGERDETECTED,			//!< Box detected Trigger/shot, this event will be followed by a series of events such as speed, spin results. Additionally box enters DISARM'ed state and SDK-USER is expected to wait for RIPE_EVT_DATA_SPEEDREADY irrespective of valid or invalid shot.
	RIPE_EVT_DATA_SPEEDREADY,				//!< Speed Result are available, follows a successful trigger event, user can get access to speed & flight model params using relavant RIPEGet APIS. Box maintains the DISARM'ed state and SDK-USER is expected to wait for RIPE_EVT_DATA_SPINREADY irrespective of valid or invalid shot
	RIPE_EVT_DATA_SPINREADY,				//!< Spin Result are available, follows a successful speed event, user can get access to spin data & flight model params using relavant RIPEGet APIS. Box maintains DISARM'ed state, which can be released here or later from this point by issuing RIPE_CMD_ARM command. 
	RIPE_EVT_DATA_USERPERSISTENTDATA_READY,	//!< Custom Data read from Box's non-volatile memory is available, user can get access to data using RIPEBoxGetUserPersistentData(..) API
	RIPE_EVT_FW_UPGRADE_AVAILABLE,          //!< Firmware Upgrade is available, event triggered only during the initial connection following a cold boot of the Box and APP is expected to start FirmwareUpgrade process issuing RIPE_CMD_UPGRADE_FIRMWARE box command
	RIPE_EVT_FW_SDK_INCOMPATIBLE,			//!< Upgrade is mandatetory for proper functioning of the Box. Without upgrade any following command/request to box would fail
	RIPE_EVT_FW_SDK_CUSTOMERCODE_INCOMPATIBLE, //!< SDK & Box's customer code mismatch, any following command/request to box would fail
	RIPE_EVT_FW_UPGRADE_SUCCESS, 			//!< Firmware Upgrade was successful, box will now try to restart automatically 
	RIPE_EVT_FW_UPGRADE_ERROR,				//!< Firmware Upgrade failed, upgrade fails due to connection or other data transfer errors, Box will revert back to its current firmware version
	RIPE_EVT_COMM_DISCOVER_UPDATE,			//!< Ready with list of boxes found (found network+USB adapters). Use RIPEGetDiscoveredBoxList(..) API to access the box lists
	RIPE_EVT_BOX_STATIC_UPDATE,				//!< Box's static data available. Use RIPEGetBoxStaticData(..) API to access the data. Event is fired only once after Box connection. From this point in time, box is ready to accept command issued using RIPESendBoxCommand(..) API, for example issuing RIPE_CMD_ARM command to prepare the box to take shots.
	RIPE_EVT_BOX_ERROR,						//!< Box entered ERROR state. Possible reasons, box data corrupted, which is a irrecoverable state.
	RIPE_EVT_NETWORK_SCAN_LIST_UPDATE,		//!< Ready with list of wifi access points seen by the connected box,  Use RIPEGetNetworkScanList(..) API to access the box lists
	RIPE_EVT_BIT_RESERVED_2,				//!< RESERVED
	RIPE_EVT_BIT_RESERVED_3,				//!< RESERVED
	RIPE_EVT_BIT_RESERVED_4,				//!< RESERVED	
	RIPE_EVT_LAST							//!< RESERVED
}RIPEEventType;

void callbackTask(void* HANDLE, RIPEEventType EVT);

struct RIPEInitType {
	void* handle;
	void (*callback)(void* handle, RIPEEventType latestEvent);
	void (*callback2)(void*, RIPEEventType);
	char dataFolderPath[2048];
};


int main() {
	RIPEInitType x1;
	void* hnd1 = (void*) 0x1;
	void* hnd2 = (void*) 0x2;

	RIPEEventType e1 = RIPE_EVT_BOX_BATTLOW;
	RIPEEventType e2 = RIPE_EVT_BOX_DISCONNECTED;

	x1.callback = callbackTask;
	x1.callback2 = callbackTask;

	x1.callback(hnd1, e1);
	x1.callback2(hnd2, e2);

	return 0;
}


void callbackTask(void* HANDLE, RIPEEventType EVT) {
	std::cout << "HANLDE \t= " << (int)HANDLE << std::endl;
	std::cout << "EVT \t= " << EVT << std::endl;
}

#endif // function_pointer

#ifdef factory_method_pattern

#include <iostream>

class Product {
public:
	virtual void use() = 0;
};

class ProductA : public Product {
public:
	void use() override {
		std::cout << "Using ProductA" << std::endl;
	}
};

class ProductB : public Product {
public:
	void use() override {
		std::cout << "Using ProductB" << std::endl;
	}
};

class Creator {
public:
	virtual Product* create_product() = 0;
};

class CreatorA : public Creator {
public:
	Product* create_product() override {
		return new ProductA();
	}
};

class CreatorB : public Creator {
public:
	Product* create_product() override {
		return new ProductB();
	}
};


int main() {
	Creator* creator(nullptr);
	Product* product(nullptr);

	creator = new CreatorA();
	product = creator->create_product();
	product->use();

	delete creator, product;
	creator = nullptr;
	product = nullptr;


	creator = new CreatorB();
	product = creator->create_product();
	product->use();
	
	delete creator, product;
	creator = nullptr;
	product = nullptr;

	return 0;
}

#endif // factory_method_pattern
