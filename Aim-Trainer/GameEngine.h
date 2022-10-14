#pragma once

#include "cScreen.hpp"

/*
    Class that acts as the game engine.
*/

class GameEngine : public cScreen {

private:
    Event event;

    Vector2i mousePosWindow;
    Vector2f mousePosView;

    Font font;
    Text uiText;

    SoundBuffer buffer;
    Sound sound;

    int width = VideoMode::getDesktopMode().width;
    int height = VideoMode::getDesktopMode().height;

    bool endGame = false;

    unsigned int speed = 100;
    unsigned int points = 0;
    unsigned int health = 10;

    float enemySpawnTimerMax = 20.f;
    float enemySpawnTimer = enemySpawnTimerMax;
    unsigned int maxEnemies = 10;

    bool mouseHeld = false;

    Vector2f position;

    vector<RectangleShape> enemies;
    RectangleShape enemy;

    const bool isRunning(sf::RenderWindow& App) const;
    const bool getEndGame() const;

    void spawnEnemy(sf::RenderWindow& App);

    void initVariables();
    void initFonts();
    void initText();
    void initEnemies();

    void updateMousePos(sf::RenderWindow& App);
    void updateText(RenderWindow& App);
    void updateEnemies(sf::RenderWindow& App);
    void update(sf::RenderWindow& App);

    void renderText(RenderTarget& target);
    void renderEnemies(RenderTarget& target);
public:
    virtual int Run(sf::RenderWindow& App);

};
