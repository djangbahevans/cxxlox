#include "scanner.hpp"
#include "lox.hpp"
#include "token.hpp"
#include <any>
#include <string>
#include <vector>

using namespace std;

Scanner::Scanner(std::string source) : source(source) {
  keywords = {
      {"and", AND},   {"class", CLASS}, {"else", ELSE},     {"false", FALSE},
      {"for", FOR},   {"fun", FUN},     {"if", IF},         {"nil", NIL},
      {"or", OR},     {"print", PRINT}, {"return", RETURN}, {"super", SUPER},
      {"this", THIS}, {"true", TRUE},   {"var", VAR},       {"while", WHILE},
  };
}

vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    // We're at the beginning of the next lexeme
    start = current;
    scanToken();
  }

  tokens.push_back(Token(EOF_, "", nullptr, line));
  return tokens;
}

void Scanner::scanToken() {
  char c = advance();
  switch (c) {
  case '(':
    addToken(LEFT_PAREN);
    break;
  case ')':
    addToken(RIGHT_PAREN);
    break;
  case '{':
    addToken(LEFT_BRACE);
    break;
  case '}':
    addToken(RIGHT_BRACE);
    break;
  case ',':
    addToken(COMMA);
    break;
  case '.':
    addToken(DOT);
    break;
  case '-':
    addToken(MINUS);
    break;
  case '+':
    addToken(PLUS);
    break;
  case ';':
    addToken(SEMICOLON);
    break;
  case '*':
    addToken(STAR);
    break;
  case '!':
    addToken(match('=') ? BANG_EQUAL : BANG);
    break;
  case '=':
    addToken(match('=') ? EQUAL_EQUAL : EQUAL);
    break;
  case '<':
    addToken(match('=') ? LESS_EQUAL : LESS);
    break;
  case '>':
    addToken(match('=') ? GREATER_EQUAL : GREATER);
    break;
  case '/':
    if (match('/')) {
      // A comment goes until the end of the line
      while (peek() != '\n' && !isAtEnd())
        advance();
    } else if (match('*')) {
      multilineComment();
    } else {
      addToken(SLASH);
    }
  case ' ':
  case '\r':
  case '\t':
    // Ignore whitespace
    break;
  case '\n':
    line++;
    break;
  case ':':
    string();
    break;
  default:
    if (isDigit(c)) {
      number();
    } else if (isAlpha(c)) {
      identifier();
    } else {
      Lox::error(line, "Unexpected character.");
    }
    break;
  }
}

bool Scanner::isAtEnd() { return current >= source.length(); }

char Scanner::advance() { return source[current++]; }

void Scanner::addToken(TokenType type) { addToken(type, nullptr); }

void Scanner::addToken(TokenType type, any literal) {
  std::string text = source.substr(start, current - start);
  tokens.push_back(Token(type, text, literal, line));
}

bool Scanner::match(char expected) {
  if (isAtEnd())
    return false;
  if (source.at(current) != expected)
    return false;

  current++;
  return true;
}

char Scanner::peek() {
  if (isAtEnd())
    return '\0';
  return source.at(current);
}

void Scanner::string() {
  while (peek() != '"') {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd()) {
    Lox::error(line, "Unterminated string");
    return;
  }

  // The closing ".
  advance();

  // Trim the surrounding quotes.
  std::string value = source.substr(start + 1, current - start - 2);
  addToken(STRING, value);
}

bool Scanner::isDigit(char c) { return c >= '0' && c <= '9'; }

void Scanner::number() {
  while (isDigit(peek()))
    advance();

  // Look for the fractional part.
  if (peek() == '.' && isDigit(peekNext())) {
    // Consume the "."
    advance();

    while (isDigit(peek()))
      advance();
  }

  addToken(NUMBER,
           stod(source.substr(start, current-start)));
}

char Scanner::peekNext() {
  if (current + 1 > source.length())
    return '\0';
  return source.at(current + 1);
}

void Scanner::identifier() {
  while (isAlphaNumeric(peek()))
    advance();

  std::string text =
      source.substr(start, current-start);
  if (const auto it = keywords.find(text); it != keywords.end()) {
    addToken(it->second);
  } else {
    addToken(IDENTIFIER);
  }
}

bool Scanner::isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isAlphaNumeric(char c) { return isAlpha(c) || isDigit(c); }

void Scanner::multilineComment() {
  while (peek() != '*' && peekNext() != '/') {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd()) {
    Lox::error(line, "Unterminated multiline comment");
    return;
  }

  // The closing "*/".
  advance();
  advance();
}
