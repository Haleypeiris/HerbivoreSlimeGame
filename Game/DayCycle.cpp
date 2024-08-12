#pragma once

#include "DayCycle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <thread>

#include "Common.h"

static Daycycle last_stored_time = Daycycle_Unknown;

void daycycleTimer(Daycycle &daycycle, sf::Clock &clock)
{

    using namespace std::literals::chrono_literals;
    int clock_timer = clock.getElapsedTime().asMilliseconds();
    //std::cout << clock_timer << std::endl;
    if (clock_timer >= 0 && clock_timer < 4000)
    {
        daycycle = Daycycle_Morning;
        //std::cout << "morning" << std::endl;
    }
    else if (clock_timer >= 4000 && clock_timer < 6000)
    {
        daycycle = Daycycle_Afternoon;
        //std::cout << "afternoon" << std::endl;
    }
    else if (clock_timer >= 6000 && clock_timer < 10000)
    {
        daycycle = Daycycle_Night;
        //std::cout << "night" << std::endl;
    }
    else if (clock.getElapsedTime().asMilliseconds() >= 10000)
    {
        sf::Time elapsed = clock.restart();
    }
    else
    {
        daycycle = Daycycle_Unknown;
    }

}

bool changeInTime(Daycycle& daycycle)
{
    if (daycycle != last_stored_time)
    {
        last_stored_time = daycycle;
        return true;
    }
    else
    {
        return false;
    }
}