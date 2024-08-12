#include "InteractionArea.h"

InteractionArea::InteractionArea(int xpos, int ypos, int width, int height, std::string name) {
    this->m_name = name;
    this->m_xpos = xpos;
    this->m_ypos = ypos;
    this->m_width = width;
    this->m_height = height;
    area.setPosition(sf::Vector2f(xpos, ypos));
    area.setSize(sf::Vector2f(width, height));
    //area.setFillColor(sf::Color::Red);
    area.setFillColor(sf::Color::Red);

}
InteractionArea::~InteractionArea()
{

}
sf::RectangleShape InteractionArea::get_area()
{
    return area;
}
void InteractionArea::set_color(sf::Color color)
{
    area.setFillColor(color);
}
bool InteractionArea::is_mouse_within_area(sf::Vector2f location)
{
    if ((location.x >= m_xpos-8) && (location.x <= m_xpos + m_width+8) && (location.y >= m_ypos-8) && (location.y <= m_ypos + m_height+8))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string InteractionArea::get_name()
{
    return m_name;
}
sf::Vector2f InteractionArea::getPos()
{
    return sf::Vector2f(this->m_xpos, this->m_ypos);
}