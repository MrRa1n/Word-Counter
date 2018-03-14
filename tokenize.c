#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"

/**
* Function to split words buffer into single words and store them in Dictionary structure.
*
* @param {Dictionary} **data - pointer to array of structures
* @param {char} *words - word data that has been read in
* @param {int} *total_words - pointer to total_words variable
*/
int tokenize(Dictionary **dictionary, char *words, int *total_words)
{
    
    char *delim = " .,?!:;/\"\'\n\t";
    char **temp = malloc(sizeof(char *) * strlen(words) + 1);
    

    // Allocate enough memory for the total number of words counted
    *dictionary = (Dictionary*)malloc(sizeof(Dictionary *) * (*total_words));

    int count = 1, index = 0;

    // Split into individual words
    char *token = strtok(words, delim);
    while (token != NULL)
    {
        // Allocate memory for each token and copy into temp array position
        temp[index] = malloc(strlen(token) + 1);
        strcpy(temp[index], token);

        // Get the next word
        token = strtok(NULL, delim);

        index++;
    }

    // Loop through the temp array and count each word occurrence
    for (int i = 0; i < (*total_words); ++i)
    {
        for (int j = i + 1; j < (*total_words); ++j)
        {
            // If words match, increase the count and overwrite the other occurrences
            if (strcmp(temp[i], temp[j]) == 0)
            {
                count++;

                for (int k = j; k < (*total_words); ++k)
                {
                    // Overwrite words until there are no more occurrences
                    if (temp[k+1] != NULL)
                    {
                        strcpy(temp[k], temp[k+1]);
                    }
                }
                // Decrease the total word count for each duplicate word
                (*total_words)--;
                // Don't increment j
                j--;

            }
        }

        // Allocate memory for the word in our Dictionary structure
        int length = strlen(temp[i]) + 1;
        (*dictionary)[i].word = malloc(length);

        // Copy the word and its count into the Dictionary members
        strcpy((*dictionary)[i].word, temp[i]);
        (*dictionary)[i].count = count;

        // Reset count to 1
        count = 1;
    }

    // Free memory allocated for temp array
    free(temp);
    
    // Return the new word count
    return (*total_words);
}