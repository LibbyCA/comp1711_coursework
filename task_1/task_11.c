#include <stdio.h>

typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

int main()
{

    FILE *fp = fopen("FitnessData_2023.csv", "r");
    if (!fp)
    {
        printf("Error occured");
        return 0;
    }
    char buff[1024];

    int row_count = 0;
    int field_count = 0;

    dict values[999];

    int i = 0;
    while (fgets(buff, 1024, fp))
    {
        printf("%s\n", buff);
    }
}