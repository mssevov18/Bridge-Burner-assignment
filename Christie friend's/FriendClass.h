#pragma once

std::string makeId();

class Friend
{
public:
	Friend();
	Friend(int newPopularity);
	Friend(std::string newName, int newPopularity);

private:
	std::string name;
	        int popularity;

public:
	std::string getName();
	       void setName(std::string newName = "");

	        int getPopularity();
	       void setPopularity(int newPopularity = 0);


	       bool isMorePopular(class Friend rival);
	       bool isLessPopular(class Friend rival);

	       void display(bool newLine = false);
};