#ifndef SPACE_CHOOO_CLASSES_BACKGROUND_H_
#define SPACE_CHOOO_CLASSES_BACKGROUND_H_

#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "../config.h"

struct Star {
  sf::Vector2f position;
  int intensity;
  bool morning_star;
  float radius;
};

struct MorningStar {
  sf::ConvexShape m_star_shape;
  int intensity;
  float size;
}; 

class Background {
 public:
  Background() {
    speed_ = kBackgroundDefaultSpeed;
    initStars();
    initMorningStar();
  }
  ~Background() {}
  void draw(sf::RenderWindow* window);
  void drawStars(sf::RenderWindow* window);
  Star generateStar(bool playing);
  void initStars();
  void update(float delta_time);

 private:
  void initMorningStar();
  sf::Color calculateIntenistyColor(int intensity);
  
  MorningStar morning_star_;
  float speed_;
  std::list <Star> stars_;
};

#endif  // SPACE_CHOOO_CLASSES_BACKGROUND_H_