#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* HashTableKey;
    typedef void* HashTableValue;

    typedef enum HashTableKeyType
    {
        HASHTABLE_KEY_TYPE_C_STRING,
        HASHTABLE_KEY_TYPE_INTEGER
    } HashTableKeyType;

    typedef struct HashTableItem
    {
        HashTableKey key;
        HashTableValue value;
    } HashTableItem;

    typedef struct HashTable
    {
        unsigned int size;
        unsigned long capacity;
        HashTableKeyType keyType;
        HashTableItem** items;
    } HashTable;

    /*
        Create a new HashTable.
    */
    HashTable* new_hashtable(HashTableKeyType keyType, unsigned long capacity);

    /*
        Free the HashTable memory.
    */
    void free_hashtable(HashTable* hashTable);

    /*
        Store data in the HashTable.
    */
    HashTable* hashtable_put(HashTable* hashTable, HashTableKey key, HashTableValue value);

    /*
        Get a value by the key from a HashTable.
    */
    HashTableValue hashtable_get(HashTable* hashTable, HashTableKey key);

    /*
        Returns 1 if the key exists and 0 otherwise.
    */
    int hashtable_contains(HashTable* hashTable, HashTableKey key);

#ifdef __cplusplus
}
#endif

#endif // HASH_TABLE_H
