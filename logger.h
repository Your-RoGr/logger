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
    LogLevel log_level = LogLevel::INFO;
    std::string log_format = "[%timestamp%] [%level%] %message%";
    bool console = true;
    bool file = false;
    bool clear_all = true;
    std::queue<std::string> log_queue_files {};
    std::queue<std::string> log_queue_file {};
    std::queue<std::string> log_queue_console {};
    size_t max_entries {};
    size_t max_entries_counter {};
    size_t max_files = 5;
    size_t log_file_number = 0;
public:
    explicit Logger(const std::string& filename_, size_t max_entries_ = 1000000);
    ~Logger();

    void log(LogLevel level, const std::string& message);
    void info(const std::string& info_message);
    void debug(const std::string& debug_message);
    void warning(const std::string& warning_message);
    void error(const std::string& error_message);
    // LogLevel::INFO by default
    void set_log_level(LogLevel level);
    // "[%timestamp%] [%level%] %message%" by default
    void set_log_format(const std::string& format);
    void set_use_console_log(bool console_);
    void set_use_file_log(bool file_);
    void set_clear_all(bool clear_all_);
    void set_filename(const std::string& filename_,  size_t max_entries_ = 1000000);
    void set_max_entries(size_t max_entries_);
    void set_max_files(size_t max_files_);
private:
    void open_file();
    void delete_first_file();
    void delete_all_files();
    void write_logs_to_file();
    void write_logs_file();
    void write_logs_to_console();
    void add_current_files();
    size_t get_count_of_lines();
    static bool is_valid_filename(const std::string& filename);
    static std::string get_formatted_timestamp();
    static std::string get_log_level_string(LogLevel level);
    static std::string replace_placeholder(const std::string& format, const std::string& placeholder,
                                           const std::string& value);
};

#endif // LOGGER_H
