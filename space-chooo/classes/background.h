#ifndef SPACE_CHOOO_CLASSES_BACKGROUND_H_
#define SPACE_CHOOO_CLASSES_BACKGROUND_H_

#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "../config.h"

enum StarBrightness {Zero, Dim, Far, Bright, Supernova};

struct Star {
  sf::Vector2f position;
  StarBrightness brightness;
  bool morning_star;
  float radius;
};

struct MorningStar {
  sf::ConvexShape m_star_shape;
  StarBrightness brightness;
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
  sf::Color calculateBrightness(StarBrightness brightness);
  
  MorningStar morning_star_;
  float speed_;
  std::list <Star> stars_;
};

#endif  // SPACE_CHOOO_CLASSES_BACKGROUND_H_