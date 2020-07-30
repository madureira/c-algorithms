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
    int string_c_is_equal(String* first, const char* second);

    /*
        Join the current String with another String value and returns its pointer.
    */
    String* string_concat(String* first, String* second);

#ifdef __cplusplus
}
#endif

#endif // STRING_H