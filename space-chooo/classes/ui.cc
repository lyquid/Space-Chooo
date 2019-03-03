#include "ui.h"

void UI::centerTextOrigin(sf::Text* text) {
  text->setOrigin(
    (text->getLocalBounds().left + text->getLocalBounds().width) / 2.f,
    (text->getLocalBounds().top + text->getLocalBounds().height) / 2.f
  );
}

void UI::drawMenu(sf::RenderWindow* window) {
  window->draw(title_);
  window->draw(options_[0]);
}

void UI::drawPauseText(sf::RenderWindow* window) {
  window->draw(pause_text_);
}

void UI::init(sf::Font* font) {
  // title
  initText(&title_, kAppName, font, kTitleFontSize);
  title_.setPosition(kScreenWidth / 2, kScreenHeight / 4);
  // options
  initText(&options_[0], "Press 1 to start", font, kOptionFontSize);
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

void UI::restartPauseFlashClock() {
  show_pause_text_ = true;
  pause_flash_.restart();
}

bool UI::showPauseText() {
  if (pause_flash_.getElapsedTime().asMilliseconds() > 500) {
    pause_flash_.restart();
    show_pause_text_ = !show_pause_text_;
  }
  return show_pause_text_;
}