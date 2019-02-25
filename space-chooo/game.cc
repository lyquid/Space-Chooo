#include "game.h"

void Game::clean() {
  window_.close();
}

void Game::handleEvents() {
  while (window_.pollEvent(event_)) {
    switch (event_.type) {
      case sf::Event::Closed:
        quit_ = true;
        break;
      case sf::Event::KeyPressed:
        if (in_menu_) {
          switch (event_.key.code) {
            case sf::Keyboard::Num1:
              in_menu_ = false;
              break;
            case sf::Keyboard::Escape:
              quit_ = true;
              break;
          }
        } else { // not in menu

        }
    }
  }
}

void Game::init() {
  // aplication window
  window_.create(
    sf::VideoMode(kScreenWidth, kScreenHeight, 32), 
    title_, 
    sf::Style::Titlebar | sf::Style::Close
  );
  window_.setVerticalSyncEnabled(true);
}

bool Game::isPaused() {
  return paused_;
}

bool Game::quit() {
  return quit_;
}

void Game::render() {
  window_.clear();
  if (in_menu_) {
    // menu
  } else {
    // window_.draw();
  }
  window_.display();
}

void Game::update() {
  float delta_time = main_clock_.restart().asSeconds();
}
