#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <MMSystem.h>

#include "conio.h"
#include "SaveState.h"
#include "ReadFromFile.h"
#include "ActPlayer.h"
#include "Act1/PageHandler.h"
#include "Act1/Act1WeaponPick.h"

using namespace std;

int main()
{
	//// creates a SaveState, and loads data from save.txt
	SaveState Save;

	//// sets data to usable variables
	string PlayerName = Save.GetPlayerName();
	int Progress = Save.GetProgress();

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	//// act is chosen depending on progress
	switch (Progress)
	{
	case 0:
	{
		//PlaySound("Room.wav", NULL, SND_LOOP | SND_ASYNC);
		//PlaySound("Infirmary.wav", NULL, SND_LOOP | SND_ASYNC);

		PlayPrologue(Save);

		Progress+=1;		// Wrap in functions for Act changes with cout << "\n    *PROGRESS SAVED*\n\n";
		Save.SetProgress(Progress);

		//writes save data to file
		Save.SaveGame();

	}
	case 1:
	{
		// all testing that the values from previous are still true
		//switch (Progress)   SUBSCENES: WIP
		chooseStarterWeapon(Save);
		//Progress += 0.1;	//Wrap in functions for sub-scenes cout << "\n    *PROGRESS SAVED*\n\n";
		Progress++;
		Save.SetProgress(Progress);
		Save.SaveGame();

	}
	case 2:
	{
		string DeleteResponse;
		cout << "    Would you like to delete your save? (y/n): ";
		//std::getline(std::cin, DeleteResponse);
		cin >> DeleteResponse;
		if (DeleteResponse == "y")
		{
			Save.DeleteSave();
		}
	}
	}
	return 0;
}