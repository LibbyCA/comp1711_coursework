#include "FitnessDataStruct.h"

// Complete the main function
int main()
{
    FITNESS_DATA daily_readings[100];
    char line_buffer[buffer_size];
    char filename[buffer_size];
    char choice;
    int counter;

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
            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }
            // error if file cannot be opened successfully
            fclose(stdin);
            break;

        case 'B':
        case 'b':
            counter = 0;

            while (fgets(line_buffer, buffer_size, input))
            {
                tokeniseRecord(line_buffer, ",", daily_readings[counter].date, daily_readings[counter].time);
                counter++;
            }
            for (int i = 0; i < counter; i++)
            {
                printf("%s - time %s", daily_readings[i].date, daily_readings[i].time);
            }
            printf("Number of records in file: %d\n", counter);
            fclose(input);
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
}