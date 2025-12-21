#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    char *line = NULL;
    size_t line_buffer = 0;

    unsigned long answer = 0;

    unsigned long *nums1 = NULL;
    unsigned long *nums2 = NULL;
    unsigned long *nums3 = NULL;
    unsigned long *nums4 = NULL;

    size_t len = 0;
    unsigned long num;

    getline(&line, &line_buffer, fp);

    char *tok = strtok(line, " ");
    while (tok != NULL) {
        if(sscanf(tok, "%ld", &num) > 0) {
            len++;
            nums1 = realloc(nums1, len * sizeof(unsigned long));
            nums1[len-1] = num;
        }
        tok = strtok(NULL, " ");
    }

    nums2 = realloc(nums2, len * sizeof(unsigned long));
    nums3 = realloc(nums3, len * sizeof(unsigned long));
    nums4 = realloc(nums4, len * sizeof(unsigned long));

    size_t i = 0;
    getline(&line, &line_buffer, fp);

    tok = strtok(line, " ");
    while (tok != NULL) {
        if(sscanf(tok, "%ld", &num) > 0) {
            nums2[i] = num;
            i++;
        }
        tok = strtok(NULL, " ");
    }

    i = 0;
    getline(&line, &line_buffer, fp);

    tok = strtok(line, " ");
    while (tok != NULL) {
        if(sscanf(tok, "%ld", &num) > 0) {
            nums3[i] = num;
            i++;
        }
        tok = strtok(NULL, " ");
    }

    i = 0;
    getline(&line, &line_buffer, fp);

    tok = strtok(line, " ");
    while (tok != NULL) {
        if(sscanf(tok, "%ld", &num) > 0) {
            nums4[i] = num;
            i++;
        }
        tok = strtok(NULL, " ");
    }

    char op;
    i = 0;
    getline(&line, &line_buffer, fp);

    tok = strtok(line, " ");
    while (tok != NULL) {
        if(sscanf(tok, "%c", &op) > 0) {
            switch (op) {
                case '*':
                    answer += (nums1[i] * nums2[i] * nums3[i] * nums4[i]);
                    break;
                case '+':
                    answer += (nums1[i] + nums2[i] + nums3[i] + nums4[i]);
                    break;
            }
        }
        tok = strtok(NULL, " ");
        i++;
    }

    printf("Part 1 answer: %ld\n", answer);

    return 0;
}
