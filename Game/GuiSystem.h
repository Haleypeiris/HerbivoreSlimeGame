#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

#include "HungerManager.h"

class GuiSystem
{
private:
    HungerManager* m_hunger_levels;
    float m_hunger_bar_max_width;
    sf::RectangleShape m_hunger_bar_back;
    sf::RectangleShape m_hunger_bar_inner;

public:
    GuiSystem(HungerManager* hunger);

    void initHungerBar();
    void renderHungerBar(sf::RenderTarget& target);
    void updateHungerBar();
};