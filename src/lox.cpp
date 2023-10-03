#include "lox.hpp"
#include "scanner.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool Lox::hadError = false;

void Lox::error(int line, string message) { report(line, "", message); }

void Lox::report(int line, string where, string message) {
  cerr << "[line " << line << "] Error" << where << ": " << message << endl;
  Lox::hadError = true;
}

void Lox::runFile(string path) {
  ifstream file(path);
  string source;

  if (file.is_open()) {
    stringstream buffer;
    buffer << file.rdbuf();
    source = buffer.str();
  } else {
    cerr << "Could not open file " << path << "." << endl;
    exit(74);
  }

  run(source);
  if (Lox::hadError)
    exit(65);
}

void Lox::runPrompt() {
  string line;
  for (;;) {
    cout << "> ";
    getline(cin, line);
    if (line.empty())
      break;
    run(line);
  }
}

void Lox::run(string source) {
  Scanner scanner(source);
  vector<Token> tokens = scanner.scanTokens();

  for (Token token : tokens) {
    cout << token.toString() << endl;
  }
}

void Lox::run(vector<string> source) {
  for (string line : source) {
    cout << "I'm here at least" << line << endl;
    run(line);
  }
}
