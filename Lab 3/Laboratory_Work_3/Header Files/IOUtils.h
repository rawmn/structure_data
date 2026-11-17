#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>

inline void ClearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

inline std::string ReadLine()
{
    std::string line;
    if (!std::getline(std::cin, line))
    {
        std::cout << std::endl;
        std::exit(0);
    }
    return line;
}

inline bool ParseInt(const std::string& source, int& result)
{
    const char* whitespace = " \t\r\n";
    size_t begin = source.find_first_not_of(whitespace);
    if (begin == std::string::npos)
    {
        return false;
    }
    size_t end = source.find_last_not_of(whitespace);
    std::string text = source.substr(begin, end - begin + 1);

    char* parsedEnd = nullptr;
    errno = 0;
    long value = std::strtol(text.c_str(), &parsedEnd, 10);
    if (errno == ERANGE || *parsedEnd != '\0')
    {
        return false;
    }
    if (value < INT_MIN || value > INT_MAX)
    {
        return false;
    }
    result = static_cast<int>(value);
    return true;
}


inline int ReadInt(const char* prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (ParseInt(ReadLine(), value))
        {
            return value;
        }
        std::cout << "Invalid input: enter a whole number.\n";
    }
}


inline int ReadChoice(int min, int max, std::string& message)
{
    std::cout << "Choice: ";
    int value;
    if (!ParseInt(ReadLine(), value) || value < min || value > max)
    {
        message = "Invalid choice. Enter a number from " + std::to_string(min) +
                  " to " + std::to_string(max) + ".";
        return -1;
    }
    return value;
}

inline void PrintMessage(std::string& message)
{
    if (!message.empty())
    {
        std::cout << ">> " << message << "\n\n";
        message.clear();
    }
}
