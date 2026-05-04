#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"


class Recipe {
public:
    std::string itemName;
    std::vector<Ingredient> requiredIngredients;
    std::string requiredTool;
    int requiredTier;

    Recipe(std::string name, std::vector<Ingredient> ing, std::string tool, int tier);
};