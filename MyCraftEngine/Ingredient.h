#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
using namespace std;

class Recipe {
public:
    string itemName;
    vector<Ingredient> requiredIngredients;
    string requiredTool;
    int requiredTier;

    Recipe(string name, vector<Ingredient> ing, string tool, int tier);
};