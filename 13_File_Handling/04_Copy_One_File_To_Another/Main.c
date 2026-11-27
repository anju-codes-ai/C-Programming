
#include <stdio.h>

int main()
{
    FILE *source, *destination;
    int ch;

    source = fopen("source.txt", "r");

    if (source == NULL)
    {
        printf("Source file could not be opened.");
        return 1;
    }

    destination = fopen("destination.txt", "w");

    if (destination == NULL)
    {
        printf("Destination file could not be created.");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully!");

    return 0;
}
