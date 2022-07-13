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
	Node* current;
	Stack()
	{
		head = new Node;
		current = head;
	}
	void push(T element)
	{
		current->set_next(new Node);
		current->set_value(element);
		current = current->get_next();
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
	stack1->push(3);
	stack1->push(4);
	return 0;
}