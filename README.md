# Logger

Данный репозиторий посвящен программе логеру на C++

- [Features](##Features)
- [Tech](##Tech)
- [Installation](##Installation)
- [Usage](##Usage)
- [Files](##Files)

## Features

Уровни логирования реализованы в виде enum class LogLevel:

| Уровень | Представление |
| ------ | ------ |
| DEBUG | Logger::LogLevel::DEBUG |
| INFO | Logger::LogLevel::INFO |
| WARNING | Logger::LogLevel::WARNING |
| ERROR | Logger::LogLevel::ERROR |

Имеются следующие функии сеттеры для полей:

| Функия сеттер | Аргументы | Значение полей в class Logger | Описание |
| ------ | ------ | ------ |  ------ | 
| set_log_level | LogLevel level | - | Устанавливает уровень логирования для консоли и файла |
| set_log_level_console | LogLevel level | LogLevel::WARNING | Устанавливает уровень логирования для консоли |
| set_log_level_file | LogLevel level | LogLevel::INFO | Устанавливает уровень логирования для файла |
| set_log_format | const std::string& format | [%timestamp%] [%level%] %message%" | Устанавливает формат вывода логов |
| set_use_console_log | bool console_ | true | Устанавливает флаг использования вывода в консоль (_true_ включить) |
| set_use_file_log | bool file_ | true | Устанавливает флаг использования вывода в файлы (_true_ включить) |
| set_clear_all | bool clear_all_ | false | При _true_ удаляет все файлы логов в директории (с таким же наименованием) при создании объекта класса Logger или при вызове set_filename |
| set_filename | const std::string& filename_, const std::string& path_folder_ = "logs", size_t max_entries_ = 1000000 | const std::string& path_folder_ = "logs", size_t max_entries_ = 1000000 | Устанвливает новое название файлов |
| set_max_entries | size_t max_entries_ | size_t max_entries_ = 1000000 | Устанвливает количество записей в одном файле |
| set_max_files | size_t max_files_ | size_t max_files_ = 5 | Устанавливает максимальное количество файлов |

## Tech

Для работы Logger использует стандарт&nbsp; _C++20_:

- [MinGW](https://winlibs.com/) - Компилятор MinGW
> При тестировании испльзовался следующий компилятор:
> GCC 13.2.0 (with POSIX threads) + LLVM/Clang/LLD/LLDB 16.0.6 + MinGW-w64 11.0.0 (UCRT) - release 1
- [cppreference](https://ru.cppreference.com/w/cpp/20) - Всё о стандарте&nbsp; _C++20_

## Installation

> 1. Архив с компилятором необходимо разархивировать в удобное место (обычно в _C:\mingw64_)
> 2. Добавить в переменные среды в системные переменные в Path:
     > 2.1 _C:\mingw64_
     > 2.2 _C:\mingw64\bin_
> 3. Проверить работоспособность компилятора в консоле:
```sh
gcc -v
```
> 4. Выбрать MinGW в IDE для компиляции (Если используете IDE)

## Usage

| Функия | Аргументы | Описание |
| ------ | ------ | ------ |
| Logger | const std::string& filename_, const std::string& path_folder_ = "logs", size_t max_entries_ = 1000000, size_t max_files_ = 5 | Конструктор класса Logger |
| log | LogLevel level, const std::string& message | Записывает log с выбранным уровнем логирования |
| debug | const std::string& debug_message | Записывает log с уровнем логирования DEBUG |
| info | const std::string& info_message | Записывает log с уровнем логирования INFO |
| warning | const std::string& warning_message | Записывает log с уровнем логирования WARNING |
| error | const std::string& error_message | Записывает log с уровнем логирования ERROR |

- Пример использования:
```С++
#include "logger.h"

int main() {
    Logger logger("logfile.txt", "logs", 8);

    logger.log(Logger::LogLevel::WARNING, "console Warning message");
    logger.debug("console Debug message");
    logger.info("console Info message");
    logger.warning("console Warning message");
    logger.error("console Error message");
}
```

- Вывод в консоли:
```sh
[30-09-2020 21:59:05] [WARNING] console Warning message
[30-09-2020 21:59:05] [INFO] console Info message
[30-09-2020 21:59:05] [WARNING] console Warning message
[30-09-2020 21:59:05] [ERROR] console Error message
```

Как видно из примера, лог с уровнем логирования DEBUG не вывелся в консоль

## Files

- CMakeLists.txt - файл настроек для сборки программного проекта с помощью CMake
- logger.cpp - файл с реализацией логера
- logger.h - файл с объявлениями класса логера и его функций
- main.cpp - файл с нативными тестами
- timer.cpp - файл с реализацией таймера для main.cpp
- timer.h - файл с объявлениями функций и классов для timer.cpp

## License

MIT

**Free Software, Hell Yeah!**