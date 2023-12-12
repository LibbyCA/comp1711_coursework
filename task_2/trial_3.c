#include "FitnessDataStruct.h"

// Complete the main function
int main()
{
    FITNESS_DATA daily_readings[100];
    int buffer_size = 100;
    char line_buffer[buffer_size];
    char filename[buffer_size];
    char choice;
    int counter;
    int mean;
    int x;
    int lowest;
    int highest;
    int y;


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
        int i;

        

        while (getchar() != '\n');

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
            break;

        case 'B':
        case 'b':
            i = 0;
            while (fgets(line_buffer, buffer_size, input))
            {
                i++;
            }

            printf("Total number of records in the files: %d\n", i);
            fclose(input);
            break;

        case 'C':
        case 'c':
            i = 0;
            while (fgets(line_buffer, buffer_size, input))
            {
                char xsteps [15];
                printf("1");
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                i++;
            }
            lowest = daily_readings[0].steps;
            for (int j = 0; j < i; j ++)
            {
                if (daily_readings[j].steps < lowest) {
                    lowest = daily_readings[j].steps;
                    x = j;
                }

            }
            printf("Fewest steps: %s %s\n", daily_readings[x].date, daily_readings[x].time);
            fclose(input);
            break;

        case 'D':
        case 'd':
            i = 0;
            while (fgets(line_buffer, buffer_size, input))
            {
                char xsteps [15];
                printf("1");
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                i++;
            }
            highest = daily_readings[0].steps;
            for (int j = 0; j < i; j ++)
            {
                if (daily_readings[j].steps > highest) {
                    highest = daily_readings[j].steps;
                    y = j;
                }

            }
            printf("Highest steps: %s %s\n", daily_readings[y].date, daily_readings[y].time);
            fclose(input);
            break;

        case 'E':
        case 'e':
            i = 0;
            mean = 0;
            while (fgets(line_buffer, buffer_size, input))
            {
                char xsteps [8];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                mean += daily_readings[i].steps;
                printf ("%d\n", daily_readings[i].steps);
                i++;
            }
            mean /= i;
            printf("Mean step count: %d\n", mean);
            fclose(input);
            break;

        case 'F':
        case 'f':
             i = 0;
            while (fgets(line_buffer, buffer_size, input) != NULL)
            {
                char xsteps [15];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                printf("%s %s %d\n", daily_readings[i].date, daily_readings[i].time, daily_readings[i].steps);
            }
            fclose(input);
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