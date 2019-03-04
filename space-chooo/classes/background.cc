#include "background.h"

void Background::draw(sf::RenderWindow* window) {
  drawStars(window);
}

void Background::drawStars(sf::RenderWindow* window) {
  std::list <Star>::iterator star;
  sf::CircleShape circle;
  for (star = stars_.begin(); star != stars_.end(); ++star) {
    circle.setRadius(1);
    circle.setOrigin(1, 1);
    circle.setPosition(star->position.x, star->position.y);
    circle.setFillColor(sf::Color::White);
    switch (star->intensity) {
      case 0:
        circle.setFillColor(sf::Color(40, 40, 40));
        break;
      case 1:
        circle.setFillColor(sf::Color(80, 80, 80));
        break;
      case 2:
        circle.setFillColor(sf::Color(170, 170, 170));
        break;
      case 3:
        circle.setFillColor(sf::Color(255, 255, 255));
        break;
    } 
    window->draw(circle);
  }
} 

void Background::initStars() {
  int intensity = 0;
  int star_num = rand() % 250 + 150;
  float rand_x, rand_y;
  stars_.clear();
  for (int i = 0; i < star_num; ++i) {
    Star star;
    intensity = rand() % 10 + 1;
    switch (intensity) {
      case 1:
      case 2:
      case 3:
        intensity = 0;
        break;
      case 4:
      case 5:
      case 6:
        intensity = 1;
        break;
      case 7:
      case 8:
      case 9:
        intensity = 2;
        break;
      case 10:
        intensity = 3;
        break;
    }
    star.intensity = intensity;
    rand_x = (float) (rand() % kScreenWidth);
    rand_y = (float) (rand() % kScreenHeight);
    star.position = sf::Vector2f(rand_x, rand_y);
    stars_.push_front(star);
  }
}