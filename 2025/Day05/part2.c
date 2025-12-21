#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <sys/param.h>

typedef struct {
    unsigned long start;
    unsigned long end;
} Range;

int compare_range(const void *v1, const void *v2) {
    Range *r1 = (Range*)v1;
    Range *r2 = (Range*)v2;
    if (r1->start < r2->start) {
        return -1;
    } else if (r1->start > r2->start) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    char *line = NULL;
    size_t line_buffer = 0;

    unsigned long answer = 0;
    unsigned long first, second;

    size_t len = 0;
    Range *ranges = NULL;

    while (getline(&line, &line_buffer, fp) != EOF) {

        if (strcmp(line, "\n") == 0) break;

        sscanf(line, "%ld-%ld", &first, &second);
        len++;
        ranges = realloc(ranges, len * sizeof(Range));
        ranges[len-1] = (Range){.start = first, .end = second};
    }
    
    qsort(ranges, len, sizeof ranges[0], compare_range);

    size_t i = 1;
    while (i < len) {
        if (ranges[i].start <= ranges[i-1].end) {
            ranges[i-1].end = MAX(ranges[i].end, ranges[i-1].end);
            for (size_t j = i; j < len-1; j++) {
                ranges[j] = ranges[j+1];
            }
            len--;
            ranges = realloc(ranges, len * sizeof(Range));
        } else {
            i++;
        }
    }

    for (size_t x = 0; x < len; x++) {
        answer = answer + (ranges[x].end - ranges[x].start) + 1;
    }

    printf("Part 2 answer: %ld\n", answer);

    free(line);
    fclose(fp);

    return 0;
}
