#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "Page.h"

class ListingsPage : public Page
{
public:
	void printPage(const string &); 
	void getResponse(string &, int &, bool &);
private:
	bool checkInputValid(char, char*);
};