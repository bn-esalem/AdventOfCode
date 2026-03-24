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
        long long baseTen = 10;
        long long minPattern = 1;

        for(int length = 1; length <= 5; length ++)
        {
            long long repeater = baseTen + 1;  // is like a stamp
            long long maxPattern = baseTen;
            
            for(long long pattern = minPattern; pattern < maxPattern; pattern++)
            {
                long long invalidId = pattern * repeater;
                
                if (invalidId >= start && invalidId <= end)
                {
                    sumInvalidIds += invalidId;
                }
            }

            minPattern = baseTen;
            baseTen *= 10;
        }        
    }

    fclose(fp);
    fp = NULL;

    printf("Total sum of Invalid IDs is: %lld\n", sumInvalidIds);
    
    return 0;
}