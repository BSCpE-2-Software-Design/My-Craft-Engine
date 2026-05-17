#include "doctest.h"

#include "Tool.h"

TEST_CASE("Tool upgrade increases tier") {

    Tool tool("Forge Hammer", 1);

    tool.upgrade();

    CHECK(tool.tier == 2);
}

TEST_CASE("Tool max tier is 3") {

    Tool tool("Forge Hammer", 3);

    tool.upgrade();

    CHECK(tool.tier == 3);
}