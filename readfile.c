#include <stdio.h>
#include <stdlib.h>

/**
* Function to read words from file into array of chars
*
* @param {FILE} *file - pointer to the file we want to read from
* @param {char} **words - words array to read data from file to
* @param {size_t} *length - pointer to length variable for total bytes from file
*/
void read_file(FILE *file, char **words, size_t *length)
{
    long size = 0;

    // If there is a file
    if (file)
    {
        // Find total number of bytes from file
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Allocate enough memory to read words
        *words = (char*)malloc(sizeof(char) * (size + 1));

        // Initialize each element in array
        for (int i = 0; i <= size; ++i)
        {
            (*words)[i] = 0;
        }

        // Read in the data
        if (words)
        {
            *length = fread(*words, 1, size, file);
        } 
    }
}