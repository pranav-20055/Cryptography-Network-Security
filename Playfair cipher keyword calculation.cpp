#include <stdio.h>
#include <math.h>

#define TOTAL_LETTERS 25

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    // Part (a): Number of unique arrangements (ignoring duplicates)
    unsigned long long total_keys = factorial(TOTAL_LETTERS);
    double approx_power_of_2 = log2((double)total_keys);

    printf("Total number of possible keys (ignoring identical encryption results): %llu\n", total_keys);
    printf("Approximation as a power of 2: 2^%.2f\n", approx_power_of_2);

    // Part (b): Considering effectively unique keys
    // Assuming a 20% reduction due to duplicates (this is an approximation)
    unsigned long long unique_keys = (unsigned long long)(total_keys * 0.8);
    double unique_power_of_2 = log2((double)unique_keys);

    printf("Effectively unique keys: %llu\n", unique_keys);
    printf("Approximation as a power of 2: 2^%.2f\n", unique_power_of_2);

    return 0;
}

