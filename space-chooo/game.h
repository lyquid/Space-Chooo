#ifndef SPACE_CHOOO_GAME_H_
#define SPACE_CHOOO_GAME_H_

#include <SFML/Graphics.hpp>

#include "config.h"
#include "classes/menu.h"
#include "classes/player.h"
#include "classes/ship.h"

class Game {
 public:
  Game() {
    in_menu_ = true;
    paused_ = false;
    quit_ = false;
    title_ = kAppName + " - v" + kAppVersion;
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
  sf::Clock main_clock_;
  sf::Event event_;
  sf::Font font_;
  bool in_menu_;
  Menu main_menu_;
  bool paused_;
  Player player_;
  bool quit_;
  Ship ship_;
  sf::String title_;
  sf::RenderWindow window_;
};

#endif  // SPACE_CHOOO_GAME_H_