#pragma once

#include "cScreen.hpp"

class GameRestart : public cScreen
{
private:
	Event event;

	Font font;
	Text Retry;
	Text ReturnToMenu;
	Text Exit;

	bool mouseHeld;
public:
	virtual int Run(sf::RenderWindow& App);
};
