#include "ui.h"

void UI::centerTextOrigin(sf::Text* text) {
  text->setOrigin(
    (text->getLocalBounds().left + text->getLocalBounds().width) / 2.f,
    (text->getLocalBounds().top + text->getLocalBounds().height) / 2.f
  );
}

void UI::drawMenu(sf::RenderWindow* window) {
  window->draw(title_);
  if (showFlashingText(1000)) {
    window->draw(options_[0]);
  }
}

void UI::drawPauseText(sf::RenderWindow* window) {
  if (showFlashingText(500)) { 
    window->draw(pause_text_);
  }
}

void UI::init(sf::Font* font) {
  // title
  initText(&title_, kAppName, font, kTitleFontSize);
  title_.setPosition(kScreenWidth / 2, kScreenHeight / 4);
  // options
  initText(&options_[0], "Press 1 or Start", font, kOptionFontSize);
  options_[0].setPosition(kScreenWidth / 2, kScreenHeight / 2);
  // pause
  initText(&pause_text_, kDefaultPauseMessage, font, kOptionFontSize);
  pause_text_.setPosition(kScreenWidth / 2, kScreenHeight / 2);
}

void UI::initText(sf::Text* sf_text, sf::String text, sf::Font* font, int size) {
  sf_text->setFont(*font);
  sf_text->setCharacterSize(size);
  sf_text->setOutlineThickness(0.8f);
  sf_text->setString(text);
  centerTextOrigin(sf_text);
}

void UI::restartFlashClock() {
  show_flashing_text_ = true;
  flash_clock_.restart();
}

bool UI::showFlashingText(int interval) {
  if (flash_clock_.getElapsedTime().asMilliseconds() > interval) {
    flash_clock_.restart();
    show_flashing_text_ = !show_flashing_text_;
  }
  return show_flashing_text_;
}