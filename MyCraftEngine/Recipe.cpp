#include "Recipe.h"

Recipe::Recipe(std::string name, std::vector<Ingredient> ing, std::string tool, int tier) {
	itemName = name;
	requiredIngredients = ing;
	requiredTool = tool;
	requiredTier = tier;
}