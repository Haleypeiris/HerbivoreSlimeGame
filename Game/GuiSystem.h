#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

#include "HungerManager.h"

class GuiSystem
{
private:
    HungerManager* hunger_levels;
    float hp_bar_max_width;
    sf::RectangleShape hp_bar_back;
    sf::RectangleShape hp_bar_inner;

public:
    GuiSystem(HungerManager* hunger);

    void init_hp_bar();
    void render_hp_bar(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
    void update_hp_bar();
};