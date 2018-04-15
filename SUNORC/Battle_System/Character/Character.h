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
	int CurHP;
	int MaxHP;

	explicit CharStats(int Attack, int Defense, int Speed, int CurHealth, int MaxHealth);
	CharStats(const CharStats& inChar);
};

struct CounterBox
{
	int MoveCount;
	int MaxMoveCount;
	int ActionCount;
	int MaxActionCount;

	explicit CounterBox(int MoveCount, int MaxMoveCount, int ActionCount, int MaxActionCount);
	CounterBox(const CounterBox& inCountBox);
};

// temporary obviously
// SHOULD PROBABLY BE MADE INTO CHARACTER EQUIPMENT AT SOME POINT
struct Weapon
{
	string Name;
	int AttackModifier;
	int AttackRange;

	explicit Weapon(string Name, int AttackModifier, int AttackRange);
	Weapon(const Weapon& inWeap);
};

// temporary obviously
struct Item
{
	string Name;
	int Quantity;
	string Effect;

	explicit Item(string Name, int Quantity, string Effect);
	Item(const Item& inItem);
};

// obviously temporary
struct Move
{
	string Name;
	int Cooldown;
	string Effect;

	explicit Move(string Name, int Cooldown, string Effect);
	Move(const Move& inMove);
};


class Character
{
public:
	Character(			// constructor
		string Name,
		Weapon Weapon,
		CounterBox Counters,
		map<int, Move> Moves,
		map<int, Item> Items,
		string StatusEffect,
		Point Loc,
		char Symbol,
		CharStats inStats);

	string GetCharName();
	void SetCharName(string);

	Weapon GetCharWeapon();
	void SetCharWeapon(Weapon newWeapon);
	
	map<int, Move> GetMoveList();
	void SetMoveList(map<int, Move>);
	map<int, Item> GetItemList();

	string GetCharStatus();
	void SetCharStatus(string);

	CounterBox GetCounterBox();
	void ResetCounters();

	Point GetCharLoc();
	void SetCharLoc(Point);
	char GetCharSymbol();
	void SetCharSymbol(char);

	CharStats GetCharStats();

private:
	string CharName;
	Weapon CharWeapon;

	map<int, Move> MoveList;
	map<int, Item> ItemList;

	string CharStatus;
	int CurrentHP;

	CounterBox Counters;

	Point CharLoc;
	char CharSymbol;
	CharStats Stats;
};