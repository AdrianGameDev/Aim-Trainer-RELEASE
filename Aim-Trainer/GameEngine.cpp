#include "GameEngine.h"

void GameEngine::initVariables() {

    speed = 100;
    endGame = false;
    points = 0;
    health = 20;
    enemySpawnTimerMax = 20.f;
    enemySpawnTimer = enemySpawnTimerMax;
    maxEnemies = 10;
    mouseHeld = false;
}

void GameEngine::initFonts() {

    if (!font.loadFromFile("Resources/Fonts/Dosis-Light.ttf")) {

        cout << "ERROR::GameEngine::initFonts::Resources/Fonts/Dosis-Light.ttf!";
    }
}

void GameEngine::initText() {

    uiText.setFont(font);
    uiText.setCharacterSize(50);
    uiText.setFillColor(Color::White);
    uiText.setString("NONE");
}

void GameEngine::initEnemies() {

    enemy.setPosition(10.f, 10.f);
    position = enemy.getPosition();
    enemy.setSize(Vector2f(100.f, 100.f));
    enemy.setFillColor(Color::Cyan);
    enemy.setOutlineColor(Color::White);
    enemy.setOutlineThickness(2.f);
}

const bool GameEngine::isRunning(RenderWindow& App) const {

    return App.isOpen();
}

const bool GameEngine::getEndGame() const {

    return endGame;
}

void GameEngine::spawnEnemy(RenderWindow& App) {

    enemy.setPosition(
        static_cast<float>(rand() % static_cast<int> (App.getSize().x - enemy.getSize().x)),
        0.f
    );

    while (enemy.getPosition() == position) {

        enemy.setPosition(
            static_cast<float>(rand() % static_cast<int> (App.getSize().x - enemy.getSize().x)),
            0.f
        );
    }

    unsigned int type = rand() % 6;

    switch (type) {

    case 0:

        enemy.setSize(Vector2f(90.f, 90.f));
        enemy.setFillColor(Color::White);
        break;

    case 1:

        enemy.setSize(Vector2f(95.f, 95.f));
        enemy.setFillColor(Color::Magenta);
        break;

    case 2:

        enemy.setSize(Vector2f(100.5f, 100.5f));
        enemy.setFillColor(Color::Green);
        break;

    case 3:

        enemy.setSize(Vector2f(110.f, 110.f));
        enemy.setFillColor(Color::Blue);
        break;

    case 4:

        enemy.setSize(Vector2f(120.f, 120.f));
        enemy.setFillColor(Color::Cyan);
        break;

    case 5:

        enemy.setSize(Vector2f(130.f, 130.f));
        enemy.setFillColor(Color::Yellow);
        break;
    }

    enemies.push_back(enemy);
}

void GameEngine::updateMousePos(RenderWindow& App) {

    mousePosWindow = Mouse::getPosition(App);
    mousePosView = App.mapPixelToCoords(mousePosWindow);
}

void GameEngine::updateText(RenderWindow& App) {

    stringstream ss;

    ss << "Points: " << points << '\n'
       << "Health: " << health;

    uiText.setString(ss.str());
}

void GameEngine::updateEnemies(RenderWindow& App) {

    if (enemies.size() < maxEnemies) {

        if (enemySpawnTimer >= enemySpawnTimerMax) {

            spawnEnemy(App);
            enemySpawnTimer = 0.f;
            speed += 1;
        }
        else
            enemySpawnTimer += 1.f;
    }

    for (int i = 0; i < enemies.size(); ++i) {

        bool deleted = false;

        enemies[i].move(0.f, 1.5f);

        if (enemies[i].getPosition().y > App.getSize().y) {

            enemies.erase(enemies.begin() + i);
            health -= 1;
        }
    }

    if (Mouse::isButtonPressed(Mouse::Left)) {

        if (mouseHeld == false) {

            mouseHeld = true;
            bool deleted = false;

            for (size_t i = 0; i < enemies.size() && deleted == false; i++) {

                if (enemies[i].getGlobalBounds().contains(mousePosView)) {

                    sound.play();

                    if (enemies[i].getFillColor() == Color::White) {

                        points += 10;
                    }

                    else if (enemies[i].getFillColor() == Color::Magenta) {

                        points += 8;
                    }

                    else if (enemies[i].getFillColor() == Color::Green) {

                        points += 8;
                    }

                    else if (enemies[i].getFillColor() == Color::Blue) {

                        points += 8;
                    }

                    else if (enemies[i].getFillColor() == Color::Cyan) {

                        points += 8;
                    }

                    else if (enemies[i].getFillColor() == Color::Yellow) {

                        points += 8;
                    }

                    deleted = true;
                    enemies.erase(enemies.begin() + i);

                }
            }
        }
    }
    else {

        mouseHeld = false;
    }
}


void GameEngine::update(RenderWindow& App) {

    if (!endGame) {

        updateMousePos(App);

        updateText(App);

        updateEnemies(App);
        if (speed <= 260)
            App.setFramerateLimit(speed);
    }

    if (health == 0) {

        endGame = true;
    }
}

void GameEngine::renderText(RenderTarget& target) {

    target.draw(uiText);
}

void GameEngine::renderEnemies(RenderTarget& target) {

    for (auto& e : enemies) {

        target.draw(e);
    }
}

int GameEngine::Run(RenderWindow& App)
{

    initVariables();
    initEnemies();
    initFonts();
    initFonts();
    initText();

    if (!buffer.loadFromFile("Resources/Audio/laser.ogg")) {

        cout << "ERROR::GameEngine::Run::Resources/Audio/laser.ogg!";
    }

    sound.setBuffer(buffer);
    sound.setVolume(10);

    bool Running = true;

    while (Running) {

        while (App.pollEvent(event)) {

            switch (event.type) {

            case Event::Closed:
                Running = false;
                break;

            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {

                    return(2);
                }
                break;

            }
        }

        if (endGame == true) {

            return (2);
        }

        App.clear(sf::Color(0, 0, 0, 0));

        update(App);
        renderEnemies(App);
        renderText(App);

        App.display();
    }

    return -1;
}