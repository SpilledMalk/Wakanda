#pragma once
#include <stdio.h>
#include "SaveState.h"

using namespace std;

// constructor
SaveState::SaveState()
{
	SaveState::Load();
}

// getters for various data
int SaveState::GetProgress() { return Progress; }
string SaveState::GetPlayerName() { return SaveState::PlayerName; }
string SaveState::GetBaseWeapon() { return SaveState::BaseWeapon; }

void SaveState::SetProgress(int NewProg)
{
	SaveState::Progress = NewProg;
	return;
}

void SaveState::SetPlayerName(string NewName)
{
	SaveState::PlayerName = NewName;
	return;
}

void SaveState::SetBaseWeapon(string BaseWeap)
{
	SaveState::BaseWeapon = BaseWeap;
	return;
}

void SaveState::DeleteSave()
{
	// default save values
	SaveState::Progress = 0;
	SaveState::PlayerName = "";
	SaveState::BaseWeapon = "";

	remove("save.txt");

	// rewrite save.txt to default values
	ofstream OutFile("save.txt");
	OutFile << "PlayerName : \n";
	OutFile << "Progress : 0";
	OutFile.close();
}

void SaveState::SaveGame()
{
	remove("save.txt");

	ofstream OutFile("save.txt");
	OutFile << "PlayerName : " << SaveState::GetPlayerName() << endl;
	OutFile << "Progress : " << SaveState::GetProgress() << endl;
	OutFile << "BaseWeapon : " << SaveState::GetBaseWeapon() << endl;
	OutFile.close();
}

void SaveState::Load()
{
	ifstream inFile; // declare an input file stream
	inFile.open("save.txt"); // open file for streaming
	string line;
	getline(inFile, line);

	// PlayerName assigned to whatever follows the : in save.txt
	SaveState::PlayerName = line.substr(line.find(":") + 2);
	getline(inFile, line);
	SaveState::Progress = stoi(line.substr(line.find(":") + 2));
	getline(inFile, line);
	SaveState::BaseWeapon = line.substr(line.find(":") + 2);
	inFile.close();
	return;
}