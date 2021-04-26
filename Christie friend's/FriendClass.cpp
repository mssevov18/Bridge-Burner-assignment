#include <iostream>
#include <string>

#include "FriendClass.h"

std::string makeId()
{
	return "#" + std::to_string(rand() % 10) + std::to_string(rand() % 10) + std::to_string(rand() % 10) + std::to_string(rand() % 10);
}

Friend::Friend()
{
	name = "Random" + makeId();
	popularity = rand() % 100 + 1;
}

Friend::Friend(int newPopularity)
{
	name = "Random" + makeId();
	setPopularity(newPopularity);
}

Friend::Friend(std::string newName, int newPopularity)
{
	setName(newName);
	setPopularity(newPopularity);
}

std::string Friend::getName()
{
	return name;
}

void Friend::setName(std::string newName)
{
	if (newName != "")
		name = newName;
}

int Friend::getPopularity()
{
	return popularity;
}

void Friend::setPopularity(int newPopularity)
{
	popularity = newPopularity;
}


bool Friend::isMorePopular(class Friend rival)
{
	return (popularity > rival.getPopularity());
}

bool Friend::isLessPopular(class Friend rival)
{
	return (popularity < rival.getPopularity());
}

void Friend::display(bool newLine)
{
	std::cout << name << ": " << popularity << (char)('\n' * newLine);
}