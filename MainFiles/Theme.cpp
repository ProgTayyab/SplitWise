#include "Theme.h"
#include <iostream>

// Initialize static members
Theme::Mode Theme::currentMode = Theme::LIGHT;
const std::string Theme::CONFIG_FILE = "theme_config.txt";

// Light mode colors
const std::string Theme::LIGHT_RESET = "\033[0m";
const std::string Theme::LIGHT_HEADER = "\033[1;34m";      // Bold Blue
const std::string Theme::LIGHT_MENU = "\033[0;32m";        // Green
const std::string Theme::LIGHT_INPUT = "\033[0;36m";       // Cyan
const std::string Theme::LIGHT_SUCCESS = "\033[1;32m";     // Bold Green
const std::string Theme::LIGHT_ERROR = "\033[1;31m";       // Bold Red
const std::string Theme::LIGHT_SEPARATOR = "\033[0;33m";   // Yellow

// Dark mode colors
const std::string Theme::DARK_RESET = "\033[0m";
const std::string Theme::DARK_HEADER = "\033[1;95m";       // Bold Bright Magenta
const std::string Theme::DARK_MENU = "\033[0;96m";         // Bright Cyan
const std::string Theme::DARK_INPUT = "\033[0;93m";        // Bright Yellow
const std::string Theme::DARK_SUCCESS = "\033[1;92m";      // Bold Bright Green
const std::string Theme::DARK_ERROR = "\033[1;91m";        // Bold Bright Red
const std::string Theme::DARK_SEPARATOR = "\033[0;94m";    // Bright Blue

void Theme::loadTheme() {
    std::ifstream file(CONFIG_FILE);
    if (file.is_open()) {
        int mode;
        file >> mode;
        currentMode = (mode == 1) ? DARK : LIGHT;
        file.close();
    }
    
    // Set background color based on mode
    if (currentMode == DARK) {
        std::cout << "\033[48;5;235m"; // Dark background
    } else {
        std::cout << "\033[48;5;255m"; // Light background
    }
    clearScreen();
}

void Theme::saveTheme() {
    std::ofstream file(CONFIG_FILE);
    if (file.is_open()) {
        file << (currentMode == DARK ? 1 : 0);
        file.close();
    }
}

void Theme::toggleMode() {
    currentMode = (currentMode == LIGHT) ? DARK : LIGHT;
    saveTheme();
    
    // Set background color based on new mode
    if (currentMode == DARK) {
        std::cout << "\033[48;5;235m"; // Dark background
    } else {
        std::cout << "\033[48;5;255m"; // Light background
    }
    clearScreen();
}

Theme::Mode Theme::getCurrentMode() {
    return currentMode;
}

void Theme::setMode(Mode mode) {
    currentMode = mode;
    saveTheme();
}

std::string Theme::getResetColor() {
    return (currentMode == DARK) ? DARK_RESET : LIGHT_RESET;
}

std::string Theme::getHeaderColor() {
    return (currentMode == DARK) ? DARK_HEADER : LIGHT_HEADER;
}

std::string Theme::getMenuColor() {
    return (currentMode == DARK) ? DARK_MENU : LIGHT_MENU;
}

std::string Theme::getInputColor() {
    return (currentMode == DARK) ? DARK_INPUT : LIGHT_INPUT;
}

std::string Theme::getSuccessColor() {
    return (currentMode == DARK) ? DARK_SUCCESS : LIGHT_SUCCESS;
}

std::string Theme::getErrorColor() {
    return (currentMode == DARK) ? DARK_ERROR : LIGHT_ERROR;
}

std::string Theme::getSeparatorColor() {
    return (currentMode == DARK) ? DARK_SEPARATOR : LIGHT_SEPARATOR;
}

void Theme::clearScreen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top
}

void Theme::printHeader(const std::string& text) {
    std::cout << getHeaderColor() << text << getResetColor() << std::endl;
}

void Theme::printMenu(const std::string& text) {
    std::cout << getMenuColor() << text << getResetColor();
}

void Theme::printInput(const std::string& text) {
    std::cout << getInputColor() << text << getResetColor();
}

void Theme::printSuccess(const std::string& text) {
    std::cout << getSuccessColor() << text << getResetColor() << std::endl;
}

void Theme::printError(const std::string& text) {
    std::cout << getErrorColor() << text << getResetColor() << std::endl;
}

void Theme::printSeparator() {
    std::cout << getSeparatorColor() << "=========================================" << getResetColor() << std::endl;
}