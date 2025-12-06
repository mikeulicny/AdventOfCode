#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

// Return 0 if no matches
// Return 1 if all match
int compare(char *str, size_t str_len, size_t tkn_len) {
    for (int i = 0; i < str_len; i += tkn_len) {
        if (strncmp(str, &str[i], tkn_len))
            return 0;
    }

    return 1;
}

int main(void) {

    char str[16];

    unsigned long answer;
    unsigned long first, second;

    while (scanf("%ld-%ld,", &first, &second) != EOF) {
        for (unsigned long i = first; i <= second; i++) {
            sprintf(str, "%ld", i);
            size_t str_len = strlen(str);

            if (str_len == 1)
                continue;

            for (size_t tkn_len = 1; tkn_len <= str_len / 2; tkn_len++) {
                if (compare(str, str_len, tkn_len)) {
                    answer += i;
                    break;
                }
            }
        }
    }

    printf("Part 2 answer: %ld\n", answer);
    return 0;
}
