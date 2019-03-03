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
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
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
    ui_.init(&font_);
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
    ui_.drawMenu(&window_);
  } else {
    ship_.draw(&window_);
    ship_.drawProjectiles(&window_);
    if (paused_) {
      ui_.drawPauseText(&window_);
    }
  }
  window_.display();
}

void Game::update() {
  float delta_time = main_clock_.restart().asSeconds();
  if (paused_) {
    // show pause menu or something
  } else {
    // player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !ship_.touchUp()) {
      ship_.moveUp(delta_time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !ship_.touchDown()) {
      ship_.moveDown(delta_time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !ship_.touchLeft()) {
      ship_.moveLeft(delta_time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !ship_.touchRight()) {
      ship_.moveRight(delta_time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shoot_clock_.getElapsedTime().asMilliseconds() >= 100) {
      shoot_clock_.restart();
      ship_.shoot();
    }
    ship_.updateProjectiles(delta_time);
  }
}
