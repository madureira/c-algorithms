#include "String.h"
#include <stdlib.h>

String* new_string(const char* value)
{
    if (value == NULL)
    {
        return NULL;
    }

    String* newString = (String*)malloc(sizeof(String));

    if (newString == NULL)
    {
        return NULL;
    }

    size_t n = 0;
    while (value[n] != '\0')
    {
        n++;
    }

    newString->value = (char*)malloc((n + 1) * sizeof(char));

    if (newString->value == NULL)
    {
        free(newString);
        return NULL;
    }

    newString->length = n;

    for (unsigned int i = 0; i < n; i++)
    {
        newString->value[i] = value[i];
    }

    newString->value[n] = '\0';

    return newString;
}

void free_string(String* str)
{
    str->length = 0;
    free(str->value);
    free(str);
    str = NULL;
}

int string_is_equal(String* first, String* second)
{
    if (first == NULL && second == NULL)
    {
        return 1;
    }

    if (first == NULL && second != NULL || first != NULL && second == NULL)
    {
        return 0;
    }

    if (first->length != second->length)
    {
        return 0;
    }

    for (int i = 0; i < first->length; i++)
    {
        if (first->value[i] != second->value[i])
        {
            return 0;
        }
    }

    return 1;
}

int string_is_equal_c(String* first, const char* second)
{
    if (first == NULL && second == NULL)
    {
        return 1;
    }

    if (first == NULL && second != NULL || first != NULL && second == NULL)
    {
        return 0;
    }

    for (int i = 0; i < first->length; i++)
    {
        if (first->value[i] != second[i])
        {
            return 0;
        }
    }

    return 1;
}

String* string_concat(String* first, String* second)
{
    if (first == NULL && second == NULL)
    {
        return NULL;
    }

    if (first != NULL && second == NULL)
    {
        return first;
    }

    if (first == NULL && second != NULL)
    {
        return second;
    }

    String* temp = (String*)malloc(sizeof(String));

    if (temp == NULL)
    {
        return NULL;
    }

    temp->value = (char*)malloc(((size_t)first->length + second->length + 1) * sizeof(char));

    if (temp->value == NULL)
    {
        free(temp);
        return NULL;
    }

    temp->length = first->length + second->length;

    unsigned int i = 0;
    for (i; i < first->length; i++)
    {
        temp->value[i] = first->value[i];
    }

    for (unsigned j = 0; j < second->length; j++)
    {
        temp->value[i] = second->value[j];
        i++;
    }

    temp->value[temp->length] = '\0';

    free_string(first);

    first = temp;

    return first;
}

String* string_concat_c(String* first, const char* second)
{
    String* temp = new_string(second);
    first = string_concat(first, temp);
    free_string(temp);
    temp = NULL;

    return first;
}

int string_indexof(String* first, String* second)
{
    if (first == NULL || second == NULL)
    {
        return -1;
    }

    if (first->value == NULL || second->value[0] == '\0' || first->length < second->length)
    {
        return -1;
    }

    int found = 0;
    for (int i = 0; i < first->length; i++)
    {
        for (int j = 0; j < second->length; j++)
        {
            if (first->value[i] == second->value[j])
            {
                found++;
                if (found == second->length)
                {
                    return i;
                }
            }
            else
            {
                found = 0;
                break;
            }
        }
    }

    return -1;
}

int string_indexof_c(String* first, const char* second)
{
    if (first == NULL || second == NULL)
    {
        return -1;
    }

    if (first->value == "" || first->length == 0 || second[0] == '\0')
    {
        return -1;
    }

    size_t n = 0;
    while (second[n] != '\0')
    {
        n++;
    }

    if (first->length < n)
    {
        return -1;
    }

    int found = 0;
    for (int i = 0; i < first->length; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (first->value[i] == second[j])
            {
                found++;
                if (found == n)
                {
                    return i;
                }
            }
            else
            {
                found = 0;
                break;
            }
        }
    }

    return -1;
}

int string_contains(String* first, String* second)
{
    return (string_indexof(first, second) > -1) ? 1 : 0;
}

int string_contains_c(String* first, const char* second)
{
    return (string_indexof_c(first, second) > -1) ? 1 : 0;
}

int string_is_empty(String* first)
{
    if (first == NULL || first->value == NULL || first->length == 0 || first->value[0] == '\0')
    {
        return 1;
    }

    return 0;
}

String* string_clear(String* str)
{
    free_string(str);
    str = NULL;
    str = new_string("");

    return str;
}

String* string_set(String* first, String* second)
{
    return NULL;
}