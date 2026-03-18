#include <stdio.h>
#include <stdlib.h>   // for malloc
#include <ctype.h>   // to use a function to check if char is a number

#define FILENAME "LobbyBatteries.txt"

int main()
{
    
    FILE *fp = fopen(FILENAME, "r");
    char *bank = NULL;

    size_t bufferSize = 0;
    int totalOutputJoltage = 0;

    if(fp == NULL)
    {
        printf("File doesn't exist!\n");
        return -1;
    }

    while(getline(&bank, &bufferSize, fp) != -1)
    {
        

    }

    free(bank);
    fclose(fp);
    fp = NULL;

    printf("The total output joltage is: %d\n", totalOutputJoltage);

    return 0;
}