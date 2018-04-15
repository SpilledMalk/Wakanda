#include "Character.h"
#include <map>

CharStats::CharStats(int Attack, int Defense, int Speed, int CurHealth, int MaxHealth)
	: Atk(Attack), Def(Defense), Spd(Speed), CurHP(CurHealth), MaxHP(MaxHealth)
{
}

CharStats::CharStats(const CharStats& inChar)
	: Atk(inChar.Atk), Def(inChar.Def), Spd(inChar.Spd), CurHP(inChar.CurHP), MaxHP(inChar.MaxHP)
{
}

CounterBox::CounterBox(int MoveCount, int MaxMoveCount, int ActionCount, int MaxActionCount)
	: MoveCount(MoveCount), MaxMoveCount(MaxMoveCount), ActionCount(ActionCount), MaxActionCount(MaxActionCount)
{
}

CounterBox::CounterBox(const CounterBox& inCountBox)
	: MoveCount(inCountBox.MoveCount), MaxMoveCount(inCountBox.MaxMoveCount), ActionCount(inCountBox.ActionCount), MaxActionCount(inCountBox.MaxActionCount)
{
}

Weapon::Weapon(string Name, int AttackModifier, int AttackRange)
	: Name(Name), AttackModifier(AttackModifier), AttackRange(AttackRange)
{
}

Weapon::Weapon(const Weapon& inWeap)
	: Name(inWeap.Name), AttackModifier(inWeap.AttackModifier), AttackRange(inWeap.AttackRange)
{
}

Item::Item(string Name, int Quantity, string Effect)
	: Name(Name), Quantity(Quantity), Effect(Effect)
{
}

Item::Item(const Item& inItem)
	: Name(inItem.Name), Quantity(inItem.Quantity), Effect(inItem.Effect)
{
}

Move::Move(string Name, int Cooldown, string Effect)
	: Name(Name), Cooldown(Cooldown), Effect(Effect)
{
}

Move::Move(const Move& inMove)
	: Name(inMove.Name), Cooldown(inMove.Cooldown), Effect(inMove.Effect)
{
}

// constructor
Character::Character(		// constructor
	string Name,	
	Weapon Weapon,
	CounterBox Counters,
	map<int, Move> Moves,
	map<int, Item> Items,
	string StatusEffect,
	Point Loc,
	char Symbol,
	CharStats inStats)
	: CharName(Name), CharWeapon(Weapon), Counters(Counters), MoveList(Moves),
	  ItemList(Items), CharStatus(StatusEffect), CharLoc(Loc), CharSymbol(Symbol), Stats(inStats)
	{
	}

// Character Name
string Character::GetCharName(){ return CharName; }
void Character::SetCharName(string newCharName) { CharName = newCharName; }

// Character Weapons
Weapon Character::GetCharWeapon(){ return CharWeapon; }
void Character::SetCharWeapon(Weapon newWeapon){ CharWeapon = newWeapon; }

// Character Move List and Item List
map<int, Move> Character::GetMoveList(){ return MoveList; }
void Character::SetMoveList(map<int, Move> newMoveList) { MoveList = newMoveList; }
map<int, Item> Character::GetItemList(){ return ItemList; }

// Character Status Effect
string Character::GetCharStatus(){ return CharStatus; }
void Character::SetCharStatus(string newStatus) { CharStatus = newStatus; }

// Move Counter and Action Counter
CounterBox Character::GetCounterBox(){ return Counters; }
void Character::ResetCounters()
{ 
	Counters.MoveCount = Counters.MaxMoveCount;
	Counters.ActionCount = Counters.MaxActionCount;
}

// Character Location
Point Character::GetCharLoc(){ return CharLoc; }
void Character::SetCharLoc(Point newCharLoc) { CharLoc = newCharLoc; }
char Character::GetCharSymbol(){ return CharSymbol; }
void Character::SetCharSymbol(char newCharSymbol) { CharSymbol = newCharSymbol; }

// Character Stats
CharStats Character::GetCharStats() { return Stats; }