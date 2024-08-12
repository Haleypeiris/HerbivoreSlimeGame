#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include<string>
class InteractionArea
{
private:
    std::string m_name;
    int m_xpos;
    int m_ypos;
    int m_width;
    int m_height;
    sf::RectangleShape area;

public:
    InteractionArea(int xpos, int ypos, int width, int height, std::string name);
    ~InteractionArea();
    sf::RectangleShape get_area();
    void set_color(sf::Color color);
    bool is_mouse_within_area(sf::Vector2f location);
    std::string get_name();
    sf::Vector2f getPos();


};
