#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "String.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

void test_new_string()
{
    String* str = new_string("test");

    ASSERT_STRING_EQUALS(str->value, "test");

    free_string(str);

    TEST_DONE
}

void test_string_length()
{
    String* str = new_string("test");

    ASSERT_INT_EQUALS(str->length, 4);

    free_string(str);

    TEST_DONE
}

void test_string_is_equal()
{
    String* first = new_string("AAA");
    String* second = new_string("AAA");

    ASSERT_INT_EQUALS(string_is_equal(first, second), 1);

    free_string(second);

    second = new_string("AAB");

    ASSERT_INT_EQUALS(string_is_equal(first, second), 0);

    free_string(first);
    free_string(second);

    TEST_DONE
}

void test_string_is_equal_c()
{
    String* first = new_string("AAA");
    char* second = "AAA";

    ASSERT_INT_EQUALS(string_is_equal_c(first, second), 1);

    second = "AAB";

    ASSERT_INT_EQUALS(string_is_equal_c(first, second), 0);

    free_string(first);

    TEST_DONE
}

void test_string_concat()
{
    String* first = new_string("AAA");
    String* second = new_string("BBB");

    first = string_concat(first, second);

    ASSERT_STRING_EQUALS(first->value, "AAABBB");

    free_string(first);
    free_string(second);

    TEST_DONE
}

void test_string_concat_c()
{
    String* first = new_string("AAA");
    char* second = "BBB";

    first = string_concat_c(first, second);

    ASSERT_STRING_EQUALS(first->value, "AAABBB");

    free_string(first);

    TEST_DONE
}

void test_string_indexof()
{
    String* first = new_string("AAABBBCCC");
    String* second = new_string("BBB");
    String* third = new_string("AAABZ");

    ASSERT_INT_EQUALS(string_indexof(first, second), 3);
    ASSERT_INT_EQUALS(string_indexof(first, third), -1);

    free_string(first);
    free_string(second);
    free_string(third);

    TEST_DONE
}

void test_string_indexof_c()
{
    String* first = new_string("AAABBBCCC");
    char* second = "BBB";
    char* third = "AAABZ";

    ASSERT_INT_EQUALS(string_indexof_c(first, second), 3);
    ASSERT_INT_EQUALS(string_indexof_c(first, third), -1);

    free_string(first);

    TEST_DONE
}

void test_string_contains()
{
    String* first = new_string("AAABBBCCC");
    String* second = new_string("BBB");
    String* third = new_string("AAABZ");

    ASSERT_INT_EQUALS(string_contains(first, second), 1);
    ASSERT_INT_EQUALS(string_contains(first, third), 0);

    free_string(first);
    free_string(second);
    free_string(third);

    TEST_DONE
}

void test_string_contains_c()
{
    String* first = new_string("AAABBBCCC");
    char* second = "BBB";
    char* third = "AAABZ";

    ASSERT_INT_EQUALS(string_contains_c(first, second), 1);
    ASSERT_INT_EQUALS(string_contains_c(first, third), 0);

    free_string(first);

    TEST_DONE
}

void test_string_is_empty()
{
    String* first = new_string("");
    String* second = new_string("AAA");

    ASSERT_INT_EQUALS(string_is_empty(first), 1);
    ASSERT_INT_EQUALS(string_is_empty(second), 0);

    free_string(first);
    free_string(second);

    TEST_DONE
}

void test_string_clear()
{
    String* str = new_string("AAA");

    str = string_clear(str);

    ASSERT_INT_EQUALS(string_is_empty(str), 1);

    free_string(str);

    TEST_DONE
}

void test_string_set()
{
    String* first = new_string("AAA");
    String* second = new_string("BBB");

    //TODO: first = string_set(first, second);

    //TODO: ASSERT_STRING_EQUALS(first->value, "BBB");

    free_string(first);
    free_string(second);

    TEST_DONE
}

int main()
{
    printf_s("String tests\n\n");

    test_new_string();
    test_string_length();
    test_string_is_equal();
    test_string_is_equal_c();
    test_string_concat();
    test_string_concat_c();
    test_string_indexof();
    test_string_indexof_c();
    test_string_contains();
    test_string_contains_c();
    test_string_is_empty();
    test_string_clear();
    test_string_set();

    return 0;
}