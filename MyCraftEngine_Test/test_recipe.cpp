#include "doctest.h"
#include "Recipe.h"

TEST_CASE("Recipe constructor stores all values correctly") {

    std::vector<Ingredient> ingredients = {
        Ingredient("Iron Ore", 2, "pcs"),
        Ingredient("Wood", 1, "pcs")
    };

    Recipe recipe(
        "Dagger",
        ingredients,
        "Forge Hammer",
        1
    );

    CHECK(recipe.itemName == "Dagger");
    CHECK(recipe.station == "Forge Hammer");
    CHECK(recipe.tier == 1);
    CHECK(recipe.ingredients.size() == 2);
}

TEST_CASE("Recipe stores ingredient data correctly") {

    std::vector<Ingredient> ingredients = {
        Ingredient("Magic Dust", 3, "pcs"),
        Ingredient("Crystal Shard", 1, "pcs")
    };

    Recipe recipe("Magic Wand",ingredients,"Mystical Arcane Table",2);

    CHECK(recipe.ingredients[0].name == "Magic Dust");
    CHECK(recipe.ingredients[0].quantity == 3);

    CHECK(recipe.ingredients[1].name == "Crystal Shard");
    CHECK(recipe.ingredients[1].quantity == 1);
}

TEST_CASE("Recipe supports tier 3 recipes") {

    Recipe recipe("Blade of Despair",
        {
            Ingredient("Legion Sword", 2, "pcs")
        },
        "Forge Hammer",3);

    CHECK(recipe.tier == 3);
}

TEST_CASE("Recipe supports empty ingredients") {

    Recipe recipe("Empty Recipe",
        {},
        "Forge Hammer",1);

    CHECK(recipe.ingredients.empty());
}
