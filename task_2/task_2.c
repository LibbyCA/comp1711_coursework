#include "FitnessDataStruct.h"

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

    char choice;

    while (1)
    {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");

        choice = getchar();

        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 'A':
        case 'a':
            printf("Please enter the name of the data file: ");
            fgets(line_buffer, buffer_size, stdin);
            sscanf(line_buffer, " %s ", filename);
            // error if file cannot be opened successfully
            return 0;
            break;

        case 'B':
        case 'b':
            break;

        case 'C':
        case 'c':
            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    fclose(file);
    return 0;
}