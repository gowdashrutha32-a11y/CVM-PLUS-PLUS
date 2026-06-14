    #include "lexer.h"

#include <cctype>

Lexer::Lexer(const std::string& src)
{
    source = src;
    current = 0;
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while(current < source.length())
    {
        char c = source[current];

        if(std::isspace(c))
        {
            current++;
            continue;
        }

        if(std::isalpha(c))
        {
            std::string word;

            while(current < source.length() &&
                  (std::isalnum(source[current]) ||
                   source[current] == '_'))
            {
                word += source[current];
                current++;
            }

            if(word == "var")
            {
                tokens.push_back({TokenType::VAR, word});
            }
            else if(word == "print")
            {
                tokens.push_back({TokenType::PRINT, word});
            }
            else
            {
                tokens.push_back({TokenType::IDENTIFIER, word});
            }

            continue;
        }

        if(std::isdigit(c))
        {
            std::string number;

            while(current < source.length() &&
                  std::isdigit(source[current]))
            {
                number += source[current];
                current++;
            }

            tokens.push_back(
            {
                TokenType::NUMBER,
                number
            });

            continue;
        }

        switch(c)
        {
            case '=':
                tokens.push_back({TokenType::ASSIGN,"="});
                break;

            case '+':
                tokens.push_back({TokenType::PLUS,"+"});
                break;

            case '-':
                tokens.push_back({TokenType::MINUS,"-"});
                break;

            case '*':
                tokens.push_back({TokenType::STAR,"*"});
                break;

            case '/':
                tokens.push_back({TokenType::SLASH,"/"});
                break;

            case '(':
                tokens.push_back({TokenType::LPAREN,"("});
                break;

            case ')':
                tokens.push_back({TokenType::RPAREN,")"});
                break;

            case ';':
                tokens.push_back({TokenType::SEMICOLON,";"});
                break;
        }

        current++;
    }

    tokens.push_back(
    {
        TokenType::END_OF_FILE,
        "EOF"
    });

    return tokens;
}