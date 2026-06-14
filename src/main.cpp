#include <iostream>
#include <fstream>
#include <sstream>

#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

std::string tokenToString(TokenType type)
{
    switch(type)
    {
        case TokenType::VAR: return "VAR";
        case TokenType::PRINT: return "PRINT";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::ASSIGN: return "ASSIGN";
        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::STAR: return "STAR";
        case TokenType::SLASH: return "SLASH";
        case TokenType::LPAREN: return "LPAREN";
        case TokenType::RPAREN: return "RPAREN";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::END_OF_FILE: return "EOF";
    }

    return "UNKNOWN";
}

std::string opcodeToString(OpCode op)
{
    switch(op)
    {
        case OpCode::PUSH: return "PUSH";
        case OpCode::STORE: return "STORE";
        case OpCode::LOAD: return "LOAD";
        case OpCode::ADD: return "ADD";
        case OpCode::PRINT: return "PRINT";
    }

    return "UNKNOWN";
}

int main()
{
    std::ifstream file("tests/hello.cvm");

    if(!file.is_open())
    {
        std::cout
            << "Failed to open script file\n";

        return 1;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    std::string source = buffer.str();

    Lexer lexer(source);

    auto tokens = lexer.tokenize();

    std::cout << "TOKENS\n\n";

    for(auto token : tokens)
    {
        std::cout
            << tokenToString(token.type)
            << " : "
            << token.value
            << std::endl;
    }

    Parser parser(tokens);

    auto ast = parser.parse();

    std::cout << "\nAST\n\n";

    for(auto node : ast)
    {
        std::cout
            << node.type
            << " -> "
            << node.value
            << std::endl;
    }

    Compiler compiler;

    auto bytecode =
        compiler.compile(ast);

    std::cout
        << "\nBYTECODE\n\n";

    for(auto instruction : bytecode)
    {
        std::cout
            << opcodeToString(
                   instruction.op
               )
            << " "
            << instruction.operand
            << std::endl;
    }

    std::cout
        << "\nOUTPUT\n\n";

    VM vm;

    vm.execute(bytecode);

    return 0;
}