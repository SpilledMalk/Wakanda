#pragma once
#include <string>
#include <iostream>
#include <fstream>

#ifndef SAVES_H
#define SAVES_H

using namespace std;

class SaveState
{
public:
	SaveState(); // constructor

	int GetProgress();
	string GetPlayerName();
	void SetPlayerName(string);

	string GetBaseWeapon();
	void SetBaseWeapon(string);
	void SetProgress(int);

	void SaveGame();
	void Load();
	void DeleteSave();

private:
	int Progress; // general "chronological" location
	string PlayerName; // playername given in prologue
	string BaseWeapon;
};

#endif