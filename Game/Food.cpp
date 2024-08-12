#include "Food.h"


Food::Food(int xpos, int ypos, int width, int height, std::string name, Daycycle time, std::string texture)
	:InteractionArea{ xpos, ypos, width, height, name }
	,m_eatingtime{ time }
	,m_filepath{ texture }
	{
	initTexture();
	initSprite();
	}

Food::~Food()
{

}

void Food::initSprite()
{
	this -> m_sprite.setTexture(this->m_texture);
	this -> m_sprite.setPosition(this->getPos());
}

void Food::initTexture()
{
	this->m_texture.loadFromFile(m_filepath);
}

void Food::render(sf::RenderTarget& target)
{
	target.draw(this->m_sprite);
}

bool Food::canFoodBeEatenNow(Daycycle time) 
{
	if (time == this->m_eatingtime)
	{
		return true;
	}
	else
	{
		return false;
	}
}