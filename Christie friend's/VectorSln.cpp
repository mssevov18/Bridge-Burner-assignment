#include <iostream>
#include <vector>
#include <string>

#include "VectorSln.h"
#include "LinkedListSln.h"
#include "FriendClass.h"

std::vector<Friend> makeRandomVector(unsigned short int amount)
{
	std::vector<Friend> out;
	for (amount; amount > 0; amount--)
		out.push_back(Friend::Friend());
	return out;
}

std::vector<Friend> setVector(unsigned short int amount)
{
	std::vector<Friend> out;
	int tempPop;

	for (amount; amount > 0; amount--)
	{
		std::cout << "Popularity: ";
		std::cin >> tempPop;
		out.push_back(Friend(tempPop));
	}
	
	return out;
}

void displayVector(std::vector<Friend>& vec, bool indexed)
{
	if (vec.empty())
	{
		std::cout << "You are all alone. :'(\n";
		return;
	}
	if (vec.size() == 1)
	{
		std::cout << "Best friend forever: ";
		vec[0].display(true);
		return;
	}
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if(indexed)
			std::cout << i + 1 << ". ";
		vec[i].display(true);
	}
}

void bridgeBurner(std::vector<Friend>& vec, unsigned short int tests)
{
	for (tests; tests > 0; tests--)
	{
		if (vec.empty())
			return;
		burner(vec);
	}
}

void burner(std::vector<Friend>& vec)
{
	if (vec.empty())
		return;
	for (unsigned int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i].isLessPopular(vec[i + 1]))
		{
			vec.erase(vec.begin() + i);
			return;
		}
	}
	vec.pop_back();
}

Stack vectorToStack(std::vector<Friend>& vec)
{
	Stack out;
	Node* ptr;

	for (size_t i = 0; i < vec.size(); i++)
	{
		ptr = new Node(vec[i]);
		out.push(ptr);
	}
	return out;
}
