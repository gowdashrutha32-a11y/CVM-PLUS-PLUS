#include "vm.h"

#include <iostream>

void VM::execute(
    const std::vector<Instruction>& bytecode)
{
    for(auto instruction : bytecode)
    {
        switch(instruction.op)
        {
            case OpCode::PUSH:
            {
                stack.push_back(
                    std::stoi(
                        instruction.operand
                    )
                );
                break;
            }

            case OpCode::STORE:
            {
                int value = stack.back();

                stack.pop_back();

                variables[
                    instruction.operand
                ] = value;

                break;
            }

            case OpCode::LOAD:
            {
                stack.push_back(
                    variables[
                        instruction.operand
                    ]
                );

                break;
            }

            case OpCode::ADD:
            {
                int b = stack.back();
                stack.pop_back();

                int a = stack.back();
                stack.pop_back();

                stack.push_back(a + b);

                break;
            }

            case OpCode::PRINT:
            {
                std::cout
                    << stack.back()
                    << std::endl;

                stack.pop_back();

                break;
            }
        }
    }
}