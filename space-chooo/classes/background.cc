#include "background.h"

sf::Color Background::calculateBrightness(StarBrightness brightness) {
  switch (brightness) {
    case Zero:
      return sf::Color(0, 0, 0);
      break;
    case Dim:
      return sf::Color(40, 40, 40);
      break;
    case Far:
      return sf::Color(80, 80, 80);
      break;
    case Bright:
      return sf::Color(170, 170, 170);
      break;
    case MorningStarB:
      return sf::Color(255, 255, 204);
      break;
    case Supernova:
    default:
      return sf::Color(255, 255, 255);
      break;
  }  
}

void Background::draw(sf::RenderWindow* window) {
  drawStars(window);
}

void Background::drawStars(sf::RenderWindow* window) {
  std::list <Star>::iterator star;
  sf::CircleShape circle;
  for (star = stars_.begin(); star != stars_.end(); ++star) {
    if (star->morning_star) {
      morning_star_.m_star_shape.setPosition(star->position.x, star->position.y);
      window->draw(morning_star_.m_star_shape);
    } else {
      circle.setRadius(star->radius);
      circle.setOrigin(star->radius, star->radius);
      circle.setPosition(star->position.x, star->position.y);
      circle.setFillColor(calculateBrightness(star->brightness));
      window->draw(circle);
    }
  }
} 

Star Background::generateStar(bool playing) {
  int brightness = rand() % 10 + 1; // rnd 1 to 10
  int morning_star_ch = rand() % 2000;
  float rand_x, rand_y;
  Star star;
  switch (brightness) {
    case 1:
    case 2:
    case 3:
      brightness = Dim;
      break;
    case 4:
    case 5:
    case 6:
      brightness = Far;
      break;
    case 7:
    case 8:
    case 9:
      brightness = Bright;
      break;
    case 10:
      brightness = Supernova;
      break;
  }
  star.brightness = StarBrightness(brightness);
  rand_x = (float) (rand() % kScreenWidth);
  (playing) ? rand_y = 0 : rand_y = (float) (rand() % kScreenHeight);
  star.position = sf::Vector2f(rand_x, rand_y);
  star.radius = 1.f;
  if (morning_star_ch == 0){
    star.morning_star = true;
    // star.brightness = Zero; // ¿¿¿¿!!
  } else {
    star.morning_star = false;
  }
  return star;
}

void Background::initMorningStar() {
  morning_star_.m_star_shape.setPointCount(8);
  // north
  morning_star_.m_star_shape.setPoint(0, sf::Vector2f(3.f, 0.f));
  morning_star_.m_star_shape.setPoint(1, sf::Vector2f(3.5f, 2.5f));
  // east
  morning_star_.m_star_shape.setPoint(2, sf::Vector2f(6.f, 3.f));
  morning_star_.m_star_shape.setPoint(3, sf::Vector2f(3.5f, 3.5f));
  // south
  morning_star_.m_star_shape.setPoint(4, sf::Vector2f(3.f, 6.f));
  morning_star_.m_star_shape.setPoint(5, sf::Vector2f(2.5f, 3.5f));
  // west
  morning_star_.m_star_shape.setPoint(6, sf::Vector2f(0.f, 3.f));
  morning_star_.m_star_shape.setPoint(7, sf::Vector2f(2.5f, 2.5f));
  
  morning_star_.size = 2.5f;
  morning_star_.m_star_shape.setScale(morning_star_.size, morning_star_.size);
  morning_star_.m_star_shape.setOrigin(morning_star_.size, morning_star_.size);
  morning_star_.m_star_shape.setFillColor(calculateBrightness(MorningStarB));
}

void Background::initStars() {
  int star_num = rand() % 180 + 100;
  stars_.clear();
  for (int i = 0; i < star_num; ++i) {
    stars_.push_front(generateStar(false));
  }
}

void Background::update(float delta_time) {
  if (!stars_.empty()) {
    int star_chance = rand() % 20;
    std::list <Star>::iterator star = stars_.begin();
    while (star != stars_.end()) {
      if (star->position.y - star->radius > kScreenHeight) {
        star = stars_.erase(star);
      } else {
        star->position.y += (speed_ * ((delta_time * (star->brightness + 1)))) / 30.f;
        ++star;
      }
    }
    if (star_chance == 0) {
      stars_.push_front(generateStar(true));
    }
  }
}