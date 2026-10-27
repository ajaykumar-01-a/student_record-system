#include "core/application.h"
#include <iostream>
#include <string>
#include <limits>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showDashboard() {
    while (true) {
        clearScreen();
        std::cout << "========================================\n";
        std::cout << "   STUDENT RECORD SYSTEM - DASHBOARD\n";
        std::cout << "========================================\n\n";
        std::cout << "1. Student Management\n";
        std::cout << "2. Course Management\n";
        std::cout << "3. Grade Management\n";
        std::cout << "4. Attendance Tracking\n";
        std::cout << "5. Generate Reports\n";
        std::cout << "6. Settings\n";
        std::cout << "0. Exit\n\n";
        std::cout << "Select option: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                clearScreen();
                std::cout << "=== STUDENT MANAGEMENT ===\n";
                std::cout << "1. Add Student\n2. View Students\n3. Search Student\n4. Update Student\n5. Delete Student\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 2:
                clearScreen();
                std::cout << "=== COURSE MANAGEMENT ===\n";
                std::cout << "1. Add Course\n2. View Courses\n3. Enroll Student\n4. Course Details\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 3:
                clearScreen();
                std::cout << "=== GRADE MANAGEMENT ===\n";
                std::cout << "1. Add Grade\n2. View Grades\n3. Update Grade\n4. Generate Transcript\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 4:
                clearScreen();
                std::cout << "=== ATTENDANCE TRACKING ===\n";
                std::cout << "1. Mark Attendance\n2. View Attendance\n3. Attendance Report\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 5:
                clearScreen();
                std::cout << "=== REPORTS ===\n";
                std::cout << "1. Student Performance Report\n2. Attendance Summary\n3. Course Statistics\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 6:
                clearScreen();
                std::cout << "=== SETTINGS ===\n";
                std::cout << "1. Change Password\n2. Backup Data\n3. System Info\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 0:
                std::cout << "\nGoodbye!\n";
                return;
            default:
                std::cout << "\nInvalid option!\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
        }
    }
}

int main() {
    showDashboard();
    return 0;
}
