#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "SaveSystem.h"

void SaveSystem::save(Chest& chest, std::string filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cout << "Error saving file: " << filename << '\n';
		return;
	}

	file << "[INGREDIENTS]" << '\n';
	for (const auto& i : chest.ingredients) {
		file << i.name << "," << i.quantity << "," << i.unit << '\n';
	}

	file << "[TOOLS]" << '\n';
	for (const auto& t : chest.tools) {
		file << t.name << "," << t.tier << '\n';
	}	

	file << "[ITEMS]" << '\n';
	for (const auto& it : chest.items) {
		file << it.name << '\n';
	}

	file.close();
	std::cout << "Game Saved Successfully " << filename << '\n';

}
void SaveSystem::load(Chest& chest, std::string filename) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cout << "No save file found " << filename << '\n';
		return;
	}
	chest.ingredients.clear();
	chest.tools.clear();
	chest.items.clear();
	std::string lines;
	std::string section = "";


