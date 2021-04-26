#include <iostream>

#include "FriendClass.h"
#include "LinkedListSln.h"

Node::Node()
{
	prev = nullptr;
	next = nullptr;
	data = Friend();
}

Node::Node(Friend newData)
{
	prev = nullptr;
	next = nullptr;
	setData(newData);
}

Friend Node::getData()
{
	return data;
}

void Node::setData(Friend newData)
{
	data.setName(newData.getName());
	data.setPopularity(newData.getPopularity());
}

Node* Node::getPrev()
{
	return prev;
}

void Node::setPrev(Node* newPrev)
{
	prev = newPrev;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* newNext)
{
	next = newNext;
}


Stack::Stack()
{
	first = nullptr;
	last  = nullptr;
	size  = 0;
}

size_t Stack::getSize()
{
	return size;
}

Node* Stack::getFirst()
{
	return first;
}

Node* Stack::getLast()
{
	return last;
}

Node* Stack::getByPos(size_t pos)
{
	if (isEmpty())
		return nullptr;
	if (pos >= size)
		return last;

	Node* cur = first;
	size_t count = 0;

	while (cur != NULL)
	{
		if (count == pos)
			return cur;
		count++;
		cur = cur->getNext();
	}

	return nullptr;
}

void Stack::push(Node* newNode)
{
	if (isFull())
		return;

	if (isEmpty())
	{
		newNode->setNext(nullptr);
		newNode->setPrev(nullptr);
		first = newNode;
		last = newNode;
		size++;
		return;
	}

	last->setNext(newNode);
	last->getNext()->setNext(nullptr);
	last->getNext()->setPrev(last);
	last = newNode;
	size++;
}

void Stack::pop()
{
	if (isEmpty())
		return;

	if (size == 1)
	{
		last = nullptr;
		first = nullptr;
		size--;
		return;
	}

	last = last->getPrev();
	last->setNext(nullptr);
	size--;
}

void Stack::removeByPos(size_t pos)
{
	if (isEmpty())
		return;
	if (pos >= size)
	{
		pop();
		return;
	}
	if (pos == 0)
	{
		first->getNext()->setPrev(nullptr);
		first = first->getNext();
		size--;
		return;
	}
	Node* cur = getByPos(pos);

	cur->getPrev()->setNext(cur->getNext());
	cur->getNext()->setPrev(cur->getPrev());
	size--;
}

void Stack::removeByNode(Node* node)
{
	if (isEmpty())
		return;
	if (node == last)
	{
		pop();
		return;
	}
	if (node == first)
	{
		first->getNext()->setPrev(nullptr);
		first = first->getNext();
		return;
	}

	node->getPrev()->setNext(node->getNext());
	node->getNext()->setPrev(node->getPrev());

}

bool Stack::isEmpty()
{
	return (first == nullptr) * (last == nullptr);
}

bool Stack::isFull()
{
	return (size == SIZE_MAX);
}

void Stack::display(bool indexed)
{
	Node* cur = first;
	int i = 0;
	while (cur != NULL)
	{
		if (indexed)
			std::cout << ++i << ". ";
		cur->getData().display(true);
		cur = cur->getNext();
	}
}

Stack makeRandomStack(unsigned short int amount)
{
	Stack out;
	Node* ptr;

	for (amount; amount > 0; amount--)
	{
		ptr = new Node(Friend::Friend());
		out.push(ptr);
	}

	return out;
}

Stack setStack(unsigned short int amount)
{
	Stack out;
	int tempPop;
	Node* ptr;

	for (amount; amount > 0; amount--)
	{
		std::cout << "Popularity: ";
		std::cin >> tempPop;
		ptr = new Node(Friend(tempPop));
		out.push(ptr);
	}

	return out;
}

void bridgeBurner(Stack& stack, unsigned short int tests)
{
	for (tests; tests > 0; tests--)
	{
		if (stack.isEmpty())
			return;
		burner(stack);
	}
}

void burner(Stack& stack)
{
	if (stack.isEmpty())
		return;

	Node* cur = stack.getFirst();
	while (cur != NULL)
	{
		if(cur->getData().isLessPopular(cur->getNext()->getData()))
		{
			stack.removeByNode(cur);
			return;
		}
		cur = cur->getNext();
	}

	stack.pop();
}
