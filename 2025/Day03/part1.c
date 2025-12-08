#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void highest_pair(char batt[], char str[]) {
    for (int i = 0; str[i+1] != '\n' ; i++) {
        // as we iterate through
        // if we encounter a number larger than both batt1 and batt2
        //   set batt1 to that number
        //   set batt2 to the next number
        // if the next number is larger than batt2
        //   set batt2 to the next number
        // otherwise
        //   continue
        if ( (&str[i] > &batt[0]) && (&str[i] > &batt[1]) ) {
            batt[0] = str[i];
            batt[1] = str[i+1];
        }

        if (&str[i+1] > &batt[1]) {
            batt[1] = str[i+1];
        }
    }
}

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    char *line = NULL;
    size_t line_buf_len = 0;
    ssize_t read_size = 0;

    if (fp == NULL) {
        return 1;
    }

    unsigned int jolts = 0;

    while (getline(&line, &line_buf_len, fp) != -1) {
        char batt[] = "00";
        highest_pair(batt, line);
        jolts = jolts + strtol(batt, NULL, 0);
    }

    printf("Part 1 answer: %d\n", jolts);

    free(line);
    assert(feof(fp));
    fclose(fp);

    return 0;
}
