#ifndef SPACE_CHOOO_GAME_H_
#define SPACE_CHOOO_GAME_H_

#include <SFML/Graphics.hpp>

#include "config.h"
#include "classes/background.h"
#include "classes/player.h"
#include "classes/ship.h"
#include "classes/ui.h"

class Game {
 public:
  Game() {
    in_menu_ = true;
    paused_ = true;
    quit_ = false;
    title_ = kAppName + " - v" + kAppVersion;
    settings_.antialiasingLevel = 8;
  }
  ~Game() {}
  void clean();
  void handleEvents();
  void init();
  bool isPaused();
  bool quit();
  void render();
  void update();

 private:
  Background background_;
  sf::Event event_;
  sf::Font font_;
  sf::Clock main_clock_;
  bool in_menu_;
  UI ui_;
  bool paused_;
  Player player_;
  bool quit_;
  sf::ContextSettings settings_;
  Ship ship_;
  sf::Clock shoot_clock_;
  sf::String title_;
  sf::RenderWindow window_;
};

#endif  // SPACE_CHOOO_GAME_H_