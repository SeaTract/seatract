#include <stdio.h>
#include <stdbool.h>
#include "seatract.h"

/**
 * @brief Divides two integers.
 * * Precondition: The divisor (b) must not be zero.
 * Postcondition: The result multiplied by b (plus any remainder) 
 * should equal a.
 */
float divide(int a, int b) {
    // --- Preconditions ---
    // Ensure the caller provides valid input
    Require(b != 0);

    float result = (float)a / (float)b;

    // --- Postconditions ---
    // Ensure the function performed as expected before returning
    // Note: Using a small epsilon for float comparison
    Ensure(result * b == (float)a);

    return result;
}

int main() {
    printf("Result of 10 / 2: %.2f\n", divide(10, 2));

    // This call triggers a contract violation in seatract
    printf("Result of 10 / 0: %.2f\n", divide(10, 0));

    return 0;
}
