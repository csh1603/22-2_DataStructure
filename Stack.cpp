#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() {// constructor
	topNode = nullptr;
}

template<typename T>
Stack<T>::~Stack() {// destructor
	clear();
}

template<typename T>
void Stack<T>::push(T data) {// push
	Node* node = new Node();
	node->data = data;
	node->next = topNode;
	topNode = node;
}

template<typename T>
void Stack<T>::pop() {// pop
	Node* del;
	if (topNode == nullptr) {
		cout << "Stack is empty" << endl;
	}
	else {
		del = topNode;
		topNode = topNode->next;
		delete(del);
	}
}

template<typename T>
T Stack<T>::top() {// return top data
	if (topNode != nullptr) {
		return topNode->data;
	}
	else {
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
}

template<typename T>
bool Stack<T>::isEmpty() {// return 1 if empty
	return topNode == nullptr;
}

template<typename T>
int Stack<T>::size() {// return size of the stack
	Node* cnt = topNode;
	int count = 0;
	while (cnt != nullptr) {
		count++;
		cnt = cnt->next;
	}
	return count;
}

template<typename T>
void Stack<T>::clear() {// clear the stack
	while (topNode != nullptr)
		pop();
}

template<typename T>
void Stack<T>::printStack() {// print all elements in the stack
	Node* ptr;
	if (topNode == nullptr) {
		std::cout << "Stack is empty";
	}
	else {
		ptr = topNode;
		while (ptr != nullptr) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	std::cout << endl;
}