#include "parser.h"

Parser::Parser(const std::vector<Token>& tokenList)
{
    tokens = tokenList;
    current = 0;
}

std::vector<ASTNode> Parser::parse()
{
    std::vector<ASTNode> ast;

    while(current < tokens.size())
    {
        Token token = tokens[current];

        // var x = 10;
        if(token.type == TokenType::VAR)
        {
            std::string variableName =
                tokens[current + 1].value;

            std::string variableValue =
                tokens[current + 3].value;

            ast.push_back(
            {
                "VAR_DECL",
                variableName + "=" + variableValue
            });

            current += 5;
            continue;
        }

        // x = 50;
        if(token.type == TokenType::IDENTIFIER &&
           tokens[current + 1].type == TokenType::ASSIGN)
        {
            std::string variableName =
                tokens[current].value;

            std::string variableValue =
                tokens[current + 2].value;

            ast.push_back(
            {
                "ASSIGN",
                variableName + "=" + variableValue
            });

            current += 4;
            continue;
        }

        // print(...)
        if(token.type == TokenType::PRINT)
        {
            std::string expression;

            int i = current + 2;

            while(tokens[i].type != TokenType::RPAREN)
            {
                expression += tokens[i].value;
                i++;
            }

            ast.push_back(
            {
                "PRINT",
                expression
            });

            current = i + 2;
            continue;
        }

        current++;
    }

    return ast;
}