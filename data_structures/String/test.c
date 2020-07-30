#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "String.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp((a), (b)) == 0)
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

void test_string_c_is_equal()
{
    String* first = new_string("AAA");
    char* second = "AAA";

    ASSERT_INT_EQUALS(string_c_is_equal(first, second), 1);

    second = "AAB";

    ASSERT_INT_EQUALS(string_c_is_equal(first, second), 0);

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

int main()
{
    test_new_string();
    test_string_length();
    test_string_is_equal();
    test_string_c_is_equal();
    test_string_concat();

    return 0;
}