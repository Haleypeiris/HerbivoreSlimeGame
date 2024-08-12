#include "Player.h"

void Player::initPhysics()
{
	this->m_max_velocity = 1.6f;
	this->m_min_velocity = 1.f;
	this->m_acceleration = 2.f;
	this->m_drag = 0.94f;
}

Player::Player(const std::string& text)
	:SpriteClass(text)
{
	this->initVariables();
	this->initAnimations();
	this->initPhysics();
	this->m_currentFrame = sf::IntRect(0, 0, 32, 32);
	this->returnSprite()->setTextureRect(this->m_currentFrame);
	this->returnSprite()->setScale(1.5f, 1.5f);
	
}

Player::~Player()
{
}

void Player::initAnimations()
{
	this->m_animationTimer.restart();
}

void Player::updateMovement()
{	
	this->m_animation_state = Player_Idle;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->move(-1.f, 0.f);
		this->m_animation_state = Player_Moving_Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->move(1.f, 0.f);	
		this->m_animation_state = Player_Moving_Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->move(0.f, -1.f);	
		this->m_animation_state = Player_Moving_Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->move(0.f, 1.f);	
		this->m_animation_state = Player_Moving_Down;
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
	this->updatePos();
}

void Player::updateAnimations()
{
	if (this->m_animation_state == Player_Idle)
	{
		//Values are defined based on the spritesheet size
		if (this->m_animationTimer.getElapsedTime().asSeconds() >= 0.1)
		{
			this->m_currentFrame.top = 192;
			this->m_currentFrame.left = (m_currentFrame.left + SPRITE_BODY) % (END_OF_SPRITE_SHEET);
			this->m_animationTimer.restart();
			this->returnSprite()->setTextureRect(this->m_currentFrame);
		}

		this->returnSprite()->setScale(1.5, 1.5);
		this->returnSprite()->setOrigin(0.f, 0.f);
	}
	else if (this->m_animation_state == Player_Moving_Right)
	{
		if (this->m_animationTimer.getElapsedTime().asSeconds() >= 0.1)
		{
			this->m_currentFrame.top = 224;
			this->m_currentFrame.left = (m_currentFrame.left + SPRITE_BODY) % (END_OF_SPRITE_SHEET);
			this->m_animationTimer.restart();
			this->returnSprite()->setTextureRect(this->m_currentFrame);
		}

		this->returnSprite()->setScale(1.5, 1.5);
		this->returnSprite()->setOrigin(0.f, 0.f);

	}
	else if (this->m_animation_state == Player_Moving_Left)
	{
		if (this->m_animationTimer.getElapsedTime().asSeconds() >= 0.1)
		{
			this->m_currentFrame.top = 224;
			this->m_currentFrame.left = (m_currentFrame.left + SPRITE_BODY) % (END_OF_SPRITE_SHEET);
			this->m_animationTimer.restart();
			this->returnSprite()->setTextureRect(this->m_currentFrame);
		}

		this->returnSprite()->setScale(-1.5, 1.5); //1.5 is the original scaling factor, -ve is the flip version
		this->returnSprite()->setOrigin(this->returnSprite()->getGlobalBounds().width / 1.5f, 0.f);

	}
	else if (this->m_animation_state == Player_Moving_Up)
	{
		if (this->m_animationTimer.getElapsedTime().asSeconds() >= 0.1)
		{
			this->m_currentFrame.top = 256;
			this->m_currentFrame.left = (m_currentFrame.left + SPRITE_BODY) % (END_OF_SPRITE_SHEET);
			this->m_animationTimer.restart();
			this->returnSprite()->setTextureRect(this->m_currentFrame);
		}

		this->returnSprite()->setScale(1.5, 1.5);
		this->returnSprite()->setOrigin(0.f, 0.f);

	}
	else if (this->m_animation_state == Player_Moving_Down)
	{
		if (this->m_animationTimer.getElapsedTime().asSeconds() >= 0.1)
		{
			this->m_currentFrame.top = 192;
			this->m_currentFrame.left = (m_currentFrame.left + SPRITE_BODY) % (END_OF_SPRITE_SHEET);
			this->m_animationTimer.restart();
			this->returnSprite()->setTextureRect(this->m_currentFrame);
		}

		this->returnSprite()->setScale(1.5, 1.5);
		this->returnSprite()->setOrigin(0.f, 0.f);

	}
	else
	{
		this->m_animationTimer.restart();
	}
}

void Player::updatePhysics()
{
	//deaccel
	this->m_velocity *= this->m_drag;

	//limit deccel
	if (std::abs(this->m_velocity.x) < this->m_min_velocity)
	{
		this->m_velocity.x = 0.f;
	}
	if (std::abs(this->m_velocity.y) < this->m_min_velocity)
	{
		this->m_velocity.y = 0.f;
	}

	this->returnSprite()->move(this->m_velocity);
}

void Player::move(const float dir_x, const float dir_y)
{
	//accel
	this->m_velocity.x += dir_x * this->m_acceleration;
	this->m_velocity.y += dir_y * this->m_acceleration;

	//veloc
	if (std::abs(this->m_velocity.x) > this->m_max_velocity)
	{
		this->m_velocity.x = this->m_max_velocity * ((this->m_velocity.x < 0.f) ? -1.f : 1.f);
	}
	if (std::abs(this->m_velocity.y) > this->m_max_velocity)
	{
		this->m_velocity.y = this->m_max_velocity * ((this->m_velocity.y < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePos()
{
	this->m_pos = this->returnSprite()->getPosition();
}

sf::Vector2f Player::getPos()
{//return the center of the postion
	sf::Vector2f centre;
	centre.x = m_pos.x + 16.f;
	centre.y = m_pos.y + 16.f;
	return centre;
}
void Player::initVariables()
{
	this->m_movement = false;
	this->m_animation_state = Player_Idle;
	this->m_pos = this->returnSprite()->getPosition();
}

