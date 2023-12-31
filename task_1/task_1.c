#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// describe each variable
// class named FITNESS_DATA
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main()
{

    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int i = 0;
    FITNESS_DATA records[3];
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {

        char xsteps[8];
        if (i < 3)
        {
            tokeniseRecord(line_buffer, ",", records[i].date, records[i].time, xsteps);
            records[i].steps = atoi(xsteps);
        }
        i++;
    }

    printf("Number of records in file: %d\n", i);
    for (int j = 0; j < 3; j++)
        printf("%s/%s/%d\n", records[j].date, records[j].time, records[j].steps);

    fclose(file);
    return 0;
}