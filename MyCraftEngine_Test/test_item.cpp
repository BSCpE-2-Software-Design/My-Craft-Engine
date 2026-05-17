#include "doctest.h"
#include "Item.h"

TEST_CASE("Item constructor stores name correctly") {

    Item item("Dagger");

    CHECK(item.name == "Dagger");
}

TEST_CASE("Different item names work") {

    Item item1("Blade of Despair");
    Item item2("Magic Wand");

    CHECK(item1.name == "Blade of Despair");
    CHECK(item2.name == "Magic Wand");
}

TEST_CASE("Empty item name works") {

    Item item("");

    CHECK(item.name == "");
}