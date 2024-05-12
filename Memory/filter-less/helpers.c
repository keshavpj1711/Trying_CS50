// This is where the actual logic of functions is to be written

#include "helpers.h"
#include <math.h>

// Writing swap function
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            float avg_color = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0;
            // Rounding off avg_color 
            avg_color = round(avg_color);

            // Update pixel values
            image[i][j].rgbtRed = avg_color;
            image[i][j].rgbtBlue = avg_color;
            image[i][j].rgbtGreen = avg_color;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // To complete this task we must know the sepia formula that is 
    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue

    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < width; j++) {
            
            // Finding sepia rgb
            float sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // But there is still one small issue 
            // This formula may sometimes result in values which are out of 255 range 
            // so we need to change them to 255, as to keep in range of 8 bit colors
            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }

            // Setting sepia colors to image
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    } 
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Here we just need to swap with the pixels on the other end of the row

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            swap(&image[i][j], &image[i][width-1-j]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
