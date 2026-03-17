#include <stdio.h>

#define FILENAME "SecretEntrance.txt"
int main()
{
    FILE *fp;
    char direction;
    int distance;
    int position = 50;
    int count = 0;

    // open the file 

    fp = fopen (FILENAME, "r");

    if (fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }

    // read from file until the end

    while (fscanf(fp, " %c%d", &direction, &distance) != EOF)
    {
        if(direction =='R')
        {
            position = (position + distance) % 100;
        }
        else if (direction == 'L')
        {
            position = (position - distance) % 100;

            if(position < 0)
            {
                position += 100;
            }
        }

        if (position == 0)
        {
            count ++;
        }
    }

    fclose(fp);
    fp = NULL;

    printf("Password is: %d\n", count);


    return 0;
}