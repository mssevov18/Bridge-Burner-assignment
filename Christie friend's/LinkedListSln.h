#pragma once

#include "FriendClass.h"

class Node
{
public:
	Node();
	Node(Friend newData);

private:
	 Node* prev;
	 Node* next;
	Friend data;


public:
	Friend getData();
	  void setData(Friend newData);

	 Node* getPrev();
	  void setPrev(Node* newPrev);

	 Node* getNext();
	  void setNext(Node* newNext);
};

class Stack
{
public:
	Stack();

private:
	 Node* first;
	 Node* last;
	size_t size;

public:
	size_t getSize();

	 Node* getFirst();
	 Node* getLast();
	 Node* getByPos(size_t pos);


	  void push(Node* newNode);
	  void pop();
	  void removeByPos(size_t pos);
	  void removeByNode(Node* node);

	  bool isEmpty();
	  bool isFull();

	  void display(bool indexed = true);
};

Stack makeRandomStack(unsigned short int amount = 0);

Stack setStack(unsigned short int amount = 0);

void bridgeBurner(Stack& stack, unsigned short int tests = 0);

void burner(Stack& stack);
