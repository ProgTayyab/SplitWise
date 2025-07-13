#include <iostream>
#include <cassert>
#include "Theme.h"

void testThemeToggle() {
    std::cout << "Testing Theme Toggle functionality...\n";
    
    // Test initial mode
    Theme::Mode initialMode = Theme::getCurrentMode();
    std::cout << "Initial mode: " << (initialMode == Theme::LIGHT ? "Light" : "Dark") << "\n";
    
    // Toggle mode
    Theme::toggleMode();
    Theme::Mode toggledMode = Theme::getCurrentMode();
    std::cout << "After toggle: " << (toggledMode == Theme::LIGHT ? "Light" : "Dark") << "\n";
    
    // Assert that mode has changed
    assert(initialMode != toggledMode);
    
    // Toggle back
    Theme::toggleMode();
    Theme::Mode finalMode = Theme::getCurrentMode();
    std::cout << "After second toggle: " << (finalMode == Theme::LIGHT ? "Light" : "Dark") << "\n";
    
    // Assert that we're back to the original mode
    assert(initialMode == finalMode);
    
    std::cout << "✓ Theme toggle test passed!\n";
}

void testColorOutput() {
    std::cout << "\nTesting Color Output in Light Mode:\n";
    Theme::setMode(Theme::LIGHT);
    Theme::printHeader("HEADER TEXT");
    Theme::printMenu("Menu text\n");
    Theme::printInput("Input prompt: ");
    std::cout << "test input\n";
    Theme::printSuccess("Success message");
    Theme::printError("Error message");
    Theme::printSeparator();
    
    std::cout << "\nTesting Color Output in Dark Mode:\n";
    Theme::setMode(Theme::DARK);
    Theme::printHeader("HEADER TEXT");
    Theme::printMenu("Menu text\n");
    Theme::printInput("Input prompt: ");
    std::cout << "test input\n";
    Theme::printSuccess("Success message");
    Theme::printError("Error message");
    Theme::printSeparator();
    
    std::cout << "\n✓ Color output test completed!\n";
}

int main() {
    std::cout << "=== Dark Mode Theme System Tests ===\n\n";
    
    // Load theme
    Theme::loadTheme();
    
    // Run tests
    testThemeToggle();
    testColorOutput();
    
    std::cout << "\n=== All tests passed! ===\n";
    
    // Reset colors
    std::cout << Theme::getResetColor();
    
    return 0;
}