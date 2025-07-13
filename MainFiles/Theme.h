#ifndef THEME_H
#define THEME_H

#include <string>
#include <fstream>

class Theme {
public:
    enum Mode {
        LIGHT,
        DARK
    };

private:
    static Mode currentMode;
    static const std::string CONFIG_FILE;

    // ANSI Color codes for light mode
    static const std::string LIGHT_RESET;
    static const std::string LIGHT_HEADER;
    static const std::string LIGHT_MENU;
    static const std::string LIGHT_INPUT;
    static const std::string LIGHT_SUCCESS;
    static const std::string LIGHT_ERROR;
    static const std::string LIGHT_SEPARATOR;

    // ANSI Color codes for dark mode
    static const std::string DARK_RESET;
    static const std::string DARK_HEADER;
    static const std::string DARK_MENU;
    static const std::string DARK_INPUT;
    static const std::string DARK_SUCCESS;
    static const std::string DARK_ERROR;
    static const std::string DARK_SEPARATOR;

public:
    static void loadTheme();
    static void saveTheme();
    static void toggleMode();
    static Mode getCurrentMode();
    static void setMode(Mode mode);
    
    // Color getters based on current mode
    static std::string getResetColor();
    static std::string getHeaderColor();
    static std::string getMenuColor();
    static std::string getInputColor();
    static std::string getSuccessColor();
    static std::string getErrorColor();
    static std::string getSeparatorColor();
    
    // Utility functions
    static void clearScreen();
    static void printHeader(const std::string& text);
    static void printMenu(const std::string& text);
    static void printInput(const std::string& text);
    static void printSuccess(const std::string& text);
    static void printError(const std::string& text);
    static void printSeparator();
};

#endif // THEME_H