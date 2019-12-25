#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    int count = 0;
    FILE *image;
    BYTE *buffer = malloc(BLOCK_SIZE * sizeof(BYTE));
    char *filename = malloc(strlen("###.jpg") * sizeof(char));

    while(1)
    {
        int read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (read < BLOCK_SIZE)
            break;

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (image != NULL)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", count);
            image = fopen(filename, "w");
            count++;

            fwrite(buffer, BLOCK_SIZE, sizeof(BYTE), image);
        }
        else if (image != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, sizeof(BYTE), image);
        }
    }

    free(buffer);
    free(filename);
    fclose(file);
    fclose(image);
}
