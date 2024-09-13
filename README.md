# Reverse Polish Notation (RPN) Calculator

This project is a **Reverse Polish Notation Calculator** created as part of the Programming II group project for the BICT program at the University of Colombo (UOC).

## Features
- Supports basic arithmetic operations: Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`).
- Handles input/output through a stack-based evaluation of postfix notation expressions.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/s3h4n/Reverse-Polish-Notation-Calculator.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Reverse-Polish-Notation-Calculator
   ```
3. Compile the source code:
   ```bash
   gcc -o rpn_calculator main.c stack.c arithmetic.c io_handler.c parser.c
   ```

## Usage

Run the program:
```bash
./rpn_calculator
```
Input a valid RPN expression to get the result. Example:
```bash
Input: 3 4 + 2 *
Output: 14
```

## Files
- `main.c`: Entry point of the program.
- `stack.c`: Implements stack operations.
- `arithmetic.c`: Handles arithmetic computations.
- `io_handler.c`: Deals with input/output operations.
- `parser.c`: Parses the RPN expression.

## Contributors

<a href="https://github.com/s3h4n/Reverse-Polish-Notation-Calculator/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=s3h4n/Reverse-Polish-Notation-Calculator" />
</a>
