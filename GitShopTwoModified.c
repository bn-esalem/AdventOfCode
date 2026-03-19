#include <stdio.h>
#include <stdbool.h>

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
         // 1. INCREASE SIZE to 1000 to be safe
        long long found[100]; 
        int foundCount = 0;

        for (long long pattern = 1; pattern <= 99999; pattern++) 
        {
            long long range = 10;
            
            while (range <= pattern) range *= 10;

            long long invalidId = pattern;

            while (true) 
            {
                invalidId = (invalidId * range) + pattern;

                if (invalidId > end)
                {
                    break;
                }

                else if (invalidId>= start) 
                {
                    int alreadyCounted = 0;   // 2. CHECK FOR DUPLICATES
                    
                    for (int i = 0; i < foundCount; i++)
                    {
                        if (found[i] == invalidId)
                        {
                            alreadyCounted = 1;
                            
                            break;
                        }
                    }

                    // 3. ADD SAFETY CHECK FOR THE ARRAY SIZE
                    
                    if (!alreadyCounted && foundCount < 100)
                    {
                        sumInvalidIds += invalidId;
                        found[foundCount++] = invalidId;
                    }
                }
            }
        }

    }

    fclose(fp);
    fp = NULL;

    printf("Total of Invalid Ids is: %lld\n", sumInvalidIds);

    return 0;
}