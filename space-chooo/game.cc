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
              paused_ = false;
              break;
            case sf::Keyboard::Escape:
              quit_ = true;
              break;
          }
        } else { // not in menu
          switch (event_.key.code) {
            case sf::Keyboard::Escape:
              in_menu_ = true;
              paused_ = true;
              background_.initStars();
              ship_.setInitialPosition();
              ship_.clearProjectiles();
              break;
            case sf::Keyboard::P:
            case sf::Keyboard::F1:
              paused_ = !paused_;
              ui_.restartFlashClock();
              break;
          }
        }
        break;
      case sf::Event::JoystickButtonPressed:
        if (in_menu_) {
          switch (event_.joystickButton.button) {
            case 6: // menu button
              quit_ = true;
              break;
            case 7: // start button
              in_menu_ = false;
              paused_ = false;
              break;
          }
        } else {
          switch (event_.joystickButton.button) {
            case 6: // menu button
              in_menu_ = true;
              paused_ = true;
              background_.initStars();
              ship_.setInitialPosition();
              ship_.clearProjectiles();
              break;
            case 7: // start button
              paused_ = !paused_;
              ui_.restartFlashClock();
              break;
          }
        }
        break;
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
  background_.draw(&window_);
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
    // do something
  } else {
    // player movement
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) 
      || (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 1)) 
      && !ship_.touchUp()) {
        ship_.moveUp(delta_time);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) 
      || (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -1)) 
      && !ship_.touchDown()) {
        ship_.moveDown(delta_time);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) 
      || (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -1))
      && !ship_.touchLeft()) {
        ship_.moveLeft(delta_time);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) 
      || (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 1)) 
      && !ship_.touchRight()) {
        ship_.moveRight(delta_time);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) 
      || sf::Joystick::isButtonPressed(0, 0)) // A button
      && shoot_clock_.getElapsedTime().asMilliseconds() >= 100) {
        shoot_clock_.restart();
        ship_.shoot();
    }
    ship_.updateProjectiles(delta_time);
    background_.update(delta_time);
  }
}
