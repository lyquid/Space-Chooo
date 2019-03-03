#ifndef SPACE_CHOOO_CLASSES_UI_H_
#define SPACE_CHOOO_CLASSES_UI_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

class UI {
 public:
  UI() {
    show_pause_text_ = true;
  }
  ~UI() {}
  static void centerTextOrigin(sf::Text* text);
  void drawMenu(sf::RenderWindow* window);
  void drawPauseText(sf::RenderWindow* window);
  void init(sf::Font* font);
  static void initText(sf::Text* sf_text, sf::String text, sf::Font* font, int size);
  void restartPauseFlashClock();
  void setPauseText();
  bool showPauseText();

 private:
  sf::Text options_[1];
  sf::Text pause_text_;
  sf::Clock pause_flash_;
  bool show_pause_text_;
  sf::Text title_;
};

#endif  // SPACE_CHOOO_CLASSES_UI_H_