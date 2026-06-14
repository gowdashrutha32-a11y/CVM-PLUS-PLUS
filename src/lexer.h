#pragma once

#include <string>
#include <vector>

enum class TokenType
{
    VAR,
    PRINT,

    IDENTIFIER,
    NUMBER,

    ASSIGN,

    PLUS,
    MINUS,
    STAR,
    SLASH,

    LPAREN,
    RPAREN,

    SEMICOLON,

    END_OF_FILE
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
private:
    std::string source;
    int current;

public:

    Lexer(const std::string& src);

    std::vector<Token> tokenize();
};