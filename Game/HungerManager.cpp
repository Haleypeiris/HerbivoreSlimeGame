#pragma once
#include <iostream>
#include "HungerManager.h"

#define MAX_HUNGER 10

HungerManager::HungerManager(int value)
{
	max_hunger_levels = MAX_HUNGER;
	hunger_levels = value;
	if (value > MAX_HUNGER)
	{
		hunger_levels = 10;
	}
}

int HungerManager::get_hunger_levels()
{
	return hunger_levels;
}
void HungerManager::print()
{
	std::cout << "Hunger Levels " << hunger_levels << std::endl;
}

void HungerManager::decrease_hunger_levels(int value)
{
	hunger_levels -= value;
	if (hunger_levels <= 0)
	{
		hunger_levels = 0;
		std::cout << "Too Hungry" << std::endl;
	}
}

void HungerManager::increase_hunger_levels(int value)
{
	hunger_levels += value;
	if (hunger_levels > MAX_HUNGER)
	{
		hunger_levels = 10;
	}
}