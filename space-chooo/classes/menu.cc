#include "menu.h"

void Menu::centerTextOrigin(sf::Text* text) {
  text->setOrigin(
    (text->getLocalBounds().left + text->getLocalBounds().width) / 2.f,
    (text->getLocalBounds().top + text->getLocalBounds().height) / 2.f
  );
}

void Menu::draw(sf::RenderWindow* window) {
  window->draw(title_);
  window->draw(options_[0]);
}

void Menu::init(sf::Font* font) {
  title_.setFont(*font);
  title_.setCharacterSize(kTitleFontSize);
  title_.setString(kAppName);
  centerTextOrigin(&title_);
  title_.setPosition(kScreenWidth / 2, kScreenHeight / 4);
  // options
  options_[0].setFont(*font);
  options_[0].setCharacterSize(kOptionFontSize);
  options_[0].setString("Press 1 to start");
  centerTextOrigin(&options_[0]);
  options_[0].setPosition(kScreenWidth / 2, kScreenHeight / 2);
}