#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include "ReadFromFile.h"
#include "ReadFromChoiceFile.h"
//For 'press enter to continue'
#include "ReadFromFile.h"
//#include "LinePauseWrap.cpp"
#include "SaveState.h"

using namespace std;
#define INPUT_FILE "Dialogue/Prologue/PrologueScene2choice.txt"
ReadFromFile Reader;

// Function declarations:

//USER RESPONSE GATHERING FUNCTIONS
string getResponse(char response = '\0');
string dealWithUserResponse(char response);
bool answerIsADuplicate(string prevUserResponse, string currentUserResponse);
void printString(const string & str);
void fetchLineFromFile(ifstream file_name, string & line);

//PRINT LINE FUNCTIONS
void printLines(ifstream & inputFile);
void printLinesAndScanToVector(ifstream & inputFile, vector <string> & stringVector, string & lineStatus, const bool & shouldReplace = false, string replaceStr = "");
void printOptionText(string response, ifstream & file);
void printVectorScenario(const vector <string> & vectorStr);

// UTILITY FUNCTIONS

//void iterateResponseLoop(vector <string> & scenario, ifstream & introFile, string & prevUserResponse, string & currentUserResponse, string & totalResponses, int & choiceStage);
void iterateThroughChoices(string & totalResponses, string & prevUserResponse, string & currentUserResponse, ifstream & introFile, int & choiceNumber);
bool changedLineStatus(string line, string & lineStatus);
void appendOptionToTotal(string & totalResponses, string currentUserResponse);
bool responseIsValid(const char & response);
void findOptionInFile(string response, ifstream & file);

//analyze input
bool userChoiceMatchesTrigger(const string & choiceTrigger, const string & userChoice);
bool stageMatchesTrigger(int trigger, int stage);

//End of choice functions
void setCurrentToPrev(string & currentUserChoice, string & prevUserChoice);
void handleEndOfChoice(ifstream & inputFile, string & prevUserChoice, string & currentUserChoice, string & totalResponses);


// High level looping functions
void clearAllVars(string & totalResponses, string & prevUserResponse, string & currentUserResponse);
void loopScenario(const vector <string> & dialogue);


// Exit code functions
void inputCertainText(ifstream & introFile, string & prevUserResponse, string & currentUserResponse, string & totalResponses, string & inputText, bool & replaceText, SaveState & S);
void loopForCertainOption(const vector <string> & dialogue, ifstream & inputFile, const string & choiceTrigger, string & currentUserChoice, string & prevUserChoice, string & totalResponses);
void standardInput(vector <string> & scenario, ifstream & introFile, string & prevUserResponse, string & currentUserResponse, string & totalResponses, int & choiceStage);

// decide what to do with input
void replaceIfNecessary(bool shouldReplace, string & line, string & replaceStr);

// deal with text file lines
//void addLinesToVector(ifstream & inputFile, const string & line, vector<string> & lineVector);

//UNUSED
string dealWithRepeatAnswer(const string & prevUserResponse, const vector <string> & scenario);

//---------------------------- USER RESPONSE GATHERING FUNCTIONS-------------------------------------//

// Prompts the user for a response, and returns it as a string
string getResponse(char response) {
	// Asks user for an input
	cout << "> ";
	cin.get(response);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return dealWithUserResponse(response);
}

// Makes sure that user input is valid
string dealWithUserResponse(char response)
{
	if (responseIsValid(response))
	{
		//Increment the number of successful user responses
		cout << endl;
		return to_string(toupper(response));
	}

	else
	{
		cout << "Please choose a valid input." << endl;
		return getResponse(response);
	}

}

bool answerIsADuplicate(string prevUserResponse, string currentUserResponse)
{
	return prevUserResponse == currentUserResponse;
}



// Fetches a line from the specified file
void fetchLineFromFile(ifstream file_name, string & line) {
	getline(file_name, line);
}
//---------------------------------------------------------------------------------------------------//


//-----------------------------------PRINT LINE FUNCTIONS--------------------------------------------//

void printOptions(vector<string> & lines)	// For multiple choice answers, this will print the lines in a chunk, rather than having to press enter between each line
{
	for (auto line : lines)
		Reader.PrintLineWithoutEnter(line);
}

