#ifndef SPACE_CHOOO_CLASSES_MENU_H_
#define SPACE_CHOOO_CLASSES_MENU_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

class Menu {
 public:
  Menu() {}
  ~Menu() {}
  static void centerTextOrigin(sf::Text* text);
  void draw(sf::RenderWindow* window);
  void init(sf::Font* font);

 private:
  sf::Text title_;
  sf::Text options_[1];
};

#endif  // SPACE_CHOOO_CLASSES_MENU_H_