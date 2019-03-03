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
  void drawPauseText(sf::RenderWindow* window);
  void init(sf::Font* font);
  static void initText(sf::Text* sf_text, sf::String text, sf::Font* font, int size);

 private:
  sf::Text options_[1];
  sf::Text paused_text_;
  sf::Text title_;
};

#endif  // SPACE_CHOOO_CLASSES_MENU_H_