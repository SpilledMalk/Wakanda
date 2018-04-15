#pragma once
#include <string>
#include <vector>
#include "Point.cpp"
#include <map>

using namespace std;

struct CharStats 
{
	int Atk;
	int Def;
	int Spd;
	int MaxHP;

	explicit CharStats(int Attack, int Defense, int Speed, int MaxHealth);
	CharStats(const CharStats& inChar);
};

struct Weapon
{
	string Name;
	int AttackModifier;
	int AttackRange;

	string GetWeaponName();
	explicit Weapon(string Name, int AttackModifier, int AttackRange);
	Weapon(const Weapon& inWeap);
};

struct Item
{
	string Name;
	int Quantity;
	string Effect;

	string GetItemName();
	explicit Item(string Name, int Quantity, string Effect);
	Item(const Item& inItem);
};


class Character
{
public:
	Character(			// constructor
		string Name,
		Weapon Weapon,
		int MaxMove,
		int MaxAction,
		int CurrentHealth,
		std::vector<string> Moves,
		map<int, Item> Items,
		string StatusEffect,
		Point Loc,
		char Symbol,
		CharStats inStats);

	string GetCharName();
	void SetCharName(string);

	Weapon GetCharWeapon();
	void SetCharWeapon(Weapon newWeapon);
	
	vector<string> GetMoveList();
	void SetMoveList(vector<string>);
	map<int, Item> GetItemList();

	string GetCharStatus();
	void SetCharStatus(string);

	int GetCurrentHP();
	void SetCurrentHP(int);

	int GetMoveCount();
	void SetMoveCount(int);
	int GetMaxMoveCount();
	void SetMaxMoveCount(int);
	int GetActionCount();
	void SetActionCount(int);
	int GetMaxActionCount();
	void SetMaxActionCount(int);
	void ResetCounters();

	Point GetCharLoc();
	void SetCharLoc(Point);
	char GetCharSymbol();
	void SetCharSymbol(char);

	CharStats GetCharStats();

private:
	string CharName;
	Weapon CharWeapon;

	vector<string> MoveList; // rather than a vector of strings, should be a MAP of Move type objects
	map<int, Item> ItemList; // same thing as above but with Item type objects omfg

	string CharStatus;
	int CurrentHP;

	int MoveCount;
	int MaxMoveCount;
	int ActionCount;
	int MaxActionCount;
	Point CharLoc;
	char CharSymbol;
	CharStats Stats;
};