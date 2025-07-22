#include <stdlib.h>
#include <string.h>
#include "substring.h"

// Helper function to find the index of a word in the words array
int find_word_index(const char *word, char const **words, int nb_words, int word_len)
{
    for (int i = 0; i < nb_words; i++)
    {
        if (strncmp(word, words[i], word_len) == 0)
        {
            return i;
        }
    }
    return -1;
}

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *indices = NULL;                 // Array to store the indices where valid substrings start
    int s_len = strlen(s);               // Length of the input string
    int word_len = strlen(words[0]);     // All words are of the same length
    int total_len = nb_words * word_len; // Total length of the concatenated substring
    int i, j;

    *n = 0; // Initialize the number of results to 0

    // Edge case: if the string is shorter than the total length of concatenated words
    if (s_len < total_len)
    {
        return NULL;
    }

    // Allocate space for the words count in the dictionary (hash map-like structure)
    int *current_count = (int *)malloc(nb_words * sizeof(int));

    // Traverse through the string with a sliding window of total_len
    for (i = 0; i <= s_len - total_len; i++)
    {
        // Reset word frequency counts
        memset(current_count, 0, nb_words * sizeof(int));

        // Split the current window into words of size word_len
        for (j = 0; j < nb_words; j++)
        {
            int word_start = i + j * word_len;
            const char *current_word = &s[word_start];
            int word_idx = find_word_index(current_word, words, nb_words, word_len);

            if (word_idx == -1)
            {
                // If the word is not in the list, break early
                break;
            }

            current_count[word_idx]++; // Increase count for the word

            // If the count of this word exceeds what is allowed, break early
            if (current_count[word_idx] > 1)
            {
                break;
            }
        }

        // If we checked all words and they matched exactly once
        if (j == nb_words)
        {
            // Allocate or reallocate memory for the indices
            indices = realloc(indices, (*n + 1) * sizeof(int));
            indices[*n] = i; // Store the starting index
            (*n)++;          // Increment the count of valid indices
        }
    }

    // Free allocated memory
    free(current_count);

    // If no valid substring was found, return NULL
    if (*n == 0)
    {
        free(indices);
        return NULL;
    }

    return indices;
}
