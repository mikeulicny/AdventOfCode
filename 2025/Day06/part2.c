#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned long sum(unsigned long arry[], size_t len) {
    unsigned long long s = 0;
    for (size_t i = 0; i < len; i++) {
        s += arry[i];
    }
    return s;
}

unsigned long mult(unsigned long arry[], size_t len) {
    unsigned long long m = 1;
    for (size_t i = 0; i < len; i++) {
        m = m * arry[i];
    }
    return m;
}

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    unsigned long long answer = 0;

    char *line1 = NULL;
    char *line2 = NULL;
    char *line3 = NULL;
    char *line4 = NULL;
    char *line5 = NULL;
    size_t line_buffer = 0;

    getline(&line1, &line_buffer, fp);
    getline(&line2, &line_buffer, fp);
    getline(&line3, &line_buffer, fp);
    getline(&line4, &line_buffer, fp);
    getline(&line5, &line_buffer, fp);

    size_t len = strlen(line1);

    unsigned long nums[8];
    size_t num_len = 0;

    for (size_t i = len-1; i > 0; i--) {
        char str[8];
        snprintf(str, sizeof(str), "%c%c%c%c", line1[i-1], line2[i-1], line3[i-1], line4[i-1]);

        if (strcmp(str, "    ") == 0) {
            continue;
        }
        //printf("%s ", str);
        sscanf(str, "%ld", &nums[num_len]);
        num_len++;
        //printf("%ld\n", nums[num_len-1]);

        switch (line5[i-1]) {
            case '+':
                answer += sum(nums, num_len);
                num_len = 0;
                break;
            case '*':
                answer += mult(nums, num_len);
                num_len = 0;
                break;
        }

    }

    printf("Part 2 answer: %lld\n", answer);

    fclose(fp);
}
