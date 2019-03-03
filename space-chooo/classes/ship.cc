#include "ship.h"

void Ship::draw(sf::RenderWindow* window) {
  window->draw(shape_);
}

void Ship::drawProjectiles(sf::RenderWindow* window) {
  std::list <sf::Vector2f>::iterator it;
  for (it = projectiles_.begin(); it != projectiles_.end(); ++it) {
    sf::Vertex line[] = {
      sf::Vertex(sf::Vector2f(it->x, it->y)),
      sf::Vertex(sf::Vector2f(it->x, it->y + 10.f))
    };
    window->draw(line, 2, sf::Lines);
  }
}

void Ship::moveDown(float delta_time) {
  shape_.move(0.f, speed_ * delta_time);
}

void Ship::moveLeft(float delta_time) {
  shape_.move(-speed_ * delta_time, 0.f);
}

void Ship::moveRight(float delta_time) {
  shape_.move(speed_ * delta_time, 0.f);
}

void Ship::moveUp(float delta_time) {
  shape_.move(0.f, -speed_ * delta_time);
}

void Ship::setInitialPosition() {
  shape_.setPosition(kScreenWidth / 2, kScreenHeight - (kScreenHeight * 0.1f));
}

void Ship::shoot() {
  projectiles_.push_front(sf::Vector2f(shape_.getPosition().x, shape_.getPosition().y - kShipSize));
}

bool Ship::touchDown(){
  return (shape_.getPosition().y + shape_.getRadius() >= kScreenHeight) ? true : false;
}

bool Ship::touchLeft() {
  return (shape_.getPosition().x - shape_.getRadius() <= 0.f) ? true : false;
}

bool Ship::touchRight() {
  return (shape_.getPosition().x + shape_.getRadius() >= kScreenWidth) ? true : false;
}

bool Ship::touchUp() {
  return (shape_.getPosition().y - shape_.getRadius() <= 0.f) ? true : false;
}

void Ship::updateProjectiles(float delta_time) {
  if (!projectiles_.empty()) {
    std::list <sf::Vector2f>::iterator it = projectiles_.begin();
    while (it != projectiles_.end()) {
      if (it->y < 0.f) {
        // destroy projectile
        it = projectiles_.erase(it);
      } else {
        it->y -= speed_ * (delta_time * 2.f);
        // todo: check collisions
        ++it;
      }
    }
  }
}