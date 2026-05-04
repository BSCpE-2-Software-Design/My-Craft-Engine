#pragma once
#include "Chest.h"
#include <string>
#include <iostream>

class SaveSystem {
public:
	static void save(Chest& chest, std::string filename);
	static void load(Chest& chest, std::string filename);
};