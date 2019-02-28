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