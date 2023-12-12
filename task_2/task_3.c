#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

FitnessData daily_readings[1000];
int buffer_size = 1000;
char line_buffer[1000];
char filename[1000];
int i;
int j;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps)
{
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL)
    {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL)
        {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL)
            {
                *steps = atoi(ptr);
            }
        }
    }
}

int main()
{
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, "%s", filename);
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: invalid file\n");
        return 1;
    }
    i = 0;
    j = 0;

    while (fgets(line_buffer, buffer_size, input) != NULL)
    {
        tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, daily_readings[i].steps);
        j++;
    }
    while (i < j)
    {
        if (daily_readings[i].date == NULL || daily_readings[i].time == NULL || daily_readings[i].steps == NULL)
        {
            return 1;
        }

        if (strlen(daily_readings[i].date) == 0 || strlen(daily_readings[i].time) == 0 || strlen(daily_readings[i].steps) == 0)
        {
            return 1;
        }
        i++;
    }
}