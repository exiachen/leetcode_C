#include <stdio.h>
#include <stdlib.h>

static void floodFill(char **grid, int x, int y, char target, int newValue, int gridRowSize, int gridColSize)
{
    if (x < 0 || x >= gridRowSize || y < 0 || y >= gridColSize)
        return;
    if (grid[x][y] != target)
        return;

    grid[x][y] = newValue;
    floodFill(grid, x, y - 1, target, newValue, gridRowSize, gridColSize);
    floodFill(grid, x, y + 1, target, newValue, gridRowSize, gridColSize);
    floodFill(grid, x - 1, y, target, newValue, gridRowSize, gridColSize);
    floodFill(grid, x + 1, y, target, newValue, gridRowSize, gridColSize);

    return;
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
   int i = 0, j = 0;
   int count = 0;

   for (i = 0; i < gridRowSize; i++)
   {
        for (j = 0; j < gridColSize; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                floodFill(grid, i, j, '1', '2', gridRowSize, gridColSize);
            }
            else
                continue;

        }
   }

   return count;
}

int main(int argc, char const *argv[])
{
    char **grid = NULL;

    grid = (char**)malloc(sizeof(char *) * 1);
    grid[0] = (char*)malloc(sizeof(char) * 2);

    grid[0][0] = '1';
    grid[0][1] = '0';

    //printf("%c\n", grid[0][0]);
    int num = numIslands(grid, 1, 2);

    printf("num = %d\n", num);
    return 0;
}
