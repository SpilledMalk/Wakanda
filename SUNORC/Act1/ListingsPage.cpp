using namespace std;

#include "ListingsPage.h"



void ListingsPage::printPage(const string & Item)
{
	std::ifstream ListingWindow("Act1/ListingWindow.txt"); // uses "Ivrit" ASCII art font for listings text and "Big" ASCII art font for amazon 
													  //std::ifstream ListingWindow("ListingText.txt");
	std::string line;
	while (getline(ListingWindow, line))
	{
		cout << line << endl;
	}
}

void ListingsPage::getResponse( string & currentItem, int & pageNum, bool & terminate)
{
	map<int, string> Listing = { { '1', "Gauntlets" }, { '2', "SlingBlade" }, { '3', "Blaster" } };
	bool input_valid = false;
	char legalOptions[4] = "123";

	char choice;
	while (!input_valid)
	{
		cout << "Choose a listing number: ";
		cin >> choice;
		input_valid = ListingsPage::checkInputValid(choice, legalOptions);
		if (!input_valid) {
			if (choice == '4')	// Put Jandro hentai voice here
				cout << "First... it says Sold Out. Second... why tho. Third... Nigguh." << endl;
			else
				cout << "Psyche! That's the wrong INPUT!... Nigguh." << endl;
		}
	}
	currentItem = Listing[choice];
	pageNum++;
}

bool ListingsPage::checkInputValid(char response, char * options) {
	for (int i = 0; options[i] != '\0'; ++i)
	{
		if (options[i] == response)
			return true;
	}

	return false;
}
