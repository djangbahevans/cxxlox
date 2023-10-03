#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "token.hpp"
#include <string>
#include <vector>
#include <unordered_map>

class Scanner {
public:
  Scanner(std::string source);
  std::vector<Token> scanTokens();

private:
  int start{0};
  int current{0};
  int line{1};
  std::string source;
  std::vector<Token> tokens;
  std::unordered_map<std::string, TokenType> keywords;

  void scanToken();
  bool isAtEnd();
  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, std::any literal);
  bool match(char expected);
  char peek();
  void string();
  bool isDigit(char c);
  void number();
  char peekNext();
  bool isAlpha(char c);
  bool isAlphaNumeric(char c);
  void identifier();
};
#endif
