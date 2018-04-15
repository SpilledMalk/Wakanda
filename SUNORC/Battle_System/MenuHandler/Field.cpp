#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Field.h"

Field::Field(int maxWidth, int maxHeight)
	:width(maxWidth), height(maxHeight), grid(new char *[height])
{

	for (int i = 0; i < height+1; ++i) // Iterate through every row
	{
		grid[i] = new char[width + 1]; // each row is now initialized as an array
		int j;
		for (j = 0; j < width; ++j) // Iterate through every cell in row 'i'
			grid[i][j] = '_'; // Assign every cell within the grid to the character '_'
		grid[i][j] = '\0'; // This loop will set all the last index values to a null character. This way, when we want to print out the field, we can stop at every null char
	}
}

void Field::insertCharacter(Character & c)
{
	int coords[2] = { 0,1 }; // Placeholder for now; we want to randomly generate these coordinates
	c.setCoords(coords[0], coords[1]);
	characters.push_back(c);
}

void Field::printField()
{
	grid[5][6] = 'a';
	grid[7][6] = 'b';
	for (int j = 0; grid[0][j] != '\0'; ++j)
		cout << " _";
	for (int i = 0; i < height; ++i)
		printCell(i, grid);
	cout << endl << endl;;
	printCharacters();
}

void Field::printCell(int x, char ** grid)
{
	cout << endl;
	for (int j = 0; grid[x][j] != '\0'; ++j)
		cout << "|" << grid[x][j];
	cout << "|";
}

void Field::printCharacters()
{

	cout << "Name" << setw(20) << "Symbol" << setw(10) << "Status" << setw(10) << "Health" << setw(15) << "Coordinates" << endl;
	cout << "-----------------------------------------------------------" << endl;
	for (auto character : characters)
	{
		character.printStats();
	}
	cout << endl;
}
