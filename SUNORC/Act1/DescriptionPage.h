#pragma once
#include <string>
#include "Page.h"

class DescriptionPage : public Page
{
public:
	void getResponse(string &, int &, bool &);
private:
	bool checkInputValid(char, char*);
};