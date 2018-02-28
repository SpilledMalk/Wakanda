using namespace std;

#include "DescriptionPage.h"
#include <iostream>

void DescriptionPage::getResponse(std::string & currentItem, int & pageNum, bool & term)
{
	bool input_valid = false;
	char legalOptions[5] = "bBpP";
	char choice;
	while (!input_valid) {
		cin >> choice;
		input_valid = DescriptionPage::checkInputValid(choice, legalOptions);
		if (!input_valid)
			cout << "Look man, you only have two options... Click it or ticket... Be there or be square... Soup or salad... Nigguh." << endl;
	}
	if  (choice == 'b' || choice == 'B')
	{
		currentItem = ""; 
		pageNum--;
	}
	else if(choice == 'p' || choice == 'P')
	{
		pageNum++;
	}
}

bool DescriptionPage::checkInputValid(char response, char * options) {
	for (int i = 0; options[i] != '\0'; ++i)
	{
		if (options[i] == response)
			return true;
	}

	return false;
}