// Some info about wav files
    // One 44 byte header: 
    // Many 2 byte samples
    // To chage the volume of a sample you just multiply it with the number

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef u_int8_t BYTE;
typedef u_int16_t BYTE2 ;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // First reading the header from input file
    BYTE header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);


    // TODO: Read samples from input file and write updated data to output file
    // Create a buffer for a single sample
    BYTE2 buffer;

    // Read single sample from input into buffer while there are samples left to read
    // fread returns zero if nothing left to read and zero is treated as false
    while (fread(&buffer, sizeof(BYTE2), 1, input))
    {
        // Update volume of sample
        buffer *= factor;

        // Write updated sample to new file
        fwrite(&buffer, sizeof(BYTE2), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
