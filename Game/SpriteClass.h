#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <iostream>
class SpriteClass
{
private:
	std::string m_text;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	SpriteClass(const std::string& text);
	~SpriteClass();
	void initSprite();
	void initTexture();
	void render(sf::RenderTarget& target);
	void setTint(sf::Color colour);
	sf::Vector2i size();
	sf::Sprite* returnSprite();
};

