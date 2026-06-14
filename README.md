# CVM++

CVM++ is a custom scripting language and stack-based virtual machine implemented in C++.

## Features

- Lexical Analysis (Lexer)
- Recursive Descent Parser
- Abstract Syntax Tree (AST)
- Bytecode Compiler
- Stack-Based Virtual Machine
- Variable Declaration
- Variable Assignment
- Arithmetic Operations
- Print Statements

## Project Structure

```
src/
├── lexer.h
├── lexer.cpp
├── parser.h
├── parser.cpp
├── compiler.h
├── compiler.cpp
├── vm.h
├── vm.cpp
└── main.cpp

tests/
└── hello.cvm
```

## Example Program

```c
var x = 10;
var y = 20;

print(x);
print(y);
print(x + y);

x = 50;

print(x);
```

## Execution Pipeline

Source Code

↓

Lexer

↓

Tokens

↓

Parser

↓

AST

↓

Compiler

↓

Bytecode

↓

Virtual Machine

↓

Output

## Sample Output

```
10
20
30
50
```

## Build

```bash
g++ src/main.cpp src/lexer.cpp src/parser.cpp src/compiler.cpp src/vm.cpp -o cvm
```

## Run

```bash
./cvm
```