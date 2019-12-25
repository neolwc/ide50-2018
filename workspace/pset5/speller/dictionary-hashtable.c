// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define TABLE_SIZE 26

node *hashtable[TABLE_SIZE];
int counter = 0;

int hash(const char *word)
{
    return tolower(word[0]) - 97;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = hashtable[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        counter++;
        int index = hash(word);
        if (index > TABLE_SIZE || index < 0)
        {
            return false;
        }

        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, word);
        new_node->next = hashtable[index];
        hashtable[index] = new_node;
    }

    return fclose(file) == 0;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = temp->next;
            free(temp);
        }
    }
    return true;
}
