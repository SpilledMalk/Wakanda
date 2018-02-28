using namespace std;

#include "PageHandler.h"

PageHandler::PageHandler(Page ** pagesList, int pageNum = 0)
	:currentPage(pageNum), pageList(pagesList), currentItem("")
{
}

void PageHandler::startPageLoop()
{
	string Descriptions[] = { "Gauntlets", "Act1/Gauntlet.txt", "SlingBlade", "Act1/Sling Blade.txt", "Blaster", "Act1/Blaster.txt" };
	pageList[1]->loadPages(3, Descriptions);

	string Confirmations[] = { "Gauntlets", "Act1/ConfirmGauntlet.txt", "SlingBlade", "Act1/ConfirmSlingBlade.txt", "Blaster", "Act1/ConfirmHandCannon.txt" };
	pageList[2]->loadPages(3, Confirmations);

	while (!terminate)
	{
		pageList[currentPage]->printPage(currentItem);
		pageList[currentPage]->getResponse(currentItem, currentPage, terminate);
	}
}

string PageHandler::getCurrentItem() { return currentItem; }