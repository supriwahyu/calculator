#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool calculate(double a, char op, double b, double *result) {
    switch (op) {
        case '+':
            *result = a + b;
            return true;
        case '-':
            *result = a - b;
            return true;
        case '*':
            *result = a * b;
            return true;
        case '/':
            if (b == 0.0) {
                fprintf(stderr, "Error: Division by zero.\n");
                return false;
            }
            *result = a / b;
            return true;
        case '%':
            if (b == 0.0) {
                fprintf(stderr, "Error: Modulo by zero.\n");
                return false;
            }
            *result = fmod(a, b);
            return true;
        default:
            fprintf(stderr, "Error: Unsupported operator '%c'. Use +, -, *, /, or %%.\n", op);
            return false;
    }
}

int main(void) {
    char line[256];

    printf("Simple Calculator (operators: + - * / %%)\n");
    printf("Enter an expression like: 12.5 + 3.5 (or 'q' to quit)\n");

    while (true) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Trim leading whitespace to check for quit command or empty line.
        char *p = line;
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        if (*p == '\n' || *p == '\0') {
            continue;
        }
        if (*p == 'q' || *p == 'Q') {
            break;
        }

        double a = 0.0;
        double b = 0.0;
        char op = '\0';
        char extra = '\0';

        if (sscanf(p, "%lf %c %lf %c", &a, &op, &b, &extra) != 3) {
            fprintf(stderr, "Error: Invalid input. Format: <number> <operator> <number>\n");
            continue;
        }

        double result = 0.0;
        if (calculate(a, op, b, &result)) {
            printf("= %.10g\n", result);
        }
    }

    return 0;
}
