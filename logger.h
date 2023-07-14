#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <ctime>
#include <vector>
#include <regex>
#include <filesystem>

// Logger class for logs
// explicit Logger(const std::string& filename_, const std::string& path_folder_, size_t max_entries_);
// const std::string& path_folder_ = "logs", size_t max_entries_ = 1000000 by default
class Logger {
public:
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };
private:
    std::string filename {};
    std::ofstream file_stream {};
    LogLevel log_level_console = LogLevel::INFO;
    LogLevel log_level_file = LogLevel::WARNING;
    std::string log_format = "[%timestamp%] [%level%] %message%";
    std::string path_folder {};
    bool console = true;
    bool file = false;
    bool clear_all = false;
    std::queue<std::string> log_queue_files {};
    std::queue<std::string> log_queue_file {};
    std::queue<std::string> log_queue_console {};
    size_t max_entries {};
    size_t max_entries_counter {};
    size_t max_files = 5;
    size_t log_file_number = 0;
public:
    explicit Logger(const std::string& filename_, const std::string& path_folder_ = "logs",
                    size_t max_entries_ = 1000000);
    ~Logger();

    void log(LogLevel level, const std::string& message);
    void info(const std::string& info_message);
    void debug(const std::string& debug_message);
    void warning(const std::string& warning_message);
    void error(const std::string& error_message);
    // LogLevel::INFO by default
    void set_log_level(LogLevel level);
    // LogLevel::WARNING by default
    void set_log_level_console(LogLevel level);
    // LogLevel::INFO by default
    void set_log_level_file(LogLevel level);
    // "[%timestamp%] [%level%] %message%" by default
    void set_log_format(const std::string& format);
    // true by default
    void set_use_console_log(bool console_);
    // false by default
    void set_use_file_log(bool file_);
    // false by default
    void set_clear_all(bool clear_all_);
    // const std::string& path_folder_ = "logs", size_t max_entries_ = 1000000 by default
    void set_filename(const std::string& filename_, const std::string& path_folder_ = "logs",
                      size_t max_entries_ = 1000000);
    // size_t max_entries_ = 1000000 by default
    void set_max_entries(size_t max_entries_);
    // size_t max_files_ = 5 by default
    void set_max_files(size_t max_files_);
private:
    void open_file();
    void delete_first_file();
    void delete_all_files();
    void write_logs_to_file();
    void write_logs_file();
    void write_logs_to_console();
    void add_current_files();
    void create_folder();
    size_t get_count_of_lines();
    static bool is_valid_filename(const std::string& filename);
    static bool is_valid_path_folder(const std::string& path_folder);
    static std::string get_formatted_timestamp();
    static std::string get_log_level_string(LogLevel level);
    static std::string replace_placeholder(const std::string& format, const std::string& placeholder,
                                           const std::string& value);
};

#endif // LOGGER_H
