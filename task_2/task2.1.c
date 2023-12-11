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