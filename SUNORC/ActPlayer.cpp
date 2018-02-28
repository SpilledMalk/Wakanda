#include <iostream>
#include "ActPlayer.h"
#include "ReadFromFile.h"
#include "ReadFromChoiceFile.h"
#include "SaveState.h"

//For sound MAYBE
#include <windows.h>
#include <MMSystem.h>
#include "conio.h"

using namespace std;

void PlayPrologue(SaveState & S)
{
	ReadFromFile FileReader;
	FileReader.ReadsAndPrintsScene("PrologueScene1.txt");

	//Bully fight
	startChoiceScene("PrologueScene2choice.txt", S);

	//After Bully Fight Choices7
	FileReader.ReadsAndPrintsScene("PrologueScene3.txt");

	//Infirmary NameEntry Text and Dialogue Options
	PlaySound("Infirmary.wav", NULL, SND_LOOP | SND_ASYNC);
	startChoiceScene("PrologueScene4choice.txt", S);
	PlaySound(NULL, NULL, 0);


	return;
}