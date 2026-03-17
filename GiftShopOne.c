#include <stdio.h>

# define FILENAME "InvalidIDs.txt"

int main()
{
    FILE *fp;
    long long start;
    long long end;

    long long sumInvalidIds = 0;

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        printf("File does not exist! %s\n", FILENAME);
        return -1;
    }

    while (fscanf(fp, "%lld-%lld,", &start, &end) != EOF)
    {
        long long mutiplierBase = 10;
        long long startHalf = 1;

        for(int length = 1; length <= 5; length ++)
        {
            long long multiplier = mutiplierBase + 1;
            long long endHalf = mutiplierBase;
            
            for(long long half = startHalf; half < endHalf; half++)
            {
                long long invalidId = half * multiplier;
                
                if (invalidId >= start && invalidId <= end)
                {
                    sumInvalidIds += invalidId;
                }
            }

            startHalf = mutiplierBase;
            mutiplierBase *= 10;
        }        
    }

    fclose(fp);
    fp = NULL;

    printf("Total sum of Invalid IDs is: %lld\n", sumInvalidIds);
    
    return 0;
}