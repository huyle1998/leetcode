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

public:
	Stack()
	{
		head	= NULL;
		temp	= NULL;
	}
	void push(T element)
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
	}
	void pop()
	{
		if (!is_empty())
		{
			temp = head;
			head = head->get_next();
			delete temp;
			temp = NULL;
		}
		else
		{
			std::cout << "The stack is empty." << std::endl;
		}
	}
	unsigned int size()
	{
		unsigned int s;
		return s;
	}
	T top()
	{
		if (!is_empty())
		{
			return head->get_value();
		}
		else
		{
			std::cout << "The stack is empty." << std::endl;
			return 0;
		}

	}
	bool is_empty()
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

	void delete_stack()
	{
		while (head != NULL)
		{
			pop();
		}
	}
};


int main(int argc, char** argv)
{
	Stack<int>* stack1 = new Stack<int>;
	stack1->push(5);
	stack1->push(4);
	stack1->push(3);
	stack1->delete_stack();
	std::cout << "stack1 after pop = " << stack1->top() << std::endl;
	return 0;
}