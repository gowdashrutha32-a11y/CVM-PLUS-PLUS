#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "compiler.h"

class VM
{
private:

    std::vector<int> stack;

    std::unordered_map<
        std::string,
        int
    > variables;

public:

    void execute(
        const std::vector<Instruction>& bytecode
    );
};