#include "InteractionArea.h"

InteractionArea::InteractionArea(int xpos, int ypos, int width, int height, std::string name) {
    this->m_name = name;
    this->m_xpos = xpos;
    this->m_ypos = ypos;
    this->m_width = width;
    this->m_height = height;
    this->m_area.setPosition(sf::Vector2f(xpos, ypos));
    this->m_area.setSize(sf::Vector2f(width, height));
    this->m_area.setFillColor(sf::Color::Red);

}
InteractionArea::~InteractionArea()
{

}
sf::RectangleShape InteractionArea::getArea()
{
    return this->m_area;
}
void InteractionArea::setColor(sf::Color color)
{
    this->m_area.setFillColor(color);
}
bool InteractionArea::isPlayerWithinArea(sf::Vector2f location)
{
    //checks if object is within certain amount of pixels of a location
    if ((location.x >= m_xpos-EDGE) && (location.x <= m_xpos + m_width+ EDGE) && (location.y >= m_ypos- EDGE) && (location.y <= m_ypos + m_height+ EDGE))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string InteractionArea::getName()
{
    return this->m_name;
}
sf::Vector2f InteractionArea::getPos()
{
    return sf::Vector2f(this->m_xpos, this->m_ypos);
}