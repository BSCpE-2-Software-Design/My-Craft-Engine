# My-Craft-Engine
~~~mermaid
sequenceDiagram

actor User
participant MainUI
participant SaveSystem
participant RecipeLoader
participant Chest
participant Recipe
participant CraftEngine
participant ToolUpgrade



User->>MainUI: Run Program
MainUI->>SaveSystem: load(chest, save.txt)

alt Save file exists
    SaveSystem-->>Chest: restore saved data
else No save file
    SaveSystem-->>Chest: initialize empty chest
end

MainUI->>RecipeLoader: load recipes
RecipeLoader-->>MainUI: recipes ready


User->>MainUI: Choose option

alt Chest Selected

    MainUI->>Chest: display inventory
    Chest-->>User: ingredients, tools, items

    User->>MainUI: add ingredient
    MainUI->>Chest: addIngredient()
    Chest-->>User: updated chest

else Craft Engine Selected

    MainUI->>Recipe: show recipe list
    Recipe-->>MainUI: recipes available

    User->>MainUI: select recipe
    MainUI->>Recipe: get requirements
    Recipe-->>MainUI: ingredients + tool + tier

    MainUI->>User: show requirements
    User->>MainUI: confirm craft

    MainUI->>CraftEngine: craft(chest, recipe)

    CraftEngine->>Chest: check ingredients
    CraftEngine->>Chest: check tool tier

    alt Requirements satisfied
        CraftEngine->>Chest: add crafted item
        CraftEngine-->>User: Craft Successful
    else Requirements not satisfied
        CraftEngine-->>User: Missing Ingredients or Tool
    end

    alt Tool Upgrade chosen
        User->>MainUI: select tool upgrade
        MainUI->>ToolUpgrade: upgradeTool(chest, toolName)
        ToolUpgrade->>Chest: increase tool tier
        ToolUpgrade-->>User: Tool upgraded
    end

else Save & Exit Selected

    MainUI->>SaveSystem: save(chest, save.txt)
    SaveSystem->>Chest: read current state
    SaveSystem-->>User: Game Saved

end
~~~
~~~mermaid
classDiagram

class SaveSystem {
    +load(chest, filePath)
    +save(chest, filePath)
}

class RecipeLoader {
    +loadRecipes()
}

class Chest {
    -inventory
    +addIngredient()
    +removeIngredient()
    +displayInventory()
    +hasIngredients()
    +updateTool()
}

class Recipe {
    -ingredients
    -requiredTool
    -toolTier
    +getRequirements()
}

class CraftEngine {
    +craft(chest, recipe)
    +validateIngredients()
    +validateToolTier()
}

class ToolUpgrade {
    +upgradeTool(chest, toolName)
}



SaveSystem --> Chest : loads/saves
RecipeLoader --> Recipe : creates/loads

CraftEngine --> Chest : checks/modifies
CraftEngine --> Recipe : reads requirements

ToolUpgrade --> Chest : upgrades tool

Chest --> Recipe : compares requirements
~~~
