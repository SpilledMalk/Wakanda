#include "Character.h"
#include <map>

CharStats::CharStats(int Attack, int Defense, int Speed, int MaxHealth)
	: Atk(Attack), Def(Defense), Spd(Speed), MaxHP(MaxHealth)
{
}

CharStats::CharStats(const CharStats& inChar)
	: Atk(inChar.Atk), Def(inChar.Def), Spd(inChar.Spd), MaxHP(inChar.MaxHP)
{
}

string Weapon::GetWeaponName() { return Name; }

Weapon::Weapon(string Name, int AttackModifier, int AttackRange)
	: Name(Name), AttackModifier(AttackModifier), AttackRange(AttackRange)
{
}

Weapon::Weapon(const Weapon& inWeap)
	: Name(inWeap.Name), AttackModifier(inWeap.AttackModifier), AttackRange(inWeap.AttackRange)
{
}

string Item::GetItemName() { return Name; }

Item::Item(string Name, int Quantity, string Effect)
	: Name(Name), Quantity(Quantity), Effect(Effect)
{
}

Item::Item(const Item& inItem)
	: Name(inItem.Name), Quantity(inItem.Quantity), Effect(inItem.Effect)
{
}

// constructor
Character::Character(		// constructor
	string Name,	
	Weapon Weapon,
	int MaxMove,
	int MaxAction,
	int CurrentHealth,
	vector<string> Moves,
	map<int, Item> Items,
	string StatusEffect,
	Point Loc,
	char Symbol,
	CharStats inStats)
	: CharName(Name), CharWeapon(Weapon), MaxMoveCount(MaxMove), MoveCount(MaxMove), MaxActionCount(MaxAction), ActionCount(MaxAction),
		CurrentHP(CurrentHealth), MoveList(Moves), ItemList(Items), CharStatus(StatusEffect), CharLoc(Loc), CharSymbol(Symbol), Stats(inStats)
	{
	}

// Character Name
string Character::GetCharName(){ return CharName; }
void Character::SetCharName(string newCharName) { CharName = newCharName; }

// Character Weapons
Weapon Character::GetCharWeapon(){ return CharWeapon; }
void Character::SetCharWeapon(Weapon newWeapon){ CharWeapon = newWeapon; }

// Character Move List and Item List
vector<string> Character::GetMoveList(){ return MoveList; }
void Character::SetMoveList(vector<string> newMoveList) { MoveList = newMoveList; }
map<int, Item> Character::GetItemList(){ return ItemList; }

// Character Status Effect
string Character::GetCharStatus(){ return CharStatus; }
void Character::SetCharStatus(string newStatus) { CharStatus = newStatus; }

// Current Hp
int Character::GetCurrentHP(){ return CurrentHP; }
void Character::SetCurrentHP(int newHP) { CurrentHP = newHP; }

// Move Counter and Action Counter
int Character::GetMoveCount(){ return MoveCount; }
void Character::SetMoveCount(int newMoveCount) { MoveCount = newMoveCount; }
int Character::GetMaxMoveCount() { return MaxMoveCount; }
void Character::SetMaxMoveCount(int newMaxMoveCount) { MaxMoveCount = newMaxMoveCount; }
int Character::GetActionCount(){ return ActionCount; }
void Character::SetActionCount(int newActionCount) { ActionCount = newActionCount; }
int Character::GetMaxActionCount() { return MaxActionCount; }
void Character::SetMaxActionCount(int newMaxActionCount) { MaxActionCount = newMaxActionCount; }
void Character::ResetCounters()
{ 
	MoveCount = MaxMoveCount;
	ActionCount = MaxActionCount;
}

// Character Location
Point Character::GetCharLoc(){ return CharLoc; }
void Character::SetCharLoc(Point newCharLoc) { CharLoc = newCharLoc; }
char Character::GetCharSymbol(){ return CharSymbol; }
void Character::SetCharSymbol(char newCharSymbol) { CharSymbol = newCharSymbol; }

// Character Stats
CharStats Character::GetCharStats() { return Stats; }