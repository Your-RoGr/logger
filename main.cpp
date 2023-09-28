#include "logger.h"
#include "timer.h"

int main() {

    Timer T {};

    Logger logger("logfile.txt", "", 8);

    logger.log(Logger::LogLevel::DEBUG, "console Debug message");
    logger.log(Logger::LogLevel::INFO, "console Info message");
    logger.log(Logger::LogLevel::WARNING, "console Warning message");
    logger.log(Logger::LogLevel::ERROR, "console Error message");
    logger.debug("console Debug message");
    logger.info("console Info message");
    logger.warning("console Warning message");
    logger.error("console Error message");

    logger.set_log_level(Logger::LogLevel::DEBUG);
    logger.set_use_file_log(true);

    // system("pause");

    for (int i = 0; i < 10; ++i) {
        logger.log(Logger::LogLevel::DEBUG, "file and console Debug message");
        logger.log(Logger::LogLevel::INFO, "file and console Info message");
        logger.log(Logger::LogLevel::WARNING, "file and console Warning message");
        logger.log(Logger::LogLevel::ERROR, "file and console Error message");
        logger.debug("file and console Debug message");
        logger.info("file and console Info message");
        logger.warning("file and console Warning message");
        logger.error("file and console Error message");
    }

    // system("pause");

    logger.set_log_format("[%level%] [%timestamp%] %message%");

    logger.log(Logger::LogLevel::DEBUG, "file and console Debug message");
    logger.log(Logger::LogLevel::INFO, "file and console Info message");
    logger.log(Logger::LogLevel::WARNING, "file and console Warning message");
    logger.log(Logger::LogLevel::ERROR, "file and console Error message");
    logger.debug("file and console Debug message");
    logger.info("file and console Info message");
    logger.warning("file and console Warning message");
    logger.error("file and console Error message");

    logger.set_clear_all(false);
    logger.set_filename("additional_logfile.log");

    logger.set_log_format("[%timestamp%] [%level%] %message%");

    logger.log(Logger::LogLevel::DEBUG, "file and console Debug message");
    logger.log(Logger::LogLevel::INFO, "file and console Info message");
    logger.log(Logger::LogLevel::WARNING, "file and console Warning message");
    logger.log(Logger::LogLevel::ERROR, "file and console Error message");
    logger.debug("file and console Debug message");
    logger.info("file and console Info message");
    logger.warning("file and console Warning message");
    logger.error("file and console Error message");

    logger.set_use_console_log(false);

    logger.log(Logger::LogLevel::DEBUG, "file Debug message");
    logger.log(Logger::LogLevel::INFO, "file Info message");
    logger.log(Logger::LogLevel::WARNING, "file Warning message");
    logger.log(Logger::LogLevel::ERROR, "file Error message");
    logger.debug("file Debug message");
    logger.info("file Info message");
    logger.warning("file Warning message");
    logger.error("file Error message");

    logger.log(Logger::LogLevel::DEBUG, "file Debug message");
    logger.log(Logger::LogLevel::INFO, "file Info message");
    logger.log(Logger::LogLevel::WARNING, "file Warning message");
    logger.log(Logger::LogLevel::ERROR, "file Error message");
    logger.debug("file Debug message");
    logger.info("file Info message");
    logger.warning("file Warning message");
    logger.error("file Error message");

    // system("pause");

    logger.set_max_entries(4);
    logger.set_max_files(1);

    logger.log(Logger::LogLevel::DEBUG, "file Debug message");
    logger.log(Logger::LogLevel::INFO, "file Info message");
    logger.log(Logger::LogLevel::WARNING, "file Warning message");
    logger.log(Logger::LogLevel::ERROR, "file Error message");
    logger.debug("file Debug message");
    logger.info("file Info message");
    logger.warning("file Warning message");
    logger.error("file Error message");

    // system("pause");

    logger.set_max_files(0);

    for (int i = 0; i < 10; ++i) {
        logger.log(Logger::LogLevel::DEBUG, "file Debug message");
        logger.log(Logger::LogLevel::INFO, "file Info message");
        logger.log(Logger::LogLevel::WARNING, "file Warning message");
        logger.log(Logger::LogLevel::ERROR, "file Error message");
        logger.debug("file Debug message");
        logger.info("file Info message");
        logger.warning("file Warning message");
        logger.error("file Error message");
    }

    // system("pause");

    logger.set_max_entries(0);

    for (int i = 0; i < 10; ++i) {
        logger.log(Logger::LogLevel::DEBUG, "file Debug message");
        logger.log(Logger::LogLevel::INFO, "file Info message");
        logger.log(Logger::LogLevel::WARNING, "file Warning message");
        logger.log(Logger::LogLevel::ERROR, "file Error message");
        logger.debug("file Debug message");
        logger.info("file Info message");
        logger.warning("file Warning message");
        logger.error("file Error message");
    }

    // system("pause");
    return 0;
}
