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
  window->draw(paused_text_);
}

void UI::init(sf::Font* font) {
  // title
  initText(&title_, kAppName, font, kTitleFontSize);
  centerTextOrigin(&title_);
  title_.setPosition(kScreenWidth / 2, kScreenHeight / 4);
  // options
  initText(&options_[0], "Press 1 to start", font, kOptionFontSize);
  centerTextOrigin(&options_[0]);
  options_[0].setPosition(kScreenWidth / 2, kScreenHeight / 2);
  // pause
  initText(&paused_text_, kDefaultPauseMessage, font, kOptionFontSize);
  centerTextOrigin(&paused_text_);
  paused_text_.setPosition(kScreenWidth / 2, kScreenHeight / 2);
}

void UI::initText(sf::Text* sf_text, sf::String text, sf::Font* font, int size) {
  sf_text->setFont(*font);
  sf_text->setCharacterSize(size);
  sf_text->setString(text);
}