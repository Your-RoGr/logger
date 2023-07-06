#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <ctime>
#include <mutex>
#include <vector>

class Logger {
public:
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    Logger(const std::string& filename, size_t maxEntries);
    ~Logger();

    void setLogLevel(LogLevel level);
    void log(LogLevel level, const std::string& message);
    void error(const std::string& errorMessage);
    void setLogFormat(const std::string& format);
    void addLogFile(const std::string& filename);
    void setLogFilter(const std::string& filter);
    void addLogOutputChannel(const std::string& channel);
    void setThreadSafe(bool threadSafe);

private:
    std::string filename;
    std::ofstream fileStream;
    std::vector<std::ofstream> fileStreams;
    LogLevel logLevel;
    std::string logFormat;
    std::string logFilter;
    std::string logOutputChannel;
    bool threadSafe;
    std::queue<std::string> logQueue;
    size_t maxEntries;
    std::mutex mutex;

    static std::string getFormattedTimestamp() ;
    static std::string getLogLevelString(LogLevel level) ;
    static std::string replacePlaceholder(const std::string& format, const std::string& placeholder, const std::string& value);
    void writeLogsToFile();
};

#endif // LOGGER_H
