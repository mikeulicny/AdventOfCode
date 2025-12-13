#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*  Mapping of mask
 *
 *  1  2  3
 *  8  @  4
 *  7  6  5
 *
 */

typedef enum {
    NW = (1 << 0),
    N  = (1 << 1),
    NE = (1 << 2),
    E  = (1 << 3),
    SE = (1 << 4),
    S  = (1 << 5),
    SW = (1 << 6),
    W  = (1 << 7),
} t_mask;

int sum_3x3(int **grid, size_t row, size_t col, t_mask mask) {
    int adj = 0;

    if (mask & NW)
        adj += grid[row-1][col-1];

    if (mask & N)
        adj += grid[row-1][col];

    if (mask & NE)
        adj += grid[row-1][col+1];

    if (mask & E)
        adj += grid[row][col+1];

    if (mask & SE)
        adj += grid[row+1][col+1];

    if (mask & S)
        adj += grid[row+1][col];

    if (mask & SW)
        adj += grid[row+1][col-1];
        
    if (mask & W)
        adj += grid[row][col-1];

    return adj;
}

int main(void) {
    
    FILE *fp;
    fp = fopen("input.txt", "r");

    assert(fp != NULL);

    char *line = NULL;
    size_t line_buffer = 0;

    int **grid= NULL;
    int total = 0;

    int rows = 0;
    int cols = 0;

    // Generate grid from file
    while (getline(&line, &line_buffer, fp) != -1) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') len--;
        
        if (rows == 0) cols = len;

        grid = realloc(grid, (rows + 1) * sizeof(int*));
        grid[rows] = malloc(cols * sizeof(int));
        //grid[rows][len] = '\0';

        for (int c = 0; c < cols; c++) {
            grid[rows][c] = line[c] == '@' ? 1 : 0;
        }

        rows++;
    }

    free(line);
    fclose(fp);

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            if (grid[r][c]) {
                t_mask flags = 0b11111111;

                if (c == 0)
                    flags &= ~NW & ~W & ~SW;

                if (c == (cols - 1))
                    flags &= ~NE & ~E & ~SE;

                if (r == 0)
                    flags &= ~NW & ~N & ~NE;

                if (r == (rows - 1))
                    flags &= ~SW & ~S & ~SE;

                if (sum_3x3(grid, r, c, flags) < 4) {
                    total++;
                }
            }
        }
    }

    printf("Part 1 answer: %d\n", total);

    return 0;
}
