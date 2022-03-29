#include <iostream>
#include "stb_image/stb_image.h"
#include "stb_image/stb_image_write.h"
#include "PerlinNoise.hpp"

int main()
{
    const int width = 250;
    const int height = 250;
    const int channels_num = 3;

    PerlinNoise pn(45875);

    unsigned char data[width * height * channels_num];

    int index = 0;

    for (unsigned int i = 0; i < height; ++i)
    { // y
        for (unsigned int j = 0; j < width; ++j)
        { // x
            double x = (double)j / ((double)width);
            double y = (double)i / ((double)height);

            // Typical Perlin noise
            double n = pn.noise(10 * x, 10 * y, 0.8);

            // Map the values to the [0, 255] interval, for simplicity we use
            // tones of grey
            float r = floor(255.0 * n);
            float g = floor(255.0 * n);
            float b = floor(255.0 * n);

            if (r >= 150.0f && r <= 210.0f) // Mountains
            {
                r = 150.0f;
                g = 75.0f;
                b = 0.0f;
            }
            else if (r <= 90.0f) // Sea
            {
                r = 0.0f;
                g = 105.0f;
                b = 148.0f;
            }
            else if (r >= 90.0f && r <= 150.0f) // Forests
            {
                r = 34.0f;
                g = 139.0f;
                b = 34.0f;
            }
            else if (r > 210.0f) // Mountain Peaks
            {
                r = 255.0f;
                g = 255.0f;
                b = 255.0f;
            }

            data[index++] = r;
            data[index++] = g;
            data[index++] = b;
        }
    }

    stbi_write_jpg("result.jpg", width, height, channels_num, data, 100);

    return 0;
}