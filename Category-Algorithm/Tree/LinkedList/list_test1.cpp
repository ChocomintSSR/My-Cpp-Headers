// Linked List 2
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class node
{
public:
	void *value;
	node *next;
	
	node() : value(nullptr), next(nullptr) {}
	template <class T>
	node(T set) : next(nullptr)
	{
		value = new T(set);
	}
	~node()
	{
		delete value;
	}
};

int main()
{
	node *head = new node; // create a memory space as "node" for "head" pointer

	// create the first node
	head->value = 0;
	head->next = NULL;

	// create the nodes before
	node *current = head;

	int a = 1;
	double b = 2.0;
	char c = '3';

	current->next = new node;
	current = current->next;
	current->value = &a;
	current->next = NULL;

	current->next = new node;
	current = current->next;
	current->value = &b;
	current->next = NULL;

	current->next = new node;
	current = current->next;
	current->value = &c;
	current->next = NULL;

	current = head; // let the current aim at the head again

	cout << current->value << *(int *)(current->value) << "\n";
	current = current->next;
	cout << current->value << *(double *)(current->value) << "\n";
	current = current->next;
	cout << current->value << *(char *)(current->value) << "\n";
	current = current->next;

	vector<string> type_list = {"int", "double", "char"};
	return 0;
}
