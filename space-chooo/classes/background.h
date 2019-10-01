#ifndef SPACE_CHOOO_CLASSES_BACKGROUND_H_
#define SPACE_CHOOO_CLASSES_BACKGROUND_H_

#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "../config.h"

enum StarIntensities {Zero, Dim, Far, Bright, Supernova};

struct Star {
  sf::Vector2f position;
  StarIntensities intensity;
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
  sf::Color calculateIntenistyColor(StarIntensities intensity);
  
  MorningStar morning_star_;
  float speed_;
  std::list <Star> stars_;
};

#endif  // SPACE_CHOOO_CLASSES_BACKGROUND_H_