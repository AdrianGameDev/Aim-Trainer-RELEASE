#pragma once

#include "cScreen.hpp"

class GameRestart : public cScreen
{
private:
	Event event;

	Font font;
	Text Score;
	Text Retry;
	Text ReturnToMenu;
	Text Exit;
	string score;
	string textScore;

	bool mouseHeld;
public:
	virtual int Run(sf::RenderWindow& App);
};
