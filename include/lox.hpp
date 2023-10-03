#ifndef LOX_HPP
#define LOX_HPP

#include <string>
#include <vector>

/*
 * @brief The main class of the Lox interpreter
 *
 */
class Lox {
public:
  static bool hadError;
  /**
   * @brief Runs the interpreter on a file
   *
   * @param path The path to the file
   */
  static void runFile(std::string path);
  /**
   * @brief Runs the interpreter in REPL mode
   *
   */
  static void runPrompt();
  /**
   * @brief Runs the interpreter on a string
   *
   * @param source The string to be interpreted
   */
  static void error(int line, std::string message);

private:
  /**
   * @brief Runs the interpreter on a string
   *
   * @param source The string to be interpreted
   */
  static void run(std::string source);
  /**
   * @brief Reports an error
   *
   * @param line The line number of the error
   * @param where The location of the error
   * @param message The error message
   */
  static void report(int line, std::string where, std::string message);
};

#endif
