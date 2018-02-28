#pragma once
#include <iostream>
#include <string>
#include "Page.h"
#include "ListingsPage.h"
#include "DescriptionPage.h"
#include "ConfirmationPage.h"

class PageHandler
{
public:
	explicit PageHandler(Page ** pagesList, int pageNum);
	void startPageLoop();
	string getCurrentItem();
private:
	bool terminate = false;
	string currentItem;
	int currentPage;
	Page ** pageList;
};