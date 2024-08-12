#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include<string>
#define EDGE 10
class InteractionArea
{
private:
    std::string m_name;
    int m_xpos;
    int m_ypos;
    int m_width;
    int m_height;
    sf::RectangleShape m_area;

public:
    InteractionArea(int xpos, int ypos, int width, int height, std::string name);
    ~InteractionArea();
    sf::RectangleShape getArea();
    void setColor(sf::Color color);
    bool isPlayerWithinArea(sf::Vector2f location);
    std::string getName();
    sf::Vector2f getPos();


};
