# Dark Mode Feature Documentation

## Overview
A dark mode switcher has been successfully implemented for the SplitWise C++ console application. This feature allows users to toggle between light and dark color themes, enhancing the user experience and providing visual customization options.

## Features Implemented

### 1. Theme System (`Theme.h` / `Theme.cpp`)
- Complete theme management system with ANSI color codes
- Support for both Light and Dark modes
- Dynamic color switching for different UI elements:
  - Headers (Bold Blue/Bright Magenta)
  - Menu items (Green/Bright Cyan)
  - Input prompts (Cyan/Bright Yellow)
  - Success messages (Bold Green/Bold Bright Green)
  - Error messages (Bold Red/Bold Bright Red)
  - Separators (Yellow/Bright Blue)

### 2. Settings Menu
- Added option 7 "Settings" to the main menu
- Settings submenu with dark mode toggle option
- Shows current theme status (Light/Dark)
- Instant theme switching with visual feedback

### 3. Theme Persistence
- Automatic saving of theme preference to `theme_config.txt`
- Theme preference loads automatically on application startup
- Seamless experience across app sessions

### 4. Enhanced UI
- All expense displays now use themed colors
- Improved visual hierarchy with colored headers and separators
- Better user feedback with colored success/error messages
- Clear screen functionality for better visual transitions

## How to Use

### Accessing Dark Mode
1. Launch the SplitWise application
2. Navigate to the main menu
3. Select option "7. Settings"
4. Choose "1. Toggle Dark Mode"
5. The theme will switch immediately

### Theme Persistence
- Your theme preference is automatically saved
- When you restart the application, your preferred theme is restored
- No manual configuration required

## Technical Implementation

### Color Schemes

#### Light Mode Colors:
- Headers: Bold Blue (`\033[1;34m`)
- Menu: Green (`\033[0;32m`)
- Input: Cyan (`\033[0;36m`)
- Success: Bold Green (`\033[1;32m`)
- Error: Bold Red (`\033[1;31m`)
- Separator: Yellow (`\033[0;33m`)

#### Dark Mode Colors:
- Headers: Bold Bright Magenta (`\033[1;95m`)
- Menu: Bright Cyan (`\033[0;96m`)
- Input: Bright Yellow (`\033[0;93m`)
- Success: Bold Bright Green (`\033[1;92m`)
- Error: Bold Bright Red (`\033[1;91m`)
- Separator: Bright Blue (`\033[0;94m`)

### Files Modified/Added:
- `Theme.h` - Theme system header
- `Theme.cpp` - Theme system implementation
- `main.cpp` - Added settings menu and theme integration
- `expense.cpp` - Updated to use themed display
- `Dashboard.cpp` - Updated to use themed display
- `Login.h`, `User.h`, `Dashboard.h`, `Expense.h` - Created missing headers

## Testing
- Comprehensive test suite included (`test_theme.cpp`)
- Tests theme toggling functionality
- Validates color output in both modes
- Confirms theme persistence across restarts

## Benefits
1. **Enhanced User Experience**: Users can choose their preferred visual theme
2. **Accessibility**: Dark mode reduces eye strain in low-light environments
3. **Modern UI**: Follows contemporary application design trends
4. **Persistent Preferences**: User choices are remembered across sessions
5. **Easy Integration**: Minimal changes to existing codebase

## Future Enhancements
- Additional color themes (e.g., high contrast, colorblind-friendly)
- Custom color configuration
- Background color support for terminals that support it
- Animation effects during theme switching

The dark mode switcher is now fully functional and ready for use!