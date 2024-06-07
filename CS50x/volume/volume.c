// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    if (factor <= 0.0)
    {
        printf("Invalid scaling factor.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Copy header from input file to output file

    // Read and write the WAV header
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Read samples from input file and write updated data to output file
    // Calculate the number of samples in the file
    long totalSamples = (*(uint32_t *) (header + 40)) / sizeof(int16_t);
    for (long i = 0; i < totalSamples; i++)
    {
        int16_t buffer;
        fread(&buffer, sizeof(int16_t), 1, input);

        // Scale the sample
        buffer = (int16_t) (buffer * factor);

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
