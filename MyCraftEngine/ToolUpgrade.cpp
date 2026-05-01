#include "Ingredient.h"

Ingredient::Ingredien() {

}

Ingredient::Ingredient(std::string n, double q, std::string u) {

	name = n;
	quantity = q;
	unit += u;
}