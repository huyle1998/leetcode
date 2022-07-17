#include <iostream>

template <typename T>
class Node
{
private:
	T m_data;
	Node* next;

public:
	Node(const T& value)
	{
		this->set_data(value);
	}
	void set_data(const T& value) {
		this->m_data = value;
	}
	void set_next(Node* next)
	{
		this->next = next;
	}
	Node* get_next() {
		return this->next;
	}
	T get_data() {
		return this->m_data;
	}
};

template <typename T>
class Stack {

private:
	Node<T>* p_head;
	Node<T>* p_temp;
	unsigned int m_size;

public:
	Stack() {
		p_head = NULL;		// object A
		p_temp = NULL;		// 
		m_size = 0;
	}
	~Stack() {

	}

	T top() {
		if (!empty())
		{
			return p_head->get_data();
		}
		else {
			std::cout << "The stack is empty" << std::endl;
			return static_cast<T> (0);
		}
	}
	void push(const T& element) {
		p_temp = new Node<T>(element);
		if (empty()) {
			p_head = p_temp;
			p_tail = p_temp;
		}
		else {
			p_temp->set_next(p_head); // hét
			p_head = p_temp;
		}
		m_size++;
	}
	void pop() {
		if (!empty())
		{
			p_temp = p_head;
			p_head = p_head->get_next();
			delete p_temp;
			p_temp = NULL;
			m_size--;
		}
		else {
			std::cout << "The stack is empty" << std::endl;
		}

	}
	bool empty()
	{
		if (p_head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	unsigned int size()
	{
		return m_size;
	}
	void delete_stack()
	{
		while (p_head != NULL)
		{
			pop();
		}
	}
};

void main()
{

}