# CVM++

Custom Virtual Machine and Compiler written in C++.

## Features

- Lexical Analysis (Tokenizer)
- Recursive Parsing
- Abstract Syntax Tree (AST)
- Bytecode Generation
- Stack-Based Virtual Machine
- Variable Declaration
- Variable Assignment
- Arithmetic Addition
- Print Statements

## Project Structure

```txt
src/
 ├── lexer.cpp
 ├── lexer.h
 ├── parser.cpp
 ├── parser.h
 ├── compiler.cpp
 ├── compiler.h
 ├── vm.cpp
 ├── vm.h
 └── main.cpp

tests/
 └── hello.cvm
```

## Example Script

```c
var x = 10;
var y = 20;

print(x+y);
```

## Build

```bash
g++ src/main.cpp src/lexer.cpp src/parser.cpp src/compiler.cpp src/vm.cpp -o cvm
```

## Run

```bash
./cvm
```

## Sample Output

```txt
30
```

