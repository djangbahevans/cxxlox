#include "lox.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  if (argc > 2) {
    cout << "Usage: lox [script]" << endl;
    return 64;
  } else if (argc == 2) {
    Lox::runFile(argv[1]);
  } else {
    Lox::runPrompt();
  }
  return 0;
}
