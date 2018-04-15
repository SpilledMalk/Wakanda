#include "Character.h"
#include <list>
#include <map>

using namespace std;

void printItems(map<int, Item> items) 
{
	// iterates to last position in map
	map<int, Item>::const_iterator itr = items.end();
	--itr;

	// prints all values before last position with a comma
	for (map<int, Item>::const_iterator it = items.begin();
		it != itr; ++it)
	{
		cout << it->second.Name << ", ";
	}

	// prints last position in map
	cout << itr->second.Name;
	cout << endl;
 };

void printMoves(map<int, Move> moves)
{
	// iterates to last position in map
	map<int, Move>::const_iterator itr = moves.end();
	--itr;

	// prints all values before last position with a comma
	for (map<int, Move>::const_iterator it = moves.begin();
		it != itr; ++it)
	{
		cout << it->second.Name << " \"" << it->second.Effect << "\"" << ", ";
	}

	// prints last position in map
	cout << itr->second.Name << " \"" << itr->second.Effect << "\"";
	cout << endl;
};

int main()
{
	string a;
	map<int, Item> Items = { { 1, Item("Shrooms", 3, "-2 to Int")}, { 2, Item("More Shrooms", 4, "-3 to Int") } };
	map<int, Move> Moves = { { 1, Move("Penetrate", 2, "65% chance to clog") },{ 2, Move("Molest", 4, "Enemy is confused") } };
	CounterBox Counters = CounterBox(9001, 9001, 10, 10);
	
	Character s = Character("xXJesus420Xx", Weapon("Dildo Bat", 10, 69), Counters, Moves, Items, "Trippin'", Point(3, 12), 'X', CharStats{ 13, 8, 17, 150, 240 });
	cout << "           Name: " << s.GetCharName() << endl;
	cout << "         Weapon: " << s.GetCharWeapon().Name << endl;
	cout << "   Attack Range: " << s.GetCharWeapon().AttackRange << endl;
	cout << "Travel Distance: " << s.GetCounterBox().MaxMoveCount << endl;
	cout << "  Action Points: " << s.GetCounterBox().MaxActionCount << endl;
	cout << "         Health: " << s.GetCharStats().CurHP<< "/" << s.GetCharStats().MaxHP << endl;
	cout << "      Move List: ";
	printMoves(s.GetMoveList());
	cout << "      Item List: ";
	printItems(s.GetItemList());
	cout << "  Status Effect: " << s.GetCharStatus() << endl;
	cout << " Field Location: ";
	s.GetCharLoc().print();
	cout << endl;
	cout << "   Field Symbol: " << s.GetCharSymbol() << endl;
	cout << "Character Stats: " << "Atk(" << s.GetCharStats().Atk << "), " << "Def(" << s.GetCharStats().Def << "), " << "Spd(" << s.GetCharStats().Spd << "), " << "MaxHP(" << s.GetCharStats().MaxHP << ")"<< endl;
	cin >> a;
}