/**
 * @file main.cc
 * @author Hare
 * @brief Main program body
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main.h"

void ShowHelloWorld();

/**
 * @brief The application entry point
 *
 * @return int The application exit code
 */
auto main() -> int { ShowHelloWorld(); }

/**
 * @brief print "Hello world!"
 *
 */
void ShowHelloWorld() { std::cout << "你好!" << std::endl; }
