
#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("student.txt", "a");

    if (fp == NULL)
    {
        printf("File could not be opened.");
        return 1;
    }

    fprintf(fp, "\nNew data has been appended to the file.");
    fprintf(fp, "\nLearning C File Handling is interesting.");

    fclose(fp);

    printf("Data appended successfully!");

    return 0;
}
