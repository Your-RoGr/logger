#include "logger.h"

Logger::Logger(const std::string& filename, size_t maxEntries) : maxEntries(maxEntries), filename(filename) {
    fileStream.open(filename, std::ios::app);
    logLevel = LogLevel::INFO; // Устанавливаем уровень логирования по умолчанию
    logFormat = "[%timestamp%] [%level%] %message%";
    logFilter = "";
    logOutputChannel = "file";
    threadSafe = false;
}

Logger::~Logger() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void Logger::setLogLevel(LogLevel level) {
    logLevel = level;
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level >= logLevel) {
        std::string timestamp = getFormattedTimestamp();
        std::string levelString = getLogLevelString(level);
        std::string formattedMessage = logFormat;
        // Заменяем плейсхолдеры в формате сообщения
        formattedMessage = replacePlaceholder(formattedMessage, "%timestamp%", timestamp);
        formattedMessage = replacePlaceholder(formattedMessage, "%level%", levelString);
        formattedMessage = replacePlaceholder(formattedMessage, "%message%", message);

        if (threadSafe) {
            // Если потокобезопасность включена, выполняем блокировку перед записью в очередь
            // и разблокировку после записи
            std::lock_guard<std::mutex> lock(mutex);
            logQueue.push(formattedMessage);
        } else {
            logQueue.push(formattedMessage);
        }

        // Проверяем, достигнуто ли максимальное количество записей, и записываем логи в файл
        if (logQueue.size() >= maxEntries) {
            writeLogsToFile();
        }
    }
}

void Logger::error(const std::string& errorMessage) {
    log(LogLevel::ERROR, errorMessage);
}

void Logger::setLogFormat(const std::string& format) {
    logFormat = format;
}

void Logger::addLogFile(const std::string& filename_) {
    // Проверяем, открыт ли уже файловый поток. Если да, закрываем его
    if (fileStream.is_open()) {
        fileStream.close();
    }

    // Открываем новый файловый поток для добавленного лог-файла
    std::ofstream newFileStream(filename_, std::ios::app);
    if (newFileStream.is_open()) {
        // Добавляем новый файловый поток в вектор файловых потоков
        fileStreams.push_back(std::move(newFileStream));
    }
}

void Logger::setLogFilter(const std::string& filter) {
    logFilter = filter;
}

void Logger::addLogOutputChannel(const std::string& channel) {
    logOutputChannel = channel;
}

void Logger::setThreadSafe(bool threadSafe_) {
    this->threadSafe = threadSafe_;
}

std::string Logger::getFormattedTimestamp() {
    std::time_t now = std::time(nullptr);
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return {timestamp};
}

std::string Logger::getLogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "";
    }
}

std::string Logger::replacePlaceholder(const std::string& format, const std::string& placeholder, const std::string& value) {
    std::string result = format;
    size_t pos = result.find(placeholder);
    while (pos != std::string::npos) {
        result.replace(pos, placeholder.length(), value);
        pos = result.find(placeholder, pos + value.length());
    }
    return result;
}

void Logger::writeLogsToFile() {
    // Проверяем, есть ли открытый файловый поток
    if (!fileStream.is_open()) {
        // Если открытого файлового потока нет, открываем его снова
        fileStream.open(filename, std::ios::app);
    }

    // Записываем логи из очереди в основной файл логов
    while (!logQueue.empty()) {
        std::string logEntry = logQueue.front();
        logQueue.pop();
        fileStream << logEntry << std::endl;
    }

    // Записываем логи из очереди в дополнительные файлы логов
    for (std::ofstream& fs : fileStreams) {
        while (!logQueue.empty()) {
            std::string logEntry = logQueue.front();
            logQueue.pop();
            fs << logEntry << std::endl;
        }
    }
}
