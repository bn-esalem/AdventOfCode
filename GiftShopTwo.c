#include <stdio.h>
#include <string.h>
#include <stdbool.h>

# define FILENAME "InvalidIDs.txt"

bool isInvalidID(long long id);


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

    while(fscanf(fp, "%lld-%lld,", &start, &end) != EOF)
    {
        for(long long currentId = start; currentId <= end; currentId++)
        {
            if(isInvalidID(currentId) == true)
            {
                sumInvalidIds += currentId;
            }
        }
    }

    fclose(fp);
    fp = NULL;

    printf("Total of Invalid Ids is: %lld\n", sumInvalidIds);

    return 0;
}

bool isInvalidID (long long id)
{
    char str[32];
    sprintf(str, "%lld", id);
    int totalLen = strlen(str);

    for(int patternLen = 1; patternLen <= totalLen / 2; patternLen++)
    {
        if(totalLen % patternLen == 0)
        {
            bool matches = true;

            for(int i = patternLen; i < totalLen; i++)
            {
                if(str[i] != str[i % patternLen])
                {
                    matches = false;
                    break;
                }
            }

            if(matches == true)
            {
                printf("Invalid ID found: %lld (Pattern length: %d)\n", id, patternLen);
                return true;
            }
        }

    }

    return false;
}