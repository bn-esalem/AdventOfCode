#include <stdio.h>

#define FILENAME "SecretEntrance.txt"
int main()
{
    FILE *fp;
    char direction;
    int distance;
    int position = 50;  // dial starts at 50
    int count = 0;

    // open the file 

    fp = fopen (FILENAME, "r");

    if (fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }

    // read from file until the end and using CLICK method (0x434C49434B)

    while (fscanf(fp, " %c%d", &direction, &distance) != EOF)
    {
        for (int i = 0; i < distance; i++)
        {
            if (direction == 'R')
            {
                position = position + 1; // Move right "we change the pos 1st"

                if (position == 100)
                {  
                    position = 0;        // Wrap back to 0
                }
            } 

            else if (direction == 'L')
            {
                position = position - 1; // Move left

                if (position == -1)    // If we go below 0...
                {
                    position = 99;       // Wrap back to 99
                }
            }

            // 3. Check if the dial points at 0 after THIS click
            if (position == 0)
            {
                count++;
            }
        }
    }
    

    fclose(fp);
    fp = NULL;

    printf("Password is: %d\n", count);


    return 0;
}