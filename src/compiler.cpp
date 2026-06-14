#include "compiler.h"

std::vector<Instruction>
Compiler::compile(const std::vector<ASTNode>& ast)
{
    std::vector<Instruction> bytecode;

    for(auto node : ast)
    {
        if(node.type == "VAR_DECL")
        {
            size_t pos = node.value.find('=');

            std::string var =
                node.value.substr(0,pos);

            std::string value =
                node.value.substr(pos+1);

            bytecode.push_back(
            {
                OpCode::PUSH,
                value
            });

            bytecode.push_back(
            {
                OpCode::STORE,
                var
            });
        }

        else if(node.type == "ASSIGN")
        {
            size_t pos = node.value.find('=');

            std::string var =
                node.value.substr(0,pos);

            std::string value =
                node.value.substr(pos+1);

            bytecode.push_back(
            {
                OpCode::PUSH,
                value
            });

            bytecode.push_back(
            {
                OpCode::STORE,
                var
            });
        }

        else if(node.type == "PRINT")
        {
            if(node.value.find('+')
               != std::string::npos)
            {
                size_t pos =
                node.value.find('+');

                std::string left =
                node.value.substr(0,pos);

                std::string right =
                node.value.substr(pos+1);

                bytecode.push_back(
                {
                    OpCode::LOAD,
                    left
                });

                bytecode.push_back(
                {
                    OpCode::LOAD,
                    right
                });

                bytecode.push_back(
                {
                    OpCode::ADD,
                    ""
                });

                bytecode.push_back(
                {
                    OpCode::PRINT,
                    ""
                });
            }
            else
            {
                bytecode.push_back(
                {
                    OpCode::LOAD,
                    node.value
                });

                bytecode.push_back(
                {
                    OpCode::PRINT,
                    ""
                });
            }
        }
    }

    return bytecode;
}