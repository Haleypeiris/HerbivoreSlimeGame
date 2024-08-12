#include "SpriteClass.h"

SpriteClass::SpriteClass(const std::string& text)
{
	this->m_text = text;
	initTexture();
	initSprite();
}

SpriteClass::~SpriteClass()
{
}

void SpriteClass::initSprite()
{
	this->m_sprite.setTexture(this->m_texture);
}

void SpriteClass::initTexture()
{
	this->m_texture.loadFromFile(m_text);
}

void SpriteClass::render(sf::RenderTarget& target)
{
	target.draw(this->m_sprite);
}

void SpriteClass::setTint(sf::Color colour)
{
	this->m_sprite.setColor(colour);
}

sf::Vector2i SpriteClass::size()
{
	int height = this->m_sprite.getLocalBounds().height;
	int width = this->m_sprite.getLocalBounds().width;
	return sf::Vector2i(width, height);
}

sf::Sprite* SpriteClass::returnSprite()
{
	return &m_sprite;
}
