#include <stdio.h>

# define FILENAME "InvalidIDs.txt"

int main()
{
    long long start;
    long long end;
    long long sumInvalidIds = 0;

    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return -1;
    }

    while (fscanf(fp, "%lld-%lld,", &start, &end) != EOF)
    {
        long long minCheck = 1;
        long long maxCheck = 10;
        
        long long multiplier = 10;

        for (int i = 1; i <= 9; i++)
        {
            for(long long num = minCheck; num < maxCheck; num ++)
            {
                long long InvalidId = num;

                for (int numRepeats = 2; numRepeats <= 15; numRepeats ++)
                {
                    InvalidId = (InvalidId * multiplier) + num;

                    if (InvalidId > end)
                    {
                        break;
                    }

                    else if (InvalidId >= start)
                    {
                        sumInvalidIds += InvalidId;
                    }
                }
            }

            minCheck = maxCheck;
            maxCheck *= 10;
            multiplier *= 10;
        }

    }

    fclose(fp);
    fp = NULL;

    printf("Total of Invalid Ids is: %lld\n", sumInvalidIds);

    return 0;
}