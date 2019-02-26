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
          switch (event_.key.code) {
            case sf::Keyboard::Escape:
              in_menu_ = true;
              break;
            case sf::Keyboard::P:
            case sf::Keyboard::F1:
              paused_ = !paused_;
              break;
          }
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
  // font for texts
  if (!font_.loadFromFile("assets/computer_pixel-7.ttf")) {
    exit(EXIT_FAILURE);
  } else {
    main_menu_.init(&font_);
  }
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
    main_menu_.draw(&window_);
  } else {
    // window_.draw();
    if (paused_) {
      
    }
  }
  window_.display();
}

void Game::update() {
  float delta_time = main_clock_.restart().asSeconds();
}
