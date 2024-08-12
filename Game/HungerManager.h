#pragma once

#define MAX_HUNGER 10

class HungerManager
{
private:
	int m_hunger_levels;
	
public:
	int m_max_hunger_levels;
	HungerManager(int value);
	int getHungerLevels();
	void print();
	void increaseHungerLevels(int value);
	void decreaseHungerLevels(int value);
};

