#include "Recipe.h"
#include <string>
#include <iostream>

using namespace std;


Recipe::Recipe()
{
	Craft_Class = "";
	Craft_Level = 0;
	Number_Ingredients = 0;
	NextSibling = NULL;
	FirstChild = NULL;
}

Recipe::~Recipe()
{
	cout << "Deleted";
}

Recipe::Recipe(string ClassName, int Level, int NumIngredients)
{
	Craft_Class = ClassName;
	Craft_Level = Level;
	Number_Ingredients = NumIngredients;
	NextSibling = NULL;
	FirstChild = NULL;
}

void Recipe::SetIngredient(Recipe CurrentRecipe, Recipe* RightIngredient)
{
	CurrentRecipe.NextSibling = RightIngredient;
	return;
}

void Recipe::SetFirstIngredient(Recipe CurrentRecipe, Recipe* FirstIngredient)
{
	CurrentRecipe.FirstChild = FirstIngredient;
	return;
}

void Recipe::SetClass(Recipe CurrentRecipe, string ClassName)
{
	CurrentRecipe.Craft_Class = ClassName;
	return;
}

void Recipe::SetLevel(Recipe CurrentRecipe, int Level)
{
	CurrentRecipe.Craft_Level = Level;
	return;
}

void Recipe::SetNumberIng(Recipe CurrentRecipe, int NumIng)
{
	CurrentRecipe.Number_Ingredients = NumIng;
	return;
}