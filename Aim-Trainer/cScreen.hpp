#pragma once

#include <iostream>
#include <fstream> 
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class cScreen
{
public:
    virtual int Run(sf::RenderWindow& App) = 0;
};