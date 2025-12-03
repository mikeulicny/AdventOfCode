#include <stdio.h>
#include <stdlib.h>

#define LEN 16

int mod(int x, int y) {
    int r = x % y;
    return r < 0 ? r + y : r;
}

int main(void) {

    FILE* fp;
    fp = fopen("input.txt", "r");

    char line[LEN];

    if (fp == NULL) {
        return 1;
    }

    int dial = 50;
    int password = 0;

    // Part 1
    while (fgets(line, LEN, fp)) {
        char direction = line[0];
        int count = atoi(&line[1]);

        if (line[0] == 'L') {
            dial -= count;
        }
        else if (line[0] == 'R') {
            dial += count;
        }

        if (dial % 100 == 0)
            password += 1;
    }

    printf("Part 1 - Password: %d\n", password);

    // Reset
    fseek(fp, 0, SEEK_SET);
    dial = 50;
    password = 0;
    int prev = 0;

    // Part 2
    while (fgets(line, LEN, fp)) {
        char direction = line[0];
        int count = atoi(&line[1]);

        for (int i = 0; i < count; i++) {
            if (line[0] == 'L') {
                dial -= 1;
            }
            else if (line[0] == 'R') {
                dial += 1;
            }

            if (dial % 100 == 0)
                password += 1;
        }
    }

    printf("Part 2 - Password: %d\n", password);

    fclose(fp);

    return 0;
}
