#include <iostream>
#include "CraftEngine.h"

void CraftEngine::craft(Chest& chest, Recipe recipe) {

	if(!chest.hasIngredients(recipe.requiredIngredients)) {
		std::cout << "Insufficient Ingredients\n";
		return;

		if (!chest.hasTool(recipe.requiredTool, recipe.requiredTier)) {
			std::cout << "Missing Tool or Low Tier\n";
			return;
	}
		chest.removeIngredients(recipe.requiredIngredients);
		chest.addItem(Item(recipe.itemName));

		std::cout << "Craf Successful " << recipe.itemName << "\n";
}