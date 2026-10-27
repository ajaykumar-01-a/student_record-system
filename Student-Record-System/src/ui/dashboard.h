#ifndef STUDENT_RECORD_SYSTEM_UI_DASHBOARD_H
#define STUDENT_RECORD_SYSTEM_UI_DASHBOARD_H

#include <string>
#include <memory>

namespace srs::ui {

class Dashboard {
public:
    Dashboard();
    ~Dashboard() = default;

    // Main entry point
    void run();

private:
    // Main menu screens
    void show_main_menu();
    void show_login_screen();
    void show_admin_dashboard();
    void show_teacher_dashboard();
    void show_student_dashboard();

    // Student Management
    void manage_students();
    void add_student();
    void view_students();
    void search_student();
    void update_student();
    void delete_student();

    // Course Management
    void manage_courses();
    void add_course();
    void view_courses();
    void enroll_student();

    // Grade Management
    void manage_grades();
    void add_grade();
    void view_grades();
    void generate_transcript();

    // Attendance Management
    void manage_attendance();
    void mark_attendance();
    void view_attendance();

    // Reports
    void generate_reports();
    void student_performance_report();
    void attendance_report();
    void course_statistics();

    // Settings
    void show_settings();
    void change_password();
    void backup_data();

    // Utility functions
    void show_statistics_panel();
    bool confirm_action(const std::string& message);

    // User session
    std::string current_user_;
    std::string user_role_;  // "admin", "teacher", "student"
    bool is_logged_in_;
};

}  // namespace srs::ui

#endif  // STUDENT_RECORD_SYSTEM_UI_DASHBOARD_H
