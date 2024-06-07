// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

bool freeNode(node *); // for free dictionary

unsigned int count = 0; // size of the dictionary

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char str[LENGTH + 1];
    int i;
    for (i = 0; word[i] != '\0'; i++)
        str[i] = tolower(word[i]);

    str[i] = '\0';

    unsigned int hash_index = hash(str);

    node *current = table[hash_index];
    if (current == NULL)
        return false;

    while (1)
    {

        if (strcmp(current->word, str) == 0)
            return true;
        else if (current->next != NULL)
            current = current->next;
        else
            return false;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    int len = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += word[i];
        len++;
    }

    return ((sum + len) % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    // Read each word in the file
    char buffer[LENGTH +
                2]; // i don't know why it's not working without +2 , it's taking extra 1 byte

    // Read each word in the file
    while (fgets(buffer, sizeof(buffer), source) != NULL)
    {
        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Add each word to the hash table
        unsigned int hash_index = hash(buffer);

        if (table[hash_index] == NULL)
        {
            node *newNode = (node *) malloc(sizeof(node));
            if (newNode == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                return false;
            }

            strcpy(newNode->word, buffer);
            newNode->next = NULL;
            table[hash_index] = newNode;
        }
        else
        {
            node *prev = table[hash_index];

            node *newNode = (node *) malloc(sizeof(node));
            if (newNode == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                return false;
            }

            strcpy(newNode->word, buffer);
            newNode->next = prev;
            table[hash_index] = newNode;
        }

        count++; // count size of the dictionary
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// free node

bool freeNode(node *head)
{
    node *next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
    if (head != NULL)
        return false;

    return true;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (unsigned int i = 0; i < N; i++)
    {
        bool status = freeNode(table[i]);
        if (!status)
            return status;
    }

    return true;
}
