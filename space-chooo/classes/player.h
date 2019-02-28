#ifndef SPACE_CHOOO_CLASSES_PLAYER_H_
#define SPACE_CHOOO_CLASSES_PLAYER_H_

#include <SFML/Graphics.hpp>

#include "../config.h"
#include "ship.h"

class Player {
 public:
  Player() {}
  ~Player() {}
  sf::CircleShape drawShip();

 private:
  Ship ship_;
};

#endif  // SPACE_CHOOO_CLASSES_PLAYER_H_