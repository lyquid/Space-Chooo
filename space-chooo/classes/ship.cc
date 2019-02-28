#include "ship.h"

void Ship::draw(sf::RenderWindow* window) {
  window->draw(shape_);
}

void Ship::moveDown(float delta_time) {
  shape_.move(0, speed_ * delta_time);
}

void Ship::moveLeft(float delta_time) {
  shape_.move(-speed_ * delta_time, 0);
}

void Ship::moveRight(float delta_time) {
  shape_.move(speed_ * delta_time, 0);
}

void Ship::moveUp(float delta_time) {
  shape_.move(0, -speed_ * delta_time);
}

 bool Ship::touchDown(){
   return (shape_.getPosition().y + shape_.getRadius() >= kScreenHeight) ? true : false;
 }

bool Ship::touchLeft() {
  return (shape_.getPosition().x - shape_.getRadius() <= 0) ? true : false;
}

bool Ship::touchRight() {
  return (shape_.getPosition().x + shape_.getRadius() >= kScreenWidth) ? true : false;
}

bool Ship::touchUp() {
  return (shape_.getPosition().y - shape_.getRadius() <= 0) ? true : false;
}