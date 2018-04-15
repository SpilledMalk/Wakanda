#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

#include "ReadFromFile.h"

ReadFromFile::ReadFromFile() { return; }
//void PressEnter();

void ReadFromFile::ReadsAndPrintsScene(std::string SceneFile)
{
	std::string Enter = "    Press ENTER to continue...";
	std::string line;
	std::ifstream SceneText(SceneFile);
	while (std::getline(SceneText, line))
	{
		if (line.length() < Enter.length())
		{
			std::cout << "\r    " << wordWrap(line, 220) << "                          " << std::endl << std::endl;
		}
		else
		{
			std::cout << "\r    " << wordWrap(line, 220) << std::endl << std::endl;
		}
		PressEnter();
	}
	return;
}

void ReadFromFile::PrintLine(std::string line) {
	std::string Enter = "    Press ENTER to continue...";
	if (line.length() < Enter.length())
	{
		std::cout << "\r    " << wordWrap(line, 220) << "                          " << std::endl << std::endl;
	}
	else
	{
		std::cout << "\r    " << wordWrap(line, 220) << std::endl << std::endl;
	}
	PressEnter();
}

void ReadFromFile::PrintLineWithoutEnter(std::string line) {
	std::string Enter = "    Press ENTER to continue...";
	if (line.length() < Enter.length())
	{
		std::cout << "\r    " << wordWrap(line, 220) << "                          " << std::endl << std::endl;
	}
	else
	{
		std::cout << "\r    " << wordWrap(line, 220) << std::endl << std::endl;
	}
}

std::string ReadFromFile::wordWrap(std::string sentence, int width)
{
	int count = 0;
	int lastSpaceIndex = 0;

	int distanceToWidth = 0;

	for (count = 0; count < sentence.length(); count++)
	{
		if (distanceToWidth >= width)
		{
			distanceToWidth = 0;
			sentence.insert(lastSpaceIndex, "\n   ");
		}
		if (sentence[count] == ' ')
		{
			lastSpaceIndex = count;
		}

		distanceToWidth++;
	}
	return sentence;
}

void PressEnter()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	std::string s;
	std::cout << "    Press ENTER to continue...";
	std::getline(std::cin, s);

	SetConsoleMode(hStdin, mode);
}