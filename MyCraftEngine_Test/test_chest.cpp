#include "doctest.h"

#include "Chest.h"
#include "Ingredient.h"
#include "Tool.h"
#include "Item.h"

TEST_CASE("Add valid ingredient") {

    Chest chest;

    chest.addIngredient(Ingredient("Iron Ore", 5, "pcs"));

    CHECK(chest.ingredients.size() == 1);
    CHECK(chest.ingredients[0].name == "Iron Ore");
    CHECK(chest.ingredients[0].quantity == 5);
}

TEST_CASE("Reject invalid ingredient") {

    Chest chest;

    chest.addIngredient(Ingredient("Dagger", 1, "pcs"));

    CHECK(chest.ingredients.empty());
}

TEST_CASE("Merge same ingredient") {

    Chest chest;

    chest.addIngredient(Ingredient("Wood", 2, "pcs"));
    chest.addIngredient(Ingredient("Wood", 3, "pcs"));

    CHECK(chest.ingredients.size() == 1);
    CHECK(chest.ingredients[0].quantity == 5);
}

TEST_CASE("Has ingredients true") {

    Chest chest;

    chest.addIngredient(Ingredient("Iron Ore", 5, "pcs"));

    CHECK(chest.hasIngredients({Ingredient("Iron Ore", 3, "pcs")}));
}

TEST_CASE("Has ingredients false") {

    Chest chest;

    chest.addIngredient(Ingredient("Iron Ore", 1, "pcs"));

    CHECK_FALSE(
        chest.hasIngredients({
            Ingredient("Iron Ore", 5, "pcs")
            })
    );
}

TEST_CASE("Has tool true") {

    Chest chest;

    chest.tools.push_back(Tool("Forge Hammer", 2));

    CHECK(chest.hasTool("Forge Hammer", 2));
}

TEST_CASE("Universal tool works") {

    Chest chest;

    chest.tools.push_back(Tool("Universal", 3));

    CHECK(chest.hasTool("Guardian Sigil", 3));
}

TEST_CASE("Remove ingredients") {

    Chest chest;

    chest.addIngredient(Ingredient("Wood", 5, "pcs"));
    chest.removeIngredients({Ingredient("Wood", 2, "pcs")});

    CHECK(chest.ingredients[0].quantity == 3);
}

TEST_CASE("Has item") {

    Chest chest;

    chest.items.push_back(Item("Dagger"));
    CHECK(chest.hasItem("Dagger"));
}

TEST_CASE("Remove item") {

    Chest chest;
    chest.items.push_back(Item("Knife"));
    chest.removeItem("Knife");

    CHECK_FALSE(chest.hasItem("Knife"));
}
