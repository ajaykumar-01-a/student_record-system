#ifndef STUDENT_RECORD_SYSTEM_UI_CONSOLE_HELPER_H
#define STUDENT_RECORD_SYSTEM_UI_CONSOLE_HELPER_H

#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

namespace srs::ui {

class ConsoleHelper {
public:
    // Clear the console screen
    static void clear_screen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    // Print a horizontal line
    static void print_line(char ch = '=', int length = 60) {
        std::cout << std::string(length, ch) << '\n';
    }

    // Print a header with borders
    static void print_header(const std::string& title) {
        clear_screen();
        print_line('=', 60);
        std::cout << "  " << title << '\n';
        print_line('=', 60);
        std::cout << '\n';
    }

    // Print a section separator
    static void print_section(const std::string& section) {
        std::cout << '\n';
        print_line('-', 60);
        std::cout << "  " << section << '\n';
        print_line('-', 60);
    }

    // Wait for user to press Enter
    static void wait_for_enter() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    // Get user input with prompt
    static std::string get_input(const std::string& prompt) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    // Get integer input with validation
    static int get_int_input(const std::string& prompt, int min, int max) {
        while (true) {
            std::cout << prompt;
            std::string input;
            std::getline(std::cin, input);
            
            try {
                int value = std::stoi(input);
                if (value >= min && value <= max) {
                    return value;
                }
                std::cout << "Please enter a number between " << min << " and " << max << ".\n";
            } catch (...) {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
    }

    // Print success message
    static void print_success(const std::string& message) {
        std::cout << "\n[SUCCESS] " << message << '\n';
    }

    // Print error message
    static void print_error(const std::string& message) {
        std::cout << "\n[ERROR] " << message << '\n';
    }

    // Print info message
    static void print_info(const std::string& message) {
        std::cout << "\n[INFO] " << message << '\n';
    }

    // Set console color (Windows)
    static void set_color(int color) {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
#endif
    }

    // Color codes for Windows
    enum Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        YELLOW = 6,
        WHITE = 7,
        GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        LIGHT_YELLOW = 14,
        BRIGHT_WHITE = 15
    };
};

}  // namespace srs::ui

#endif  // STUDENT_RECORD_SYSTEM_UI_CONSOLE_HELPER_H
