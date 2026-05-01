#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "Item.h"


class Chest {
public:
    std::vector<Ingredient> ingredients;
    std::vector<Tool> tools;
    std::vector<Item> items;

    bool hasIngredients(std::vector<Ingredient> req);
    bool hasTool(std::string tool, int tier);

    void addItem(Item item);
    void removeIngredients(std::vector<Ingredient> req);

    void addIngredient(Ingredient ing);
};