void printOptionsIfNecessary(string &line, vector<string> &stringVector, ifstream &inputFile)
{
	//int len = line.length();
	const char * start = "OS";
	const char * end = "OE";
	const char * curr = line.c_str();

	if (strcmp(line.c_str(),start) && strcmp(line.c_str(),end))     //prints out line, using word wrap function so that the lines fit nicely in the console window.
	{
		//cout << "Strcmp: " << strcmp(curr,start) << endl;
		Reader.PrintLine(line);
	}
		
	else if (!strcmp(line.c_str(),start))
	{
		// progress to the next line
		getline(inputFile, line);
		// create an array
		vector<string> optionLines;
		int count = 0;
		//cout << "entered loop\n" << endl;
		while (strcmp(line.c_str(),end))
		{
			stringVector.push_back(line);
			optionLines.push_back(line);
			//cout << "Added: " << line << "to vector" << endl;
			getline(inputFile, line);
		}
		
		printOptions(optionLines);
		//cout << "exited Loop" << endl;
	}
}


void printLinesAndScanToVector(ifstream & inputFile, vector <string> & stringVector, string & lineStatus, const bool & shouldReplace, string replaceStr)
{
	string line;
	string enterForCont;
	while (getline(inputFile, line))
	{
		//cout << "nig\n";
		if (changedLineStatus(line, lineStatus)) // If the status changes at all, break from the loop
			break;
		replaceIfNecessary(shouldReplace, line, replaceStr);
		stringVector.push_back(line);
		printOptionsIfNecessary(line, stringVector,inputFile);  
	}
}

void printString(const string & str)
{
	//string pressEnterToContinue;
	cout << endl;
	cout << str << endl;
	cout << endl;
	//getline(cin, pressEnterToContinue);

}


//-------------------------------------------------------------------------------------------------------//


//-----------------------------------UTILITY FUNCTIONS-----------------------------------------------------//
//vector<string> combineOptions(ifstream inputFile, vector<string> & optionString)
//{
//	string line; 
//	while (getline(inputFile, line))
//	{
//		if (line != "O")
//			optionString.push_back(line);
//	}
//		
//}

//void addLinesToVector(ifstream & inputFile, const string & line, vector<string> & lineVector)
//{
//	if (line == "OPTIONS START")
//	{
//		vector<string> optionString;
//		combineOptions(inputFile, optionString);
//		lineVector.push_back(optionString);
//	}
//	else
//		lineVector.push_back(line);
//}

string dealWithRepeatAnswer(const string & prevUserResponse, const vector <string> & scenario)
{
	printVectorScenario(scenario);
	string currentUserResponse = getResponse();

	if (answerIsADuplicate(prevUserResponse, currentUserResponse))
		return dealWithRepeatAnswer(prevUserResponse, scenario);
	return currentUserResponse;
}
// Using a specific array, check if a given response is inside
//bool checkResponseValidity(char response) {
//	char responses[] = { 'a','b','c','A','B','C' };
//	return responseIsValid(response, responses);
//}

bool userChoiceMatchesTrigger(const string & choiceTrigger, const string & userChoice)
{
	return (userChoice == choiceTrigger);
}

bool stageMatchesTrigger(int trigger, int stage)
{
	return (trigger == stage);
}

void printVectorScenario(const vector <string> & vectorStr)
{
	const char * start = "OS";
	const char * end = "OE";
	vector<string> optionLines;
	int noPrint = 0;
	for (auto line : vectorStr)
	{
		const char * curr = line.c_str();
		if (!noPrint && strcmp(line.c_str(), start))     //prints out line, using word wrap function so that the lines fit nicely in the console window.
		{
			//cout << "Strcmp: " << strcmp(curr,start) << endl;
			Reader.PrintLine(line);
		}
		else if (!strcmp(line.c_str(), start))
			++noPrint;
		else if (strcmp(line.c_str(),end))
		{
				//stringVector.push_back(line);
				optionLines.push_back(line);
				//cout << "Added: " << line << "to vector" << endl;
				//getline(inputFile, line);
		}
		else
			break;
			//cout << "exited Loop" << endl;
	}
	printOptions(optionLines);
	//for_each(vectorStr.begin(), vectorStr.end(), printString);
}

// loops scenario
void loopScenario(const vector <string> & dialogue)
{
	printVectorScenario(dialogue);
}

void setCurrentToPrev(string & currentUserChoice, string & prevUserChoice)
{
	prevUserChoice = currentUserChoice;
}

void handleEndOfChoice(ifstream & inputFile, string & prevUserChoice, string & currentUserChoice, string & totalResponses)
{
	setCurrentToPrev(currentUserChoice, prevUserChoice);
	appendOptionToTotal(totalResponses, currentUserChoice);
	findOptionInFile(totalResponses, inputFile);
}

void loopForCertainOption(const vector <string> & dialogue, ifstream & inputFile, const string & choiceTrigger, string & currentUserChoice, string & prevUserChoice, string & totalResponses)
{
	currentUserChoice = getResponse();
	while (currentUserChoice == choiceTrigger) {
		loopScenario(dialogue);
		currentUserChoice = getResponse();
	}
	handleEndOfChoice(inputFile, prevUserChoice, currentUserChoice, totalResponses);
}

void replaceIfNecessary(bool shouldReplace, string & line, string & replaceStr) {
	if (shouldReplace)
	{
		int indexIfFound = line.find("REPLACE");
		if (indexIfFound != string::npos)
		{
			line.replace(indexIfFound, 7, replaceStr);
		}
	}
}

void standardInput(vector <string> & scenario, ifstream & introFile, string & prevUserResponse, string & currentUserResponse, string & totalResponses, int & choiceStage)
{
	currentUserResponse = getResponse();
	prevUserResponse = currentUserResponse;
	appendOptionToTotal(totalResponses, currentUserResponse);
	findOptionInFile(totalResponses, introFile);
}


//Get an input from the user that isn't an a multiple choice answer (ie. entering name)
void inputCertainText(ifstream & introFile, string & prevUserResponse, string & currentUserResponse, string & totalResponses, string & inputText, bool & replaceText, SaveState & S)
{
    Reader.PrintLineWithoutEnter("");
	cout << "> ";
	getline(cin, inputText);
	S.SetPlayerName(inputText);		// Hard codes for only saving Names as 'Long Inputs'; Must change for 'Long Inputs' that do not involve the Player Name
	cout << endl;
	findOptionInFile(totalResponses, introFile);
	replaceText = true;
}


void iterateThroughChoices(string & totalResponses, string & prevUserResponse, string & currentUserResponse, ifstream & introFile, int & choiceNumber, SaveState & S)
{
	//replaceString allows us to store certain data and replace stuff in the text file with the data, using the function printLinesAndScanToVector
	bool replaceString = false;
	string inputText;
	while (introFile.is_open()) {
		// This vector will hold the lines of text that were just printed out, just in case the user decides to choose an option that
		// requires this text to be repeated
		vector <string> scenario;
		string lineStatus;
		// Prints out current situation and saves it to 'scenario' vector
		printLinesAndScanToVector(introFile, scenario, lineStatus, replaceString, inputText);
		//Checks each line to see
		if (lineStatus == "E")
			break;
		// Standard multiple choice input
		else if (lineStatus == "I")
			standardInput(scenario, introFile, prevUserResponse, currentUserResponse, totalResponses, choiceNumber);
		// Repeat if player chooses "B"
		else if (lineStatus == "RB")
			loopForCertainOption(scenario, introFile, "66", currentUserResponse, prevUserResponse, totalResponses);
		// Long input
		else if (lineStatus == "LI")
		{
			inputCertainText(introFile, prevUserResponse, currentUserResponse, totalResponses, inputText, replaceString, S);
			replaceString = true;
		}
		else if (lineStatus == "SK")
		{
			findOptionInFile(totalResponses, introFile);
		}
	}
}

bool changedLineStatus(string line, string & lineStatus)
{
	if (line.length() <= 2)
	{
		string statuses[] = { "I", "E", "L", "RB", "LI", "SK" };
		for (int i = 0; i < sizeof(statuses) / sizeof(statuses[0]); ++i)
		{
			// If the given line matches a status code, return the code. else, return an empty string.
			if (statuses[i] == line)
			{
				lineStatus = statuses[i];
				return true;
			}
		}
	}
	return false;
}

// Clears all previous options that the user has chosen
void clearAllVars(string & totalResponses, string & prevUserResponse, string & currentUserResponse)
{
	totalResponses = "";
	prevUserResponse = " ";
	currentUserResponse = " ";
}

// Adds the current option char to the total responses string.
void appendOptionToTotal(string & totalResponses, string currentUserResponse)
{
	totalResponses += currentUserResponse;
}

// checks if the response character is found inside the responses array; returns bool value of result
bool responseIsValid(const char & response)
{
	char responses[] = { 'a','b','c','A','B','C' };
	for (int i = 0; responses[i] != '\0'; ++i)
	{
		if (response == responses[i])
			return true;
	}
	return false;
}

// Once the user chooses an option, this function will deal with finding the starting line of the result situation.
void findOptionInFile(string response, ifstream & file)
{
	string line;
	while (getline(file, line))
	{
		// if the line matches the specified response string, break.
		if (line == response)
		{
			//cout << "Found line: " << line << endl;
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------------//

void startChoiceScene(string str, SaveState & S)
{
	ifstream introFile(str);
	string totalResponses = "0";
	//currentUserResponse represent the current user's respose AFTER it is checked for validity and converted into a string so that it can be appended to totalResponses
	string prevUserResponse = " ";
	string currentUserResponse;
	int choiceNumber = 0;
	iterateThroughChoices(totalResponses, prevUserResponse, currentUserResponse, introFile, choiceNumber, S);
	introFile.close();
	return;
}

//----------------------------------- UNUSED FUNCTIONS --------------------------------

// Will print lines until you get to the next "Wait for user input" line
void printLines(ifstream & inputFile)
{
	string line;
	while (getline(inputFile, line))
	{
		if (line == "Wait for user input")
			break;
		cout << line << endl;

	}
}

//Until you reach the ending character of that specific section, print out lines.
void printOptionText(string response, ifstream & file) {
	string line;
	while (getline(file, line)) {
		if (line == response)
			break;
		else
			cout << line << endl;
	}
}

//void inputCertainText();

//void iteratethroughchoices(string & totalresponses, string & prevuserresponse, string & currentuserresponse, ifstream & introfile, int & choicenumber)
//{
//	while (introfile.is_open()) {
//
//		// this vector will hold the lines of text that were just printed out, just in case the user decides to choose an option that
//		// requires this text to be repeated
//		vector <string> scenario;
//		string linestatus;
//		// prints out current situation and saves it to 'scenario' vector
//		printlinesandscantovector(introfile, scenario, linestatus);
//		//checks each line to see 
//		if (linestatus == "e")
//			break;
//		else if (linestatus == "i")
//			standardinput(scenario, introfile, prevuserresponse, currentuserresponse, totalresponses, choicenumber);
//		else if (linestatus == "rb")
//			loopforcertainoption(scenario, introfile, "66", currentuserresponse, prevuserresponse, totalresponses);
//		//else if (linestatus == "n")
//			//inputcertaintext();
//	}
//
//}

//bool isBlank(string input)
//{
//	cout << "User input: " << input << "..." << endl;
//	return input == "" || input == "\n";
//}

//int main() {
//	ifstream introfile("IntroResponses.txt");
//
//	string totalresponses = "";
//	//currentuserresponse represent the current user's respose after it is checked for validity and converted into a string so that it can be appended to totalresponses
//	string prevuserresponse = " ";
//	string currentuserresponse;
//	int choicenumber = 0;
//	iterateThroughChoices(totalresponses, prevuserresponse, currentuserresponse, introfile, choicenumber);
//	introfile.close();
//
//	clearAllVars(totalresponses, prevuserresponse, currentuserresponse);
//	introfile.open("nurse.txt");
//	iterateThroughChoices(totalresponses, prevuserresponse, currentuserresponse, introfile, choicenumber);
//	return 0;
//}
