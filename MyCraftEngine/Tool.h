#pragma once
#include <string>

class Tool {
public:
	std::string name;
	int tier;
	Tool(std::string n, int t);
	void upgrade();
};
