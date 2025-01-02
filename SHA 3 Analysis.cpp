#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 1024

void simulateSHA3(int *lanes) {
    int rounds = 0;
    while (1) {
        int allNonZero = 1;
        for (int i = 0; i < BLOCK_SIZE; i++) {
            if (lanes[i] == 0) {
                lanes[i] = rand() % 2;  // Simulate lane update
            }
            if (lanes[i] == 0) {
                allNonZero = 0;
            }
        }
        rounds++;
        if (allNonZero) break;
    }
    printf("All lanes became nonzero after %d rounds.\n", rounds);
}

int main() {
    int lanes[BLOCK_SIZE] = {0};
    srand(time(0));

    simulateSHA3(lanes);

    return 0;
}

