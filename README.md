# Simple Calculator

A lightweight, interactive command-line calculator written in C (`C11`). It reads arithmetic expressions from standard input in a loop and evaluates binary operations on floating-point numbers.

## Files

- `calculator.c` — Source code containing the calculation logic and interactive input loop.
- `Makefile` — Build configuration using `gcc` and linking the math library (`-lm`).

## Supported Operators

| Operator | Operation | Notes |
| --- | --- | --- |
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | Reports an error on division by zero |
| `%` | Modulo | Uses `fmod(a, b)` for floating-point remainder; reports an error on modulo by zero |

## Building

Requirements: `gcc` and `make`.

Build the `calculator` binary:

```bash
make
```

This compiles `calculator.c` with `-Wall -Wextra -Werror -std=c11 -O2` and links `-lm`.

To remove the compiled binary:

```bash
make clean
```

## Usage

Run the program:

```bash
./calculator
```

Enter expressions in the format `<number> <operator> <number>` at the `> ` prompt. Results are printed with up to 10 significant digits (`%.10g`).

### Commands & Input Rules

- **Empty lines** (or lines with only spaces/tabs) are ignored.
- **Quit** by entering a line starting with `q` or `Q` (ignoring leading spaces/tabs), or by sending EOF (`Ctrl+D`).
- Input lines are read into a 256-byte buffer (`char line[256]`) and parsed with `sscanf(p, "%lf %c %lf %c", ...)`. Trailing non-whitespace characters after the second number are rejected.

### Example Session

```text
Simple Calculator (operators: + - * / %)
Enter an expression like: 12.5 + 3.5 (or 'q' to quit)
> 12.5 + 3.5
= 16
> 10 / 4
= 2.5
> 7.5 % 2
= 1.5
> 5 / 0
Error: Division by zero.
> q
```

## Code Overview

- `calculate(double a, char op, double b, double *result)` (`calculator.c`): Evaluates the requested operation, guards against division/modulo by zero and unsupported operators, writes the result to `*result`, and returns `true` on success or `false` on error.
- `main(void)` (`calculator.c`): Runs the interactive prompt loop, trims leading spaces/tabs to handle blank lines and quit commands, parses the expression, and prints either the result or an error message to `stderr`.
