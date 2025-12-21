#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

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

    while (getline(&line, &line_buffer, fp) != EOF) {

        if (strcmp(line, "\n") == 0) break;

        sscanf(line, "%ld-%ld", &first, &second);
        len++;
        ranges = realloc(ranges, len * sizeof(Range));
        ranges[len-1] = (Range){ .start = first, .end = second };
    }

    while (getline(&line, &line_buffer, fp) != EOF) {
        unsigned long number;
        sscanf(line, "%ld", &number);

        for (int i = 0; i < len; i++) {
            if ((number >= ranges[i].start) && (number <= ranges[i].end)) {
                answer++;
                break;
            }
        }
    }

    printf("Part 1 answer: %ld\n", answer);

    free(line);
    fclose(fp);

    return 0;
}
