#pragma once
#include "Chest.h"
#include "Recipe.h"

class CraftEngine {
public:
    static void craft(Chest& chest, Recipe recipe);
};