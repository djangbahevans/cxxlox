#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <any>
#include <string>

enum TokenType {
  // Single character tokens
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  // One or two character tokens
  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  // Literals
  IDENTIFIER,
  STRING,
  NUMBER,

  // KEYWORDS,
  AND,
  CLASS,
  ELSE,
  FALSE,
  FUN,
  FOR,
  IF,
  NIL,
  OR,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,

  EOF_
};

std::string TokenTypeToString(TokenType type);

class Token {
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;

public:
  Token(TokenType type, std::string lexeme, std::any literal, int line);

  std::string toString() const;
  std::string literalToString() const;
};

#endif
