#ifndef SPACE_CHOOO_CLASSES_SHIP_H_
#define SPACE_CHOOO_CLASSES_SHIP_H_

#include <list>
#include <iterator>
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
  void draw(sf::RenderWindow* window);
  void drawProjectiles(sf::RenderWindow* window);
  void moveDown(float delta_time);
  void moveLeft(float delta_time);
  void moveRight(float delta_time);
  void moveUp(float delta_time);
  void shoot();
  bool touchDown();
  bool touchLeft();
  bool touchRight();
  bool touchUp();
  void updateProjectiles(float delta_time);

 private:
  std::list <sf::Vector2f> projectiles_;
  sf::CircleShape shape_;
  float speed_ = 400.f;
};

#endif  // SPACE_CHOOO_CLASSES_SHIP_H_