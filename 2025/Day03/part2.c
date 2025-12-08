#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned long highest_batt(char str[]) {

    size_t str_len = strlen(str);
    char batt[12+1];
    strncpy(batt, str + (str_len - 13), 12);
    batt[12] = '\0';

    // Start Batt 1-12 at end of array
    // For Batt 1 take largest number from Batt 1 to left
    // For Batt 2 take largest number from Batt 2 to Batt 1
    // Repeat for entire Battery
    int end = 0; // pointer used to determine stopping point for inner loop, initially set to 0
    for (int x = 0; x < 12; x++) {
        int ptr = 0; // pointer used to track last location of max value
        for (int i = (str_len - (13 - x)); i >= end; i--) {
            if (str[i] >= batt[x]) {
                batt[x] = str[i];
                ptr = i;
            }
        }
        end = ptr + 1; // our current batt[x] ended here, stop next loop at one location to the right
    }

    unsigned long jolts = 0;
    jolts = strtol(batt, NULL, 0);
    return jolts;
}

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    char *line = NULL;
    size_t line_buf_len = 0;
    ssize_t read_size = 0;

    if (fp == NULL) {
        return 1;
    }

    unsigned long jolts = 0;

    while (getline(&line, &line_buf_len, fp) != -1) {
        jolts += highest_batt(line);
    }

    printf("Part 2 answer: %ld\n", jolts);

    free(line);
    assert(feof(fp));
    fclose(fp);

    return 0;
}
