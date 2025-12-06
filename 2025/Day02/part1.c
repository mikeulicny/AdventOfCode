#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

int main(void) {

    char str[16];

    unsigned long answer;
    unsigned long first, second;

    // Part 1
    while (scanf("%ld-%ld,", &first, &second) != EOF) {
        for (unsigned long i = first; i <= second; i++) {
            sprintf(str, "%ld", i);
            size_t len = strlen(str);

            if (len % 2 != 0)
                continue;

            if (!strncmp(str, &str[len/2], len/2)) {
                answer += i;
            }
        }
    }

    printf("Part 1 answer: %ld\n", answer);

    return 0;
}
