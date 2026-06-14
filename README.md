# CVM++

A custom scripting language and stack-based virtual machine implemented in C++.

CVM++ demonstrates the complete compilation pipeline:

Source Code
→ Lexer
→ Parser
→ Abstract Syntax Tree (AST)
→ Bytecode Compiler
→ Virtual Machine
→ Program Output

---

# Features

## Lexer

Converts source code into tokens.

Example:

```c
var x = 10;
```

Tokens:

```txt
VAR
IDENTIFIER
ASSIGN
NUMBER
SEMICOLON
```

---

## Parser

Converts tokens into an Abstract Syntax Tree.

Example AST:

```txt
VAR_DECL -> x=10
PRINT -> x
```

---

## Bytecode Compiler

Transforms AST nodes into bytecode instructions.

Example:

```txt
PUSH 10
STORE x
LOAD x
PRINT
```

---

## Virtual Machine

Executes bytecode using a stack-based architecture.

Supported instructions:

```txt
PUSH
STORE
LOAD
ADD
PRINT
```

---

# Supported Language Features

## Variable Declaration

```c
var x = 10;
var y = 20;
```

## Assignment

```c
x = 50;
```

## Print Statements

```c
print(x);
```

## Arithmetic Addition

```c
print(x + y);
```

---

# Example Program

```c
var x = 10;
var y = 20;

print(x);
print(y);

print(x + y);

x = 50;

print(x);
```

---

# Example Output

```txt
10
20
30
50
```

---

# Project Structure

```txt
CVM++
│
├── src
│   ├── lexer.h
│   ├── lexer.cpp
│   │
│   ├── parser.h
│   ├── parser.cpp
│   │
│   ├── compiler.h
│   ├── compiler.cpp
│   │
│   ├── vm.h
│   ├── vm.cpp
│   │
│   └── main.cpp
│
├── tests
│   ├── hello.cvm
│   └── arithmetic.cvm
│
├── README.md
├── .gitignore
└── .gitattributes
```

---

# Compilation Pipeline

## 1. Lexical Analysis

Source Code:

```c
var x = 10;
```

↓

Tokens:

```txt
VAR IDENTIFIER ASSIGN NUMBER
```

---

## 2. Parsing

Tokens are converted into an AST.

```txt
VAR_DECL -> x=10
```

---

## 3. Compilation

AST nodes are converted into bytecode.

```txt
PUSH 10
STORE x
```

---

## 4. Execution

The Virtual Machine executes bytecode instructions.

Memory State:

```txt
x = 10
```

Output:

```txt
10
```

---

# Build

Compile using g++:

```bash
g++ src/main.cpp src/lexer.cpp src/parser.cpp src/compiler.cpp src/vm.cpp -o cvm
```

---

# Run

Windows:

```bash
.\cvm.exe
```

Linux:

```bash
./cvm
```

---

# Technologies Used

- C++
- Object-Oriented Programming
- Recursive Parsing
- Bytecode Compilation
- Stack-Based Virtual Machine
- Custom Language Design

---

# Future Improvements

Planned features:

- Subtraction
- Multiplication
- Division
- Conditional Statements
- While Loops
- User Input
- Functions
- Strings
- Arrays
- Error Handling
- REPL Mode

---

# Author

Shruthasen Gowda

Electronics and Electrical Engineering

Indian Institute of Technology Guwahati

---

# License

Open source for educational and academic purposes.