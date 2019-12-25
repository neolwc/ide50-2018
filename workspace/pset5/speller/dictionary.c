// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// #define TABLE_SIZE 26

// node *hashtable[TABLE_SIZE];
int counter = 0;
trie *root;

// int hash(const char *word)
// {
//     return tolower(word[0]) - 97;
// }

int indexOfChar(const char c)
{
    const int index = tolower(c) - 97;
    return index < 0 || index > 25 ? 26 : index;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // node *cursor = hashtable[hash(word)];

    // while (cursor != NULL)
    // {
    //     if (strcasecmp(cursor->word, word) == 0)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         cursor = cursor->next;
    //     }
    // }

    // return false

    trie *cursor = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        int index = indexOfChar(word[i]);
        cursor = cursor->children[index];
        if (cursor == NULL)
        {
            return false;
        }
    }

    return cursor->isWord;
}

trie *newTrie(void)
{
    trie *node = malloc(sizeof(trie));
    if (node == NULL)
    {
        return NULL;
    }
    node->isWord = false;
    for(int i = 0; i < 27; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    root = newTrie();
    FILE *file = fopen(dictionary, "r");
    if (root == NULL || file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        counter++;
        // int index = hash(word);
        // if (index > TABLE_SIZE || index < 0)
        // {
        //     return false;
        // }

        // node *new_node = malloc(sizeof(node));
        // strcpy(new_node->word, word);
        // new_node->next = hashtable[index];
        // hashtable[index] = new_node;

        trie *current = root;
        int len = strlen(word);
        for (int i = 0; i < len; i++)
        {
            int index = indexOfChar(word[i]);
            if (current->children[index] == NULL)
            {
                trie *new_trie = newTrie();
                current->children[index] = new_trie;
            }
            current = current->children[index];
        }
        current->isWord = true;
    }

    return fclose(file) == 0;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

void unloadTrie(trie *node)
{
    for (int i = 0; i < 27; i++)
    {
        trie *cursor = node->children[i];
        if (cursor != NULL)
        {
            unloadTrie(cursor);
        }
    }
    free(node);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // for(int i = 0; i < TABLE_SIZE; i++)
    // {
    //     node *cursor = hashtable[i];
    //     while (cursor != NULL)
    //     {
    //         node *temp = cursor;
    //         cursor = temp->next;
    //         free(temp);
    //     }
    // }

    unloadTrie(root);

    return true;
}
