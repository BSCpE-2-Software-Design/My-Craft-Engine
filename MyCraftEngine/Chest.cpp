#include "Chest.h"

bool Chest::hasIngredients(std::vector<Ingredient> req) {
    for (auto r : req) {
        bool found = false;
        for (auto i : ingredients) {
            if (i.name == r.name && i.quantity >= r.quantity) {
                found = true;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool Chest::hasTool(std::string tool, int tier) {
    for (auto t : tools) {
        if (t.name == tool && t.tier >= tier)
            return true;
    }
    return false;
}

void Chest::addItem(Item item) {
    items.push_back(item);
}

void Chest::removeIngredients(std::vector<Ingredient> req) {
    for (auto& r : req) {
        for (auto& i : ingredients) {
            if (i.name == r.name) {
                i.quantity -= r.quantity;
            }
        }
    }
}
void Chest::addIngredient(Ingredient ing) {

    for (auto& i : ingredients) {
        if (i.name == ing.name) {
            i.quantity += ing.quantity;
            return;
        }
    }

    ingredients.push_back(ing);
}