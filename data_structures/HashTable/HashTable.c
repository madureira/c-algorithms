#include "HashTable.h"
#include <stdlib.h>

static unsigned long __hashtable_generate_hash(HashTableKey key, HashTableKeyType keyType, unsigned long capacity);

HashTable* new_hashtable(HashTableKeyType keyType, unsigned long capacity)
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }

    hashTable->keyType = keyType;
    hashTable->capacity = capacity;
    hashTable->size = 0;

    hashTable->items = calloc((size_t)hashTable->capacity, sizeof(HashTableItem*));
    if (hashTable->items == NULL)
    {
        free(hashTable);
        return NULL;
    }

    for (int i = 0; i < hashTable->capacity; i++)
    {
        hashTable->items[i] = NULL;
    }

    return hashTable;
}

void free_hashtable(HashTable* hashTable)
{
    if (hashTable != NULL)
    {
        for (int i = 0; i < hashTable->capacity; i++)
        {
            HashTableItem* item = hashTable->items[i];
            if (item != NULL)
            {
                free(item);
            }
        }
        free(hashTable->items);
        free(hashTable);
        hashTable = NULL;
    }
}

HashTable* hashtable_put(HashTable* hashTable, HashTableKey key, HashTableValue value)
{
    if (hashTable == NULL || key == NULL || value == NULL)
    {
        return NULL;
    }

    HashTableItem* item = (HashTableItem*)malloc(sizeof(HashTableItem));
    item->key = (HashTableKey*)malloc(sizeof(HashTableKey));
    item->value = (HashTableValue*)malloc(sizeof(HashTableValue));

    item->key = key;
    item->value = value;

    unsigned long hashIndex = __hashtable_generate_hash(key, hashTable->keyType, hashTable->capacity);

    HashTableItem* currentItem = hashTable->items[hashIndex];

    if (currentItem == NULL)
    {
        if (hashTable->size == hashTable->capacity)
        {
            free(item);
            return;
        }

        hashTable->items[hashIndex] = item;
        hashTable->size++;
    }
    else
    {
        hashTable->items[hashIndex] = item;
    }
}

HashTableValue hashtable_get(HashTable* hashTable, HashTableKey key)
{
    unsigned long hashIndex = __hashtable_generate_hash(key, hashTable->keyType, hashTable->capacity);

    HashTableItem* item = hashTable->items[hashIndex];

    if (item == NULL)
    {
        return NULL;
    }

    return item->value;
}

int hashtable_contains(HashTable* hashTable, HashTableKey key)
{
    unsigned long hashIndex = __hashtable_generate_hash(key, hashTable->keyType, hashTable->capacity);

    return (hashTable->items[hashIndex] == NULL) ? 0 : 1;
}

static unsigned long __hashtable_generate_hash(HashTableKey key, HashTableKeyType keyType, unsigned long capacity)
{
    unsigned int hash = 0;

    switch (keyType)
    {
    case HASHTABLE_KEY_TYPE_C_STRING:
    {
        unsigned long h = 0;
        char* str = (char*)key;
        for (int i = 0; str[i]; i++)
        {
            h += str[i];
        }
        hash = h % capacity;
        break;
    }
    case HASHTABLE_KEY_TYPE_INTEGER:
    {
        hash = (unsigned long)key % capacity;
        break;
    }
    default:
        break;
    }

    return hash;
}