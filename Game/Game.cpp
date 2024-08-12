#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initPlayer();
}
Game::~Game()
{
	delete this->m_window;
    delete this->m_background;
    delete this->m_hunger_levels;
    delete this->m_player;
}
void Game::initVariables()
{
    this->m_window = nullptr;
    this->m_time_of_day = Daycycle_Unknown;
    this->m_food_items.clear();
    this->initBackground();
    this->initHungerLevels();
    this->initFoodList();
    this->initText();
}
void Game::initWindow()
{
    //Create the window to match the size of the background image
    sf::Vector2i background_shape = this->m_background->size();
    this->m_video_mode.height = background_shape.y;
    this->m_video_mode.width = background_shape.x;
    this->m_window = new sf::RenderWindow(this->m_video_mode, "Herbivore Slime");
    this->m_window->setFramerateLimit(60);
}
void Game::initBackground()
{
    this->m_background = new SpriteClass("Texture/map.png");
}
void Game::initPlayer()
{
    this->m_player = new Player("Texture/slime.png");
}
void Game::initHungerLevels()
{
    //Starting off with 0 hunger
    this->m_hunger_levels = new HungerManager(0);
    this->m_gui = new GuiSystem(this->m_hunger_levels);
}
void Game::initFoodList()
{
    //Randomize where the fruit is spawnned
    std::srand(m_clock.getElapsedTime().asMilliseconds());
    this->m_food_items.insert(std::make_shared<Food>((std::rand() % 700 + 50), (std::rand() % 500 + 50), 16, 16, "tomato", Daycycle_Night, "Texture/tomato.png"));
    this->m_food_items.insert(std::make_shared<Food>((std::rand() % 700 + 50), (std::rand() % 500 + 50), 16, 16, "pumpkin", Daycycle_Night, "Texture/pumpkin.png"));
}

void Game::initText()
{
    //set font and style as a default value
    if (!this->m_font.loadFromFile("Font/Logam.otf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    this->m_text.setFont(this->m_font);
    this->m_text.setFillColor(sf::Color::Black);
    this->m_text.setCharacterSize(30);
}

void Game::update()
{
    if (this->m_gamestate == GameState_Start)
    {
        this->startMenu();
    }
    else if (this->m_gamestate == GameState_End)
    {
        this->endMenu();
    }
    else
    {
        this->worldClock();
        this->mousePos();
        this->pollEvents();
        this->updatePlayer();

        if (changeInTime(this->m_time_of_day) && this->m_hunger_levels->getHungerLevels() < 10 && this->m_food_items.size()<10 )
        {
            //Adds more food to the world
            addToFoodList();
        }
        else if (this->m_hunger_levels->getHungerLevels() >= 10)
        {
            //end game
            this->m_gamestate = GameState_End;
        }
    }
}
void Game::updatePlayer()
{
    this->m_player->update();
}
void Game::render()
{
    //Clear background
    this->m_window->clear();

    //Put background image in
    this->m_background->render(*this->m_window);

    //Draw food images in
    for (auto &food : this->m_food_items)
    {
        food->render(*this->m_window);
    }

    //Draw the player, text, and GUI
    this->renderPlayer();
    this->m_gui->renderHungerBar(*this->m_window);
    this->renderText(*this->m_window);

    //Write pixals to screen
    this->m_window->display();
}
void Game::renderPlayer()
{
    this->m_player->render(*this->m_window);
}
void Game::mousePos()
{
    //Save the mouse position
    this->m_mouse_pos = sf::Mouse::getPosition(*this->m_window);
}
void Game::worldClock()
{
    //Updates the world clock
    daycycleTimer(this->m_time_of_day, this->m_clock);
}
void Game::pollEvents()
{
    //Checks for SFML events
    while (this->m_window->pollEvent(this->m_ev))
    {
        switch (this->m_ev.type)
        {
        case sf::Event::Closed:
            this->m_window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->m_ev.key.code == sf::Keyboard::Escape)
            {
                this->m_window->close();
            }
            if (this->m_ev.key.code == sf::Keyboard::E)
            {
                //Check if player is on top of a food item and clears the item after being consumed
                std::set<std::shared_ptr<Food>>::iterator item_to_erase = m_food_items.end();
                for (auto& food : this->m_food_items)
                {
                    if (food->isPlayerWithinArea(m_player->getPos()))
                    {
                        this->m_text.setString("NOM");
                        this->m_text.setPosition(food->getPos().x - 10.f, food->getPos().y - 10.f);
                        
                        if (food->getName() == "pumpkin")
                        {
                            //std::cout << "pumpkin" << std::endl;
                            item_to_erase = m_food_items.find(food);
                            m_hunger_levels->increaseHungerLevels(1);
                        }
                        else if (food->getName() == "tomato")
                        {
                            //std::cout << "tomato" << std::endl;
                            item_to_erase = m_food_items.find(food);
                            m_hunger_levels->increaseHungerLevels(1);
                        }
                        else if (food->getName() == "tomato2")
                        {
                            //std::cout << "tomato2" << std::endl;
                            item_to_erase = m_food_items.find(food);
                            m_hunger_levels->increaseHungerLevels(1);
                        }
                        else if (food->getName() == "pumpkin2")
                        {
                            //std::cout << "pumpkin2" << std::endl;
                            item_to_erase = m_food_items.find(food);
                            m_hunger_levels->increaseHungerLevels(1);
                        }
                        m_gui->updateHungerBar();
                    }
                }
                //Clears the item from the list of active food items
                if (item_to_erase != this->m_food_items.end())
                {
                    m_food_items.erase(item_to_erase);
                    item_to_erase = this->m_food_items.end();
                }
            }
            break;
        }
    }
}
const bool Game::getWindowIsOpen() const
{
	return this->m_window->isOpen();
}
void Game::addToFoodList()
{
    this->m_food_items.insert(std::make_shared<Food>((std::rand() % 700 + 50), (std::rand() % 500 + 50), 16, 16, "tomato", Daycycle_Night, "Texture/tomato.png"));

}
void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->m_text);
}
void Game::startMenu()
{
    this->m_text.setString("Collect ten pieces of food to satify your hunger\n WASD to Move\n E to Eat\n Press any key to continue");
    this->m_text.setPosition((this->m_background->size().x/2.f)*0.2f, (this->m_background->size().y/2.f)*0.8f);
    this->m_text.setFillColor(sf::Color::White);
    this->m_background->setTint(sf::Color(200, 200, 200, 255));
    
    if (this->m_window->pollEvent(this->m_ev))
    {
        switch (this->m_ev.type)
        {
        case sf::Event::KeyPressed:
            this->m_text.setString("");
            this->m_gamestate = GameState_Running;
            this->m_background->setTint(sf::Color(255, 255, 255, 255));
            this->m_text.setFillColor(sf::Color::Black);
            break;
        }
    }
}
void Game::endMenu()
{
    this->m_text.setString("Congrats the slime is now full\n Press ESC to exit game");
    this->m_text.setPosition((this->m_background->size().x / 2.f) * 0.5f, (this->m_background->size().y / 2.f) * 0.8f);

    if (this->m_window->pollEvent(this->m_ev))
    {
        switch (this->m_ev.type)
        {
        case sf::Event::KeyPressed:
            if (this->m_ev.key.code == sf::Keyboard::Escape)
            {
                this->m_window->close();
            }
            break;
        case sf::Event::Closed:

            this->m_window->close();
            break;
        }
    }
}