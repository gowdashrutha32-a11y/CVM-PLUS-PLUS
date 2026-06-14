#pragma once

#include <vector>
#include <string>

#include "parser.h"

enum class OpCode
{
    PUSH,
    STORE,
    LOAD,
    ADD,
    PRINT
};

struct Instruction
{
    OpCode op;
    std::string operand;
};

class Compiler
{
public:
    std::vector<Instruction>
    compile(const std::vector<ASTNode>& ast);
};