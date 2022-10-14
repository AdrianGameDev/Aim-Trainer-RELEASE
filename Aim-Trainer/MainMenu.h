#pragma once

#include "cScreen.hpp"

class MainMenu : public cScreen
{
private:
	Event event;

	Font font;
	Text Play;
	Text Options;
	Text Exit;

	bool mouseHeld = false;
public:
	virtual int Run(sf::RenderWindow& App);
};

