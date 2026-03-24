#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILENAME "PaperRolls.txt"

int main()
{
    char grid [500][500];
    int rows = 0;
    int totalRemoved = 0;

    FILE *fp = fopen(FILENAME, "r");

    bool keepSimulating;

    if (fp == NULL)
    {
        printf("File doesn't exist!\n");
    }

    while(fscanf(fp, "%s", grid[rows]) != EOF)
    {
        rows ++;
    }

    fclose(fp);
    fp = NULL;

    int cols = strlen(grid[0]);

    do
    {
        keepSimulating = false;

        for(int r = 0; r <= rows; r++)
        {
            for(int c = 0; c <= cols; c++)
            {
                if(grid[r][c] == '@')
                {
                    int neighbours = 0;
                    
                    for(int dr = -1; dr <= 1; dr++)
                    {
                        for (int dc = -1; dc <= 1; dc++)
                        {
                            int nr = r + dr;
                            int nc = c + dc;

                            if(dr == 0 && dc == 0)
                            {
                                continue;
                            }

                            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                            {
                                if(grid[nr][nc] == '@')
                                {
                                    neighbours ++;
                                }
                            }
                        }
                    }

                    if(neighbours < 4)
                    {
                        grid[r][c] = 'x';
                        keepSimulating = true;
                    }
                }
            }
        }

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(grid[r][c] == 'x')
                {
                    grid[r][c] = '.';
                    totalRemoved ++;
                }
            }
        }

    } while (keepSimulating == true);
    

    printf("Total accessed rolls: %d\n", totalRemoved);
    
    return 0;
}