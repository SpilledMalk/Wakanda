#include <iostream>
#include <string>

using namespace std;

#include "PageHandler.h"
#include "ListingsPage.h"
#include "DescriptionPage.h"
#include "ConfirmationPage.h"
#include "Act1WeaponPick.h"
#include "../SaveState.h"

void chooseStarterWeapon(SaveState & S)
{
	ListingsPage Listings = ListingsPage();
	DescriptionPage Descriptions = DescriptionPage();
	ConfirmationPage Confirmations = ConfirmationPage();
	Page * PageList[] = { &Listings, &Descriptions, &Confirmations };
	PageHandler Handler(PageList, 0);
	Handler.startPageLoop();
	S.SetBaseWeapon(Handler.getCurrentItem());
	return;
}