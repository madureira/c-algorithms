#ifndef STRING_H
#define STRING_H

#include <stdbool.h> 

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct String
    {
        unsigned int length;
        char* value;
    } String;

    /*
        Creates a new String.
    */
    String* new_string(const char* value);

    /*
        Deallocates String pointer.
    */
    void free_string(String* str);

    /*
        Compare if two String is equals.
        Returns 1 if equals and 0 otherwise.
    */
    int string_is_equal(String* first, String* second);

    /*
        Compares if a String is equal to a c-string.
        Returns 1 if equals and 0 otherwise.
    */
    int string_is_equal_c(String* first, const char* second);

    /*
        Join the current String with another String value and returns its pointer.
    */
    String* string_concat(String* first, String* second);

    /*
        Join the current String with a c-string and returns its pointer.
    */
    String* string_concat_c(String* first, const char* second);

    /*
        Verifies if a String exists inside another.
        Returns the index of the first occurrence or -1 if it is not found.
    */
    int string_indexof(String* first, String* second);

    /*
        Verifies if a c-string exists inside a String.
        Returns the index of the first occurrence or -1 if it is not found.
    */
    int string_indexof_c(String* first, const char* second);

    /*
        Check if a String contains another.
        Returns 1 if contains and 0 otherwise.
    */
    int string_contains(String* first, String* second);

    /*
        Check if a String contains a c-string.
        Returns 1 if contains and 0 otherwise.
    */
    int string_contains_c(String* first, const char* second);

    /*
        Verifies if a String is completely empty.
        Returns 1 if equals and 0 otherwise.
    */
    int string_is_empty(String* first);

    /*
        Clear the entire String and returns a new pointer.
    */
    String* string_clear(String* first);

    /*
        Set a new value to a String.
    */
    String* string_set(String* first, String* second);

#ifdef __cplusplus
}
#endif

#endif // STRING_H