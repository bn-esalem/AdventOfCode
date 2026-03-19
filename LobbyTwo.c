#include <stdio.h>
#include <stdlib.h>   // for malloc
#include <ctype.h>   // to use a function to check if char is a number

#define FILENAME "LobbyBatteries.txt"

int main()
{
    
    FILE *fp = fopen(FILENAME, "r");
    char *line = NULL;

    size_t bufferSize = 0;
    long long totalOutputJoltage = 0;

    if(fp == NULL)
    {
        printf("File doesn't exist!\n");
        return -1;
    }

    while(getline(&line, &bufferSize, fp) != -1)
    {
        long long totalDigits = 0;

        for(int i = 0; line[i] != '\0'; i++)
        {
            if(isdigit(line[i]))     // check if digit because sometimes there is ' ' or '/'
            {
                line[totalDigits ++] = line[i]; // to put only digits and then move to next array slot
            }
        }

        line[totalDigits] = '\0';

        if (totalDigits < 12)
        {
            continue;    // not break; because we just want to skip this line not to stop reading from file
        }

        char result [13] = "";
        int currentPos = 0;  // where we standing on the line

        for(int i = 0; i < 12; i++)
        {
            int remainingDigits = 11-i;
            int maxIndex = currentPos;

            for(int j = currentPos; j <= totalDigits - remainingDigits - 1; j++)
            {
                if(line[j] > line[maxIndex])
                {
                    maxIndex = j;
                }
            } 
            
            result[i] = line[maxIndex];
            currentPos = maxIndex + 1;
        }

        result[12] = '\0';

        totalOutputJoltage += atoll(result);

    }

    free(line);
    fclose(fp);
    fp = NULL;

    printf("The total output joltage is: %lld\n", totalOutputJoltage);

    return 0;
}