#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            double res = (double) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            // Update pixel values
            image[i][j].rgbtRed = (BYTE) round(res);
            image[i][j].rgbtGreen = (BYTE) round(res);
            image[i][j].rgbtBlue = (BYTE) round(res);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed =
                (int) round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaGreen =
                (int) round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaBlue =
                (int) round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            // Update pixel with sepia values

            image[i][j].rgbtRed = (sepiaRed >= 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen >= 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue >= 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over half of the width to swap pixels on opposite sides
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Function to blur the image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];

    // Populate the copy array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate through each pixel in the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Variables for sum of color values and count of pixels
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Iterate through the neighboring pixels within the 3x3 box
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int newRow = i + row;
                    int newCol = j + col;

                    // Check if the neighboring pixel is within bounds
                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        // Accumulate color values
                        sumRed += copy[newRow][newCol].rgbtRed;
                        sumGreen += copy[newRow][newCol].rgbtGreen;
                        sumBlue += copy[newRow][newCol].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color values
            double avgRed = (double) sumRed / count;
            double avgGreen = (double) sumGreen / count;
            double avgBlue = (double) sumBlue / count;

            // Update the pixel in the original image with the averaged color values
            image[i][j].rgbtRed = (BYTE) round(avgRed);
            image[i][j].rgbtGreen = (BYTE) round(avgGreen);
            image[i][j].rgbtBlue = (BYTE) round(avgBlue);
        }
    }
}
