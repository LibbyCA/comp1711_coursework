#include "FitnessDataStruct.h"

// Complete the main function
int main()
{
    FITNESS_DATA daily_readings[1000];
    int buffer_size = 1000;
    char line_buffer[buffer_size];
    char filename[buffer_size];
    char choice;
    float mean;
    int curr;
    int x;
    int lowest;
    int highest;
    int y;
    int i;
    int start;
    int end;
    double total;
    int maxInterval = 0;
    int maxStart = 0;

    while (1)
    {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        printf("Enter choice: ");
        choice = getchar();

        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
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
            fseek(input, 0, SEEK_SET);
            i = 0;
            while (fgets(line_buffer, buffer_size, input) != NULL)
            {
                i++;
            }

            printf("Total records: %d\n", i);
            break;

        case 'C':
        case 'c':
            fseek(input, 0, SEEK_SET);
            i = 0;
            while (fgets(line_buffer, buffer_size, input) != NULL)
            {
                char xsteps[100];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                i++;
            }
            lowest = daily_readings[0].steps;
            for (int j = 0; j < i; j++)
            {
                if (daily_readings[j].steps < lowest)
                {
                    lowest = daily_readings[j].steps;
                    x = j;
                }
            }
            printf("Fewest steps: %s %s\n", daily_readings[x].date, daily_readings[x].time);
            break;

        case 'D':
        case 'd':
            fseek(input, 0, SEEK_SET);
            i = 0;
            while (fgets(line_buffer, buffer_size, input) != NULL)
            {
                char xsteps[100];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                i++;
            }
            highest = daily_readings[0].steps;
            for (int j = 0; j < i; j++)
            {
                if (daily_readings[j].steps > highest)
                {
                    highest = daily_readings[j].steps;
                    y = j;
                }
            }
            printf("Largest steps: %s %s\n", daily_readings[y].date, daily_readings[y].time);
            break;

        case 'E':
        case 'e':
            fseek(input, 0, SEEK_SET);
            i = 0;
            mean = 0;
            while (fgets(line_buffer, buffer_size, input))
            {
                char xsteps[100];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                total += daily_readings[i].steps;
                i++;
            }
            mean = total / i;
            printf("Mean step count: %d\n", (int)(mean + 0.5));
            break;

        case 'F':
        case 'f':
            fseek(input, 0, SEEK_SET);
            i = 0;
            curr = 0;
            while (fgets(line_buffer, buffer_size, input) != NULL)
            {
                char xsteps[100];
                tokeniseRecord(line_buffer, ",", daily_readings[i].date, daily_readings[i].time, xsteps);
                daily_readings[i].steps = atoi(xsteps);
                i++;
            }
            for (int j = 0; j < i; j++)
            {
                if (daily_readings[j].steps > 500)
                {
                    int curr = 1;
                    int start = j;
                    int end = j;
                    while (daily_readings[end + 1].steps > 500 && end + 1 < i)
                    {
                        end++;
                        curr++;
                    }
                    if (curr > maxInterval)
                    {
                        maxInterval = curr;
                        maxStart = start;
                    }

                    j = end;
                }
            }
            if (maxInterval > 0)
            {
                printf("%s %s\n", daily_readings[maxStart].date, daily_readings[maxStart].time);
                printf("%s %s\n", daily_readings[maxStart + maxInterval -1].date, daily_readings[maxStart + maxInterval - 1].time);
            }
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default:
            printf("Invalid choice. Try again.\n");
            fclose(input);
            return 0;
            break;
        }
    }
}