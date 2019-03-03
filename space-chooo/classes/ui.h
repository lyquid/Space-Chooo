#ifndef SPACE_CHOOO_CLASSES_UI_H_
#define SPACE_CHOOO_CLASSES_UI_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

class UI {
 public:
  UI() {
    show_flashing_text_ = true;
  }
  ~UI() {}
  static void centerTextOrigin(sf::Text* text);
  void drawMenu(sf::RenderWindow* window);
  void drawPauseText(sf::RenderWindow* window);
  void init(sf::Font* font);
  static void initText(sf::Text* sf_text, sf::String text, sf::Font* font, int size);
  void restartFlashClock();
  bool showFlashingText(int interval);

 private:
  sf::Text options_[1];
  sf::Text pause_text_;
  sf::Clock flash_clock_;
  bool show_flashing_text_;
  sf::Text title_;
};

#endif  // SPACE_CHOOO_CLASSES_UI_H_