#include "Character.h"
#include <list>
#include <map>

using namespace std;

void printMovesOrItems(map<int, Item> items) 
{
	for (map<int, Item>::const_iterator it = items.begin();
		it != items.end(); ++it)
	{
		cout << it->second.Name << ", ";
	}
	cout << endl;
 };

int main()
{
	string a;
	map<int, Item> Items = { {1, Item("Shrooms", 3, "-2 to Int")}, { 2, Item("More Shrooms", 4, "-3 to Int") } };
	
	Character s = Character("xXJesus420Xx", Weapon("Dildo Bat", 10, 69), 9001, 10, 150, { "Penetrate", "Molest" }, Items, "Trippin'", Point(3, 12), 'X', CharStats{ 13, 8, 17, 240 });
	cout << "           Name: " << s.GetCharName() << endl;
	cout << "         Weapon: " << s.GetCharWeapon().GetWeaponName() << endl;
	cout << "   Attack Range: " << s.GetCharWeapon().AttackRange << endl;
	cout << "Travel Distance: " << s.GetMaxMoveCount() << endl;
	cout << "  Action Points: " << s.GetMaxActionCount() << endl;
	cout << "         Health: " << s.GetCurrentHP()<< "/" << s.GetCharStats().MaxHP << endl;
	//cout << "      Move List: ";
	//printMovesOrItems(s.GetMoveList());
	cout << "      Item List: ";
	printMovesOrItems(s.GetItemList());
	cout << "  Status Effect: " << s.GetCharStatus() << endl;
	cout << " Field Location: ";
	s.GetCharLoc().print();
	cout << endl;
	cout << "   Field Symbol: " << s.GetCharSymbol() << endl;
	cout << "Character Stats: " << "Atk(" << s.GetCharStats().Atk << "), " << "Def(" << s.GetCharStats().Def << "), " << "Spd(" << s.GetCharStats().Spd << "), " << "MaxHP(" << s.GetCharStats().MaxHP << ")"<< endl;
	cin >> a;
}