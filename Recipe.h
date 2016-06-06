#ifndef Recipe_h
#define Recipe_h
#include <string>
using namespace std;

class Recipe
{


private:
	Recipe* NextSibling; // next ingredient
	Recipe* FirstChild; // first ingredient
	string Craft_Class;
	int Craft_Level;
	int Number_Ingredients;


public:
	Recipe();
	~Recipe();	
	Recipe (string, int, int);
	void SetNext(Recipe, Recipe*);
	void SetIngredient(Recipe, Recipe*);
	void SetFirstIngredient(Recipe, Recipe*);
	void SetClass(Recipe, string);
	void SetLevel(Recipe, int);
	void SetNumberIng(Recipe, int);


	
};



#endif