#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"

int main(int argc, char** argv)
{
	vector<cScreen*> Screens;
	int screen = 0;
	int width = VideoMode::getDesktopMode().width;
	int height = VideoMode::getDesktopMode().height;

	RenderWindow App(sf::VideoMode(width, height), "Aim-Trainer", Style::Fullscreen);

	MainMenu mainMenu;
	Screens.push_back(&mainMenu);

	GameEngine gameEngine;
	Screens.push_back(&gameEngine);

	GameRestart pauseGame;
	Screens.push_back(&pauseGame);

	while (screen >= 0) {
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}