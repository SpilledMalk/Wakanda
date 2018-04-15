#pragma once
#include "Character.h"
#include <vector>

class Field {

private:
	vector<Character> characters; // List of all the characters currently on the field
	int width, height;
	char **grid;


public:
	Field(int maxWidth, int maxHeight);

	void insertCharacter(Character & c);

	void printField();

	void printCell(int x, char ** grid);

	void printCharacters();
};