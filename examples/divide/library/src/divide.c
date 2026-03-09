/*
 * Module providing a function "divide".
 */
#include "seatract.h"
#include "divide.h"
#include <math.h>

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
    // Use a relative epsilon for float comparison to handle rounding errors
    // across the full range of integer inputs, including a == 0
    Ensure(fabsf(result * (float)b - (float)a) < 1e-5f * (fabsf((float)a) + 1.0f));

    return result;
}

