#include "words.h"

/**
* Function to sort counted words in descending order by count.
*
* @param {Dictionary} **data - point to array of structures
* @param {int} word_count - total count of words
*/
void descending_sort(Dictionary **data, int word_count)
{
    // Loop over first array
    for (int i = 0; i < word_count; i++)
    {
        // Loop over second array
        for (int j = 0; j < word_count; j++)
        {
            // If first array count is greater than second array count
            if ((*data)[j].count < (*data)[i].count)
            {
                // Temporary variables for first array members
                char *temp_word = (*data)[i].word;
                int temp_count = (*data)[i].count;

                // Assign second array member values to first array members
                (*data)[i].word = (*data)[j].word;
                (*data)[i].count = (*data)[j].count;

                // Set second array members to the temporary variable values
                (*data)[j].word = temp_word;
                (*data)[j].count = temp_count;
            }
        }
    }
}