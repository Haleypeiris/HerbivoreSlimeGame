#pragma once
#include <iostream>
#include "HungerManager.h"

HungerManager::HungerManager(int value)
{
	m_max_hunger_levels = MAX_HUNGER;
	m_hunger_levels = value;
	if (value > MAX_HUNGER)
	{
		m_hunger_levels = 10;
	}
}

int HungerManager::getHungerLevels()
{
	return m_hunger_levels;
}
void HungerManager::print()
{
	std::cout << "Hunger Levels " << m_hunger_levels << std::endl;
}

void HungerManager::decreaseHungerLevels(int value)
{
	m_hunger_levels -= value;
	if (m_hunger_levels <= 0)
	{
		m_hunger_levels = 0;
		std::cout << "Too Hungry" << std::endl;
	}
}

void HungerManager::increaseHungerLevels(int value)
{
	m_hunger_levels += value;
	if (m_hunger_levels > MAX_HUNGER)
	{
		m_hunger_levels = 10;
	}
}