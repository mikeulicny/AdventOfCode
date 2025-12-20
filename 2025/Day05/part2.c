#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned long start;
    unsigned long end;
} Range;

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    char *line = NULL;
    size_t line_buffer = 0;

    unsigned long answer = 0;
    size_t len = 0;
    Range *ranges = NULL;
    unsigned long first, second;


    struct Node* btree = NULL;
    int test = 1;

    while (getline(&line, &line_buffer, fp) != EOF) {

        if (strcmp(line, "\n") == 0) break;

        sscanf(line, "%ld-%ld", &first, &second);
        len++;
        ranges = realloc(ranges, len * sizeof(Range));
        ranges[len-1] = (Range){ .start = first, .end = second };
    }
    
    for (size_t i = 0; i < len; i++) {

    }

    printf("Part 2 answer: %ld\n", answer);

    return 0;
}
