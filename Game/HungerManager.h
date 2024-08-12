#pragma once


class HungerManager
{
private:
	int hunger_levels;
	
public:
	int max_hunger_levels;
	HungerManager(int value);
	int get_hunger_levels();
	void print();
	void increase_hunger_levels(int value);
	void decrease_hunger_levels(int value);
};

