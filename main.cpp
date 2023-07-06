#include <iostream>
#include "logger.h"

int main() {
    // Создаем объект логгера и указываем имя файла логов и максимальное количество записей
    Logger logger("logfile.txt", 10);

    // Устанавливаем уровень логирования
    logger.setLogLevel(Logger::LogLevel::DEBUG);

    // Записываем логи
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");

    // Устанавливаем формат логов
    logger.setLogFormat("[%level%] %message%");

    // Записываем логи с новым форматом
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");

    // Добавляем новый лог-файл
    logger.addLogFile("additional_logfile.txt");

    // Записываем логи в новый файл
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");

    // Устанавливаем фильтр для логов
    logger.setLogFilter("DEBUG");

    // Записываем отфильтрованные логи
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");

    // Добавляем дополнительный канал вывода
    logger.addLogOutputChannel("console");

    // Записываем логи в основной файл и в консоль
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");

    // Устанавливаем потокобезопасность
    logger.setThreadSafe(true);

    // Записываем потокобезопасные логи
    logger.log(Logger::LogLevel::DEBUG, "Debug message");
    logger.log(Logger::LogLevel::INFO, "Info message");
    logger.log(Logger::LogLevel::WARNING, "Warning message");
    logger.log(Logger::LogLevel::ERROR, "Error message");
    system("pause");
    return 0;
}
