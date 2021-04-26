#pragma once

#include "LinkedListSln.h"
#include "FriendClass.h"

std::vector<Friend> makeRandomVector(unsigned short int amount = 0);

std::vector<Friend> setVector(unsigned short int amount = 0);

void displayVector(std::vector<Friend>& vec, bool indexed = true);

void bridgeBurner(std::vector<Friend>& vec, unsigned short int tests = 0);

void burner(std::vector<Friend>& vec);

Stack vectorToStack(std::vector<Friend>& vec);