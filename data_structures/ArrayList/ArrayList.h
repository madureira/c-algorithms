#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#define ARRAY_LIST_SUCCESS 1
#define ARRAY_LIST_FAILURE 0
#define ARRAY_LIST_INITIAL_CAPACITY 128

    typedef void* ArrayListValue;

    typedef struct ArrayList
    {
        ArrayListValue* __elements;
        unsigned int __length;
        unsigned int __capacity;
    } ArrayList;

    typedef int (*ArrayListCompareFunction)(ArrayListValue a, ArrayListValue b);

    /*
        Creates a new empty ArrayList.
    */
    ArrayList* new_arraylist();

    /*
        Delete an existent ArrayList.
    */
    void free_arraylist(ArrayList* arrayList);

    /*
        Inserts a value in a specific position of an ArrayList.
    */
    int arraylist_insert(ArrayList* arrayList, unsigned int index, ArrayListValue value);

    /*
        Adds a value to the beginning of an ArrayList.
    */
    int arraylist_prepend(ArrayList* arrayList, ArrayListValue value);

    /*
        Adds a value to the final of an ArrayList.
    */
    int arraylist_append(ArrayList* arrayList, ArrayListValue value);

    /*
        Return the number of elements in ArrayList.
    */
    unsigned int arraylist_size(ArrayList* arrayList);

    /*
        Get a value by the index.
    */
    ArrayListValue arraylist_at(ArrayList* arrayList, unsigned int index);
    
    /*
        Given a value, returns the index position in the ArrayList.
    */
    int arraylist_indexof(ArrayList* arrayList, ArrayListValue value);

    /*
        Removes values between an interval from ArrayList.
    */
    void arraylist_remove_range(ArrayList* arrayList, unsigned int start, unsigned int end);

    /*
        Remove a value from the ArrayList, given an index.
    */
    void arraylist_remove(ArrayList* arrayList, unsigned int index);

    /*
        Sort the elements from an ArrayList.
    */
    void arraylist_sort(ArrayList* arrayList, ArrayListCompareFunction compareFunction);

    /*
        Reverse all elements from an ArrayList.
    */
    void arraylist_reverse(ArrayList* arrayList);

    /*
        Clear the entire ArrayList.
    */
    void arraylist_erase(ArrayList* arrayList);

    /*
        Get the ArrayList current capacity.
    */
    unsigned int arraylist_capacity(ArrayList* arrayList);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_LIST_H