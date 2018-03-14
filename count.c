#include <string.h>
#include <stdlib.h>
/**
* Function to count the total number of words that have been read into array of chars
*
* @param {char} *words - word data that has been read in
* @return {int} count - total count of words in the array of characters
*/
int count_words(char *words)
{
    int index = 0, count = 0, flag = 1;
    char previous_char = '\0';

    // Run until a null terminator is encountered
    while (flag != 0)
    {
        // If the current character is ' ', '\n' or '\0'
        if (words[index] == ' ' || words[index] == '\n' || words[index] == '\0')
        {
            // If the previous char is not a ' ', '\n' and '\0' - increase the count
            if (previous_char != ' ' && previous_char != '\n' && previous_char != '\0')
            {
                count++;
            }
        }

        // Assign current character to previous_char variable for comparison
        previous_char = words[index];

        // End if null terminator, else increment index
        if (words[index] == '\0')
            flag = 0;
        else
            index++;
    }

    // Return the final word count
    return count;
}