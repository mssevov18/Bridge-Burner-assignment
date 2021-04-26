#include <iostream>
#include <vector>

#include "stdlib.h"
#include "time.h"

#include "VectorSln.h"
#include "LinkedListSln.h"

int main()
{
	srand((unsigned int)time(NULL));

	unsigned short int testCases = 0;	// T
	      unsigned int friendCount = 0;	// N
	              bool manual = false;

	std::cout << "How many friends should be removed?  ";
	std::cin >> testCases;

	std::cout << "\nHow many friends are we starting with?  ";
	std::cin >> friendCount;

	std::cout << "\n1 for manual input, 0 for automatic?  ";
	std::cin >> manual;

	std::cout << std::endl;

	Stack st;

	if (manual)
		st = setStack(friendCount);
	else
		st = makeRandomStack(friendCount);

	std::cout << "\nFriends before:\n";
	st.display();

	bridgeBurner(st, testCases);

	std::cout << "\nFriends after:\n";
	st.display();

	/*
	//test code
	std::vector<Friend> vector;
	std::cout << std::endl;
	displayVector(vector);
	std::cout << std::endl;

	Stack stk = vectorToStack(vector);
	
	bridgeBurner(vector, testCases);
	displayVector(vector);
	std::cout << std::endl;
	std::cout << std::endl;

	stk.display();

	std::cout << std::endl;
	stk.getByPos(4)->getData().display();
	std::cout << std::endl;
	stk.getByPos(friendCount + 1)->getData().display();
	
	std::cout << std::endl;
	std::cout << std::endl;
	bridgeBurner(stk, testCases);
	stk.display();
	std::cout << std::endl;
	std::cout << std::endl;

	stk.removeByPos(0);
	stk.display();
	std::cout << std::endl;
	stk.removeByNode(stk.getLast());
	stk.display();
	std::cout << std::endl;
	stk.pop();
	stk.display();

	Stack st2 = setStack(friendCount);
	st2.display();

	//
	*/

}