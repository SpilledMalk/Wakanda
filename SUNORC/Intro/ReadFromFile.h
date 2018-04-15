#pragma once

void PressEnter();
class ReadFromFile
{

public:

	ReadFromFile();
	void ReadsAndPrintsScene(std::string);
	void PrintLine(std::string);
	std::string wordWrap(std::string, int);
	void ReadFromFile::PrintLineWithoutEnter(std::string line);
private:

};