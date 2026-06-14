#pragma once

#include <vector>
#include <string>

#include "lexer.h"

struct ASTNode
{
    std::string type;
    std::string value;
};

class Parser
{
private:

    std::vector<Token> tokens;
    int current;

public:

    Parser(const std::vector<Token>& tokenList);

    std::vector<ASTNode> parse();
};