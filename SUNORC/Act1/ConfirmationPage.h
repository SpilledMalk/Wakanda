#pragma once
#include <iostream>
#include "Page.h"

class ConfirmationPage :
	public Page {

public:
	void getResponse(string & currentItem, int & pageNum, bool & terminate) {
		bool input_valid = false;
		char legalOptions[3] = "xX";
		char response;
		int fail_counter = 0;
		//This while loop checks to see if the user's input is in legalOptions
		while (!input_valid) {
			cin >> response;
			input_valid = checkInputValid(response, legalOptions);
			if (!input_valid)
			{
				fail_counter++;
				if (fail_counter >= 3) {
					cout << "Fine. Press any key to continue... Nigguh." << endl;
					cin >> response;
					break;
				}
				else
					cout << "Porch Coon-Nigger Sand Monkey" << endl;
			}
		}
		terminate = true;
		// something like: saveItemOption(currentItem)
	}
private:
	static bool checkInputValid(char response, char * options) {
		// loops through legal/valid responses to see if input is valid
		for (int i = 0; options[i] != '\0'; ++i) 
		{
			if (options[i] == response)
				return true;
		}
		return false;
	}
};