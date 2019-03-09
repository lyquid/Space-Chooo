#ifndef SPACE_CHOOO_CONFIG_H_
#define SPACE_CHOOO_CONFIG_H_

#include <SFML/Graphics.hpp>

// app default strings
const sf::String kAppName = "Space Chooo";
const sf::String kAppVersion = "0.0"; 
const sf::String kDefaultPauseMessage = "Paused. Press P or Start to resume.";

// app default settings
const int kScreenHeight = 1024;
const int kScreenWidth = 768;

// menu default settings
const int kOptionFontSize = 40;
const int kTitleFontSize = 120;

// ship default settings
const int kShipDefaultSize = 20;
const float kShipDefaultSpeed = 400.f;

// background default settings
const float kBackgroundDefaultSpeed = 100.f;

#endif  // SPACE_CHOOO_CONFIG_H_