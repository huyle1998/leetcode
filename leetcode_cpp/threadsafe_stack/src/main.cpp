#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <stack>
#include <exception>
#include <new>


struct empty_stack : std::exception {
	const char* what() const throw();
};


template<typename T>
class threadsafe_stack {

private:
	std::stack<T> _data_stack;
	mutable std::mutex _mutex;

public:
	threadsafe_stack() = default;
	threadsafe_stack(const threadsafe_stack& other) {
		std::lock_guard<std::mutex> lk(other._mutex);
		_data_stack = other._data_stack;
	}
	threadsafe_stack& operator = (const threadsafe_stack&) = delete;

	void push(T& data) {
		std::lock_guard<std::mutex> lk(_mutex);
		_data_stack.push(std::move(data));
	}

	std::shared_ptr<T> pop() {
		std::lock_guard<std::mutex> lk(_mutex);
		if (_data_stack.empty()) {
			throw empty_stack();
		}
		std::shared_ptr<T> const res(std::make_shared<T>(std::move(_data_stack.top())));
		_data_stack.pop();
		return res;
	}

	void pop(T& value) {
		std::lock_guard<std::mutex> lk(_mutex);
		if (_data_stack.empty()) {
			throw empty_stack();
		}
		value = std::move(_data_stack.top());
		_data_stack.pop();
	}

	bool empty() const {
		std::lock_guard<std::mutex> lk(_mutex);
		return _data_stack.empty();
	}
};


int main() {
	std::nothrow_t n;

	int* p = new int();
	delete p;

	return 0;
}