#ifndef SPACE_CHOOO_CLASSES_SHIP_H_
#define SPACE_CHOOO_CLASSES_SHIP_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

class Ship {
 public:
  Ship() {
    shape_.setRadius(kShipSize);
    shape_.setPointCount(3);
    shape_.setFillColor(sf::Color::White);
    shape_.setOrigin(shape_.getRadius(), shape_.getRadius());
    shape_.setPosition(kScreenWidth / 2, kScreenHeight - (kScreenHeight * 0.1f));
  }
  ~Ship() {}
  sf::CircleShape shape();

 private:
  sf::CircleShape shape_;
};

#endif  // SPACE_CHOOO_CLASSES_SHIP_H_