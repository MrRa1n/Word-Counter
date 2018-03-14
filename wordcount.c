/**
* Wordcount application to read in a string from the command line or from a file and output the
* total words, total unique words and a count of each word's occurrence.
*
* @author Toby cook
* @version 1.0.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"
#include "readfile.h"
#include "tokenize.h"
#include "count.h"
#include "sort.h"

#define MAX_S 256

int main(int argc, char **argv)
{
    char *word_data, *file_extension = "", *input_file_name = "", *output_file_name = "";
    size_t length = 0, ignore_case = 0;
    FILE *input_file, *output_file;
    Dictionary *dictionary;

    // Loop through arguments
    for (int i = 0; i < argc; ++i)
    {
        // Checks to see if there is an input_file file name
        if (strcmp(argv[i], "-i") == 0)
        {
            if (argv[i + 1] != NULL && strcmp(argv[i + 1], "-o"))
            {
                // Retrieve the file extension and compare
                file_extension = argv[i + 1] + strlen(argv[i + 1]) - 4;
                if (strcmp(file_extension, ".txt") == 0)
                {
                    // Store file name
                    input_file_name = argv[i + 1];
                }
                else
                {
                    // Set empty string
                    input_file_name = "";
                    printf("No input file specified.\n");
                }
            }
            else
            {
                printf("No input file specified.\n");
            }
        }
        // Checks to see if there is an output_file file name
        if (strcmp(argv[i], "-o") == 0)
        {
            if (argv[i + 1] != NULL && strcmp(argv[i + 1], "-c"))
            {
                // Retrieve the file extension and compare
                file_extension = argv[i + 1] + strlen(argv[i + 1]) - 4;

                if (strcmp(file_extension, ".txt") == 0)
                {
                    // Store file name
                    output_file_name = argv[i + 1];
                }
                else
                {
                    // Set empty string
                    output_file_name = "";
                    printf("No output file specified.\n");
                }
            }
            else
            {
                printf("No output file specified.\n");
            }
        }
        // Checks if ignore case command has been entered
        if (strcmp(argv[i], "-c") == 0)
        {
            ignore_case = 1;
        }
    }

    input_file = fopen(input_file_name, "r");
    output_file = fopen(output_file_name, "w");

    // If there is an input file
    if (input_file)
    {
        // Read contents of file into word buffer
        read_file(input_file, &word_data, &length);
        // Convert words to lower if user has entered -c command
        if (ignore_case == 1)
            strlwr(word_data);
    }
    else
    {
        // Declare temporary buffer to store fgets input_file
        char buffer[MAX_S];
        // Set input_file to read from stdin
        input_file = stdin;
        // Read input_file from the command line
        printf("Please enter some text: ");
        fgets(buffer, MAX_S, input_file);
        // Assign words and length values
        word_data = (ignore_case == 1) ? strlwr(buffer) : buffer;
        length = strlen(word_data) + 1;
        word_data[length-2] = '\0';
    }

    printf("\n");

    // Get the total number of words
    int word_count = count_words(word_data);
    int total_words = word_count;
    // Split words in buffer and store total word count
    int unique_count = tokenize(&dictionary, word_data, &word_count);
    // Sort words in descending order
    descending_sort(&dictionary, unique_count);

    if (ignore_case == 1)
        printf("CHARACTER CASE IS BEING IGNORED!\n\n");

    // Print to file if there is one specified
    if (output_file)
    {
        fprintf(output_file, "The total words counted is: %d\n", total_words);
        fprintf(output_file, "The total unique words counted is: %d\n\n", unique_count);
        for (int i = 0; i < unique_count; ++i)
            fprintf(output_file, "%s : %d\n", dictionary[i].word, dictionary[i].count);
        fclose(output_file);

        printf("Words have been printed to the file: %s\n", output_file_name);
    }
    else
    {
        printf("The total words counted is: %d\n", total_words);
        printf("The total unique words counted is: %d\n\n", unique_count);
        for (int i = 0; i < unique_count; ++i)
            printf("%s : %d\n", dictionary[i].word, dictionary[i].count);
    }

    // Close the file and free the allocated memory for the structure
    fclose(input_file);
    for(int i = 0; i < unique_count; i++)
        free(dictionary[i].word);
    free(dictionary);
    free(word_data);
    return 0;
}