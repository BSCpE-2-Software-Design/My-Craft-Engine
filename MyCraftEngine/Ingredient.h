#pragma once
#include <string>

class Ingredient {
public:
    std::string name = "";
    double quantity = 0.0;
    std::string unit = "";


    Ingredient();
    Ingredient(std::string n, double q, std::string u);
};