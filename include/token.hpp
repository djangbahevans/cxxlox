#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <any>
#include <string>

/**
 * @brief The type of the token
 *
 */
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

/**
 * @brief Converts a TokenType to a string
 *
 * @param type The TokenType to be converted
 * @return std::string The string representation of the TokenType
 */
std::string TokenTypeToString(TokenType type);

/**
 * @brief The token class
 *
 */
class Token {
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;

public:
  /**
   * @brief Construct a new Token object
   *
   * @param type The type of the token
   * @param lexeme The lexeme of the token
   * @param literal The literal value of the token
   * @param line The line number of the token
   */
  Token(TokenType type, std::string lexeme, std::any literal, int line);

  std::string toString() const;
  std::string literalToString() const;
};

#endif
