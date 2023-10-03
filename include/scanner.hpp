#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "token.hpp"
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Scans the source code and returns a vector of tokens
 *
 */
class Scanner {
public:
  /**
   * @brief Construct a new Scanner object
   *
   * @param source The source code to be scanned
   */
  Scanner(std::string source);
  /**
   * @brief Scans the source code and returns a vector of tokens
   *
   * @return std::vector<Token> A vector of tokens
   */
  std::vector<Token> scanTokens();

private:
  int start{0};
  int current{0};
  int line{1};
  std::string source;
  std::vector<Token> tokens;
  std::unordered_map<std::string, TokenType> keywords;

  /**
   * @brief Scans the source code and returns a vector of tokens
   *
   */
  void scanToken();
  /**
   * @brief Checks if the scanner has reached the end of the source code
   *
   * @return true If the scanner has reached the end of the source code
   * @return false If the scanner has not reached the end of the source code
   */
  bool isAtEnd();
  /**
   * @brief Advances the scanner to the next character
   *
   * @return char The next character
   */
  char advance();
  /**
   * @brief Adds a token to the vector of tokens
   *
   * @param type The type of the token
   */
  void addToken(TokenType type);
  /**
   * @brief Adds a token to the vector of tokens
   *
   * @param type The type of the token
   * @param literal The literal value of the token
   */
  void addToken(TokenType type, std::any literal);
  /**
   * @brief Checks if the next character matches the expected character
   *
   * @param expected The expected character
   * @return true If the next character matches the expected character
   * @return false If the next character does not match the expected character
   */
  bool match(char expected);
  /**
   * @brief Returns the next character
   *
   * @return char The next character
   */
  char peek();
  /**
   * @brief Returns the character after the next character
   *
   * @return char The character after the next character
   */
  char peekNext();
  /**
   * @brief Checks if the character is a digit
   *
   * @param c The character to be checked
   * @return true If the character is a digit
   * @return false If the character is not a digit
   */
  bool isDigit(char c);
  /**
   * @brief Checks if the character is an alpha character
   *
   * @param c The character to be checked
   * @return true If the character is an alpha character
   * @return false If the character is not an alpha character
   */
  bool isAlpha(char c);
  /**
   * @brief Checks if the character is alphanumeric
   *
   * @param c The character to be checked
   * @return true If the character is alphanumeric
   * @return false If the character is not alphanumeric
   */
  bool isAlphaNumeric(char c);
  /**
   * @brief Scans a number
   *
   */
  void number();
  /**
   * @brief Scans an identifier
   *
   */
  void identifier();
  /**
   * @brief Scans a string
   *
   */
  void string();
  /**
   * @brief Scans a multiline comment
   *
   */
  void multilineComment();
};
#endif
