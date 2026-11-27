
#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("student.txt", "w");

    if (fp == NULL)
    {
        printf("File could not be created.");
        return 1;
    }

    fprintf(fp, "Welcome to C File Handling!\n");
    fprintf(fp, "This is my first file handling program.\n");

    fclose(fp);

    printf("Data written successfully into the file.");

    return 0;
}
