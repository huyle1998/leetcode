#include <iostream>


template <typename T>
class Node {

private:
	T value;
	Node* next;

public:
	Node()
	{
		next = NULL;
	}
	void set_value(T value)
	{
		this->value = value;
	}
	void set_next(Node* next)
	{
		this->next = next;
	}
	T get_value()
	{
		return this->value;
	}
	Node* get_next()
	{
		return this->next;
	}
};

template <typename T>
class Stack
{

private:
	Node<T>* head;
	Node<T>* temp;
	unsigned int m_size;

public:
	Stack()
	{
		head = NULL;
		temp = NULL;
		m_size = 0;
	}
	~Stack()
	{
		delete_stack();
	}
	void push(T element)		// big-o = O(1)
	{
		if (head == NULL)
		{
			head = new Node<T>;
			head->set_next(NULL);
		}
		else
		{
			temp = new Node<T>;
			temp->set_next(head);
			head = temp;
		}
		head->set_value(element);
		m_size++;
	}
	void pop()				// big-o = O(1)
	{
		if (!is_empty())
		{
			temp = head;
			head = head->get_next();
			delete temp;
			temp = NULL;
			m_size--;
		}
		else
		{
			std::cout << "The stack is empty." << std::endl;
		}
	}
	unsigned int size()		// big-o = O(1)
	{
		return m_size;
	}
	T top()				// big-o = O(1)
	{
		if (!is_empty())
		{
			return head->get_value();
		}
		else
		{
			std::cout << "The stack is empty." << std::endl;
			return static_cast<T> (0);
		}

	}
	bool is_empty()		// big-o = O(1)
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void delete_stack()	// big-o = O(n)
	{
		while (head != NULL)
		{
			pop();
		}
	}
};

template <typename T>
class Queue
{

private:
	Node<T>* p_front;
	Node<T>* p_back;
	Node<T>* p_temp;
	unsigned int m_size;

public:
	Queue()
	{
		p_front = NULL;
		p_back = NULL;
		p_temp = NULL;
		m_size = 0;
	}
	~Queue()
	{
		delete_queue();
	}

	bool is_empty()			// big-o = O(1)
	{
		if (p_front == NULL || p_back == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	unsigned int size()		// big-o = O(1)
	{
		return m_size;
	}
	void emplace(const T& element)	// big-o = O(1)
	{
		p_temp = new Node<T>;
		p_temp->set_next(p_back);
		p_back = p_temp;
		p_temp = NULL;
	}
	T front()				// big-o = O(1)
	{
		if (!is_empty())
		{
			return p_front->get_value();
		}
		else
		{
			std::cout << "The queue is empty" << std::endl;
			return static_cast<T>(0);
		}
	}
	T back()				// big-0 = O(1)
	{
		if (!is_empty())
		{
			return p_back->get_value();
		}
		else
		{
			std::cout << "The queue is empty" << std::endl;
			return static_cast<T>(0);
		}
	}
	void push(const T& element) // big-o = O(1)
	{
		p_temp = new Node<T>;
		if (is_empty())
		{
			p_front = p_temp;
			p_back = p_temp;
		}
		else
		{
			p_front->set_next(p_temp);
			p_front = p_temp;
		}
		p_front->set_value(element);
		p_front->set_next(NULL);
		m_size++;
	}
	void pop()				// big-o = O(1)
	{
		if (!is_empty())
		{
			p_temp = p_back->get_next();
			delete p_back;
			p_back = p_temp;
			p_temp = NULL;
		}
		else
		{
			p_front = NULL;
			p_back = NULL;
			std::cout << "The queue is empty" << std::endl;
		}
	}
	void delete_queue()		// big-0 = O(1)
	{
		while (!is_empty())
		{
			pop();
		}
	}
};

int main(int argc, char** argv)
{
	Stack<int>* stack1 = new Stack<int>;
	Queue<int>* queue1 = new Queue<int>;
	stack1->push(5);
	stack1->push(4);
	stack1->push(3);
	stack1->push(3);
	stack1->push(3);
	stack1->push(3);
	stack1->pop();
	stack1->pop();
	stack1->pop();
	stack1->pop();
	stack1->pop();
	std::cout << "size of stack =  " << stack1->size() << std::endl;
	delete stack1,queue1;
	return 0;
}