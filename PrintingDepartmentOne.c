#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "PaperRolls.txt"

int main ()
{
    char grid [500][500];
    int rows = 0;
    int totalAccessedRolls = 0;

    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        printf("File doesn't exist!\n");
        return -1;
    }

    while (fscanf(fp, "%s", grid[rows]) != EOF)
    {
        rows ++;
    }

    fclose(fp);
    fp = NULL;

    int cols = strlen(grid[0]);

    for(int r = 0; r < rows; r ++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(grid [r][c] == '@')
            {
                int count = 0;

                // we check 8 neighbours top L&R, Bottom L&R
                // dr delta row, dc delta column

                for(int dr = -1; dr <= 1; dr++)  // check above (-1), same (0), below (1)
                {
                    for(int dc = -1; dc <= 1; dc++) // check left(-1), Middle(0), right(1)
                    {
                        if(dr == 0 && dc == 0)
                        {
                            continue;
                        }

                        int nr = r + dr; // neighbour Row
                        int nc = c + dc; // neighbour Column

                       // boundary Check

                        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                        {
                            if(grid[nr][nc] == '@') 
                            {
                                count ++;
                            }
                        }
                    }
                }  
                
                if(count < 4)
                {
                    totalAccessedRolls ++;
                }
            }
        }
    }

    printf("Total accessed rolls: %d\n", totalAccessedRolls);
    return 0;
}