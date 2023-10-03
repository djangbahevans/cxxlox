#ifndef LOX_HPP
#define LOX_HPP

#include <string>
#include <vector>

class Lox {
public:
  static bool hadError;
  static void runFile(std::string path);
  static void runPrompt();
  static void error(int line, std::string message);

private:
  static void run(std::string source);
  static void run(std::vector<std::string> source);
  static void report(int line, std::string where, std::string message);
};

#endif
