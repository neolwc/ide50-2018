// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
}
node;

typedef struct trie {
    bool isWord;
    struct trie *children[27]; // 26 + '
}
trie;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
