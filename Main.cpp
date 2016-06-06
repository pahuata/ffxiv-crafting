#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Recipe.h"
using namespace std;

string ReadFile(string filename, int& numberlines)
{
	fstream inputstream(filename);
	string input, thisline;
	while (inputstream.good())
	{
		getline (inputstream, thisline);
		input = input + thisline + '\n';
		numberlines++;
	}
	return input;
}

string GetLine(string List, int& Position) // Reads a line starting at position Position in the string, delimited by '\n'
{
	string Line;
	while(List.at(Position) != '\n')
	{
		Line = Line + List.at(Position);
		Position++;
	}

	Position++;
	return Line;
}

string GetWord(string Line) // Reads the first word of the line, comma delimited
{
	int CurrentPos = 0;
	char CurrentChar = Line.at(CurrentPos);
	string FirstWord;
	while (CurrentChar != ',')
	{
		FirstWord = FirstWord + CurrentChar;
		CurrentPos++;
		CurrentChar = Line.at(CurrentPos);
	}

	return FirstWord;
}

string NextWord(string Line, int& Position)
{
	string Word;
	while(Line.at(Position) != ',')
	{
		Word = Word + Line.at(Position);
		Position++;
	}

	Position++;
	return Word;
}

int FindLine(string RecipeList, int ListLength, string ToFind) // Returns the line number of the line whose first entry is "ToFind"
{
	int FoundOnLine = -1;
	int CurrentLine = 0;
	int ListPosition = 0;

	for (CurrentLine; CurrentLine < ListLength-1; CurrentLine++)
	{
		if (GetWord(GetLine(RecipeList, ListPosition)) == ToFind)
			FoundOnLine = CurrentLine;
		if (FoundOnLine >= 0)
			break;
	}

	return FoundOnLine;
}

unordered_map<string, int> ReadLine(string Line, string& ItemName, int& CraftLevel, int& NumberIngredients)
{
	int LineLength = Line.length();




}




Recipe MakeRecipe(string RecipeLine, int ListPosition)
{


}






int main()
{
	enum craft_job {None, CRP, ARM, WVR, BSM, CUL, ALC, GSM, LTW}; // maps each class name to an int
	string FileNames[9] = {"Materials.csv", "Carpenter.csv", "Armorer.csv", "Weaver.csv", "Blacksmith.csv", 
							"Culinarian.csv", "Alchemist.csv", "Goldsmith.csv", "Leatherworker.csv"};
	int FileLines[9] = {0,0,0,0,0,0,0,0,0};
	unordered_map<string, int> FileCraftJobMap;
	unordered_map<string, int> CraftJobMap;
	for (int i = 0; i < 9; i++)
	{
		FileCraftJobMap.emplace(FileNames[i], i);
		//cout << FileNames[i] << " " << FileCraftJobMap[i] << endl;
	}
	CraftJobMap.emplace("Hempen Thread", WVR);
	//cout << FileLines[FileCraftJobMap["Weaver.csv"]] << endl;
	string WeaverFile = ReadFile("Weaver.csv", FileLines[FileCraftJobMap["Weaver.csv"]]);
	cout <<  WeaverFile; 
	//cout << FileLines[FileCraftJobMap["Weaver.csv"]]-1 << endl;

	int position = 0;
	string testline = GetLine(WeaverFile, position);
	cout << testline << ' ' << position << endl << GetWord(testline) << endl;
	testline = GetLine(WeaverFile, position);
	cout << testline << ' ' << position << endl << GetWord(testline) << endl;
	testline = GetLine(WeaverFile, position);
	cout << testline << ' ' << position << endl << GetWord(testline) << endl;

	cout << FindLine(WeaverFile, FileLines[FileCraftJobMap["Weaver.csv"]], "Hempen Halfgloves");

	system ("pause");
	return 0;

}