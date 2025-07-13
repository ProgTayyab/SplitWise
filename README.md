# SplitWise - Expense Sharing Application

A C++ console-based application for managing personal, friend, and group expenses with **Dark Mode** support!

## Features

### Core Functionality
- **Personal Expenses**: Track your individual expenses
- **Friend Expenses**: Share expenses with friends
- **Group Expenses**: Manage group expenses with multiple members
- **Groups Management**: Create and manage expense groups
- **Expense Display**: View all your expenses by category
- **Expense Deletion**: Remove expenses by category and serial number

### 🌙 NEW: Dark Mode Support
- **Theme Switcher**: Toggle between Light and Dark modes
- **Persistent Preferences**: Your theme choice is saved automatically
- **Enhanced UI**: Colored output with ANSI escape codes
- **Settings Menu**: Easy access to theme options

## Quick Start

### Building the Application
```bash
# Make the build script executable and run it
chmod +x build.sh
./build.sh
```

### Running the Application
```bash
# Start SplitWise
./MainFiles/splitwise
```

### Running Tests
```bash
# Test the dark mode functionality
./MainFiles/test_theme
```

## How to Use Dark Mode

1. Launch SplitWise
2. Complete the login process
3. From the main menu, select **"7. Settings"**
4. Choose **"1. Toggle Dark Mode"**
5. Your theme will switch immediately!

Your theme preference is automatically saved and will be restored when you restart the application.

## Menu Navigation

### Main Menu
1. Add Personal Expense
2. Add Group Expense  
3. Add Friend Expense
4. Create Group
5. Display Expenses
6. Delete Expense
7. **Settings** ← Dark Mode Toggle Here!
8. Exit

### Settings Menu
1. **Toggle Dark Mode** (shows current theme)
2. Back to Main Menu

## Color Themes

### Light Mode (Default)
- Clean, professional appearance
- High contrast for readability
- Traditional console colors

### Dark Mode
- Modern dark theme
- Reduced eye strain
- Bright accent colors on dark background

## Technical Details

### Requirements
- C++ compiler (g++)
- Terminal with ANSI color support
- Linux/Unix environment (tested on Ubuntu)

### File Structure
```
SplitWise/
├── MainFiles/
│   ├── main.cpp           # Main application
│   ├── User.cpp/h         # User management
│   ├── Login.cpp/h        # Authentication
│   ├── Dashboard.cpp/h    # Expense management
│   ├── expense.cpp        # Expense classes
│   ├── Expense.h          # Expense headers
│   ├── Theme.cpp/h        # 🌙 Dark mode system
│   └── test_theme.cpp     # Theme tests
├── build.sh               # Build script
├── .gitignore            # Git ignore rules
└── DARK_MODE_FEATURE.md  # Detailed feature docs
```

### Dependencies
- Standard C++ libraries
- No external dependencies required

## Development

### Compilation
```bash
g++ -o splitwise main.cpp Login.cpp expense.cpp Dashboard.cpp User.cpp Theme.cpp
```

### Testing
The application includes a comprehensive test suite for the dark mode functionality:
```bash
g++ -o test_theme test_theme.cpp Theme.cpp
./test_theme
```

## Contributing

Feel free to contribute to this project! Areas for improvement:
- Additional color themes
- Enhanced UI elements
- More expense management features
- Cross-platform compatibility

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

**Enjoy using SplitWise with Dark Mode! 🌙**