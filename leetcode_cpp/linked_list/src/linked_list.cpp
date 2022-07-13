#include <iostream>

class Node {

private:
	int value;
	Node* next;

public:
	void set_value(int value)
	{
		this->value = value;
	}
	void set_next(Node* next)
	{
		this->next = next;
	}
	int get_value()
	{
		return this->value;
	}
	Node* get_next()
	{
		return this->next;
	}
};

void print_linked_list(Node* node)
{
	while (node != NULL)
	{
		std::cout << node->get_value() << std::endl;
		node = node->get_next();
	}
}

int main(int argc, char** argv)
{
	// Assume: we have a linked list which consits of 6 elements (node1->6)
	Node* node1 = new Node;
	Node* node2 = new Node;
	Node* node3 = new Node;
	Node* node4 = new Node;
	Node* node5 = new Node;
	Node* node6 = new Node;

	node1->set_value(1); node1->set_next(node2);
	node2->set_value(2); node2->set_next(node3);
	node3->set_value(3); node3->set_next(node4);
	node4->set_value(4); node4->set_next(node5);
	node5->set_value(5); node5->set_next(node6);
	node6->set_value(6); node6->set_next(NULL);

	print_linked_list(node1);

	delete node1, node2, node3, node4, node5, node6;
	return 0;
}