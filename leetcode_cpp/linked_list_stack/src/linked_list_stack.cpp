#include <iostream>

// class Stack : public Node<int> 
template <typename T>
class Stack
{

private:
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

public:
	Node* head;
	Stack()
	{
		head = new Node;
	}
	void push(T element)
	{
		head->get_next(new Node);
		head->set_value(element);
	}
	void pop()
	{

	}
	unsigned int size()
	{
		unsigned int s;

		return s;
	}
	T top()
	{
		T ret;

		return ret;
	}
	bool is_empty()
	{
		try
		{

		}
		catch (T* e)
		{

		}
	}
	bool is_full()
	{
		try
		{

		}
		catch (T* e)
		{

		}
	}
	void delete_stack()
	{

	}
};


int main(int argc, char** argv)
{
	Stack<int>* stack1 = new Stack<int>;
	stack1->push(5);
	return 0;
}