#include<unity.h>
#include<stddef.h>
#include "library.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_darray_init() {
    DArray *da = darray_init(sizeof(int32_t), 10);
    TEST_ASSERT_NOT_NULL(da);
    TEST_ASSERT_EQUAL(10, da->cap);
    TEST_ASSERT_EQUAL(0, da->len);
    TEST_ASSERT_NOT_NULL(da->data);
    TEST_ASSERT_EQUAL(4, da->type_size);
}

// TODO test append

void test_darray_access() {
    DArray *da = darray_init(sizeof(int32_t), 10);
    da->len = 10;

    for (size_t i = 0; i < da->len; i++)
        *(int *) darray_access(da, i) = (int) i;

    for (size_t i = 0; i < da->len; i++)
        TEST_ASSERT_EQUAL_INT(i, *(int *) darray_access(da, i));
}

void test_darray_insert() {
    DArray *da = darray_init(sizeof(int32_t), 10);

    for (size_t i = 0; i < 9; i++) {
        darray_append(da, (int32_t *) &i);
    }

    darray_insert(da, 5, (int32_t []){100});

    for (size_t i = 0; i < 5; i++)
        TEST_ASSERT_EQUAL(i, *(int *) darray_access(da, i));

    TEST_ASSERT_EQUAL(100, *(int *) darray_access(da, 5));

    for (size_t i = 6; i < 10; i++) {
        TEST_ASSERT_EQUAL(i - 1, *(int *) darray_access(da, i));
    }

    darray_insert(da, 0, (int32_t []){1000});
    // for (size_t i = 0; i < da->len; i++) {
    //     printf("%d: %d\n", i, *(int *) darray_access(da, i));
    // }
    TEST_ASSERT_EQUAL(1000, *(int *) darray_access(da, 0));
    for (size_t i = 1; i < 6; i++)
        TEST_ASSERT_EQUAL(i-1, *(int *) darray_access(da, i));
    TEST_ASSERT_EQUAL(100, *(int *) darray_access(da, 6));
    for (size_t i = 7; i < 10; i++)
        TEST_ASSERT_EQUAL(i-2, *(int *) darray_access(da, i));
}

void test_darray_clear() {
    DArray *da = darray_init(sizeof(int32_t), 10);

    for (size_t i = 0; i < 10; i++) {
        darray_append(da, (int32_t *) &i);
    }

    TEST_ASSERT_EQUAL(10, da->len);
    for (size_t i = 0; i < 9; i++) {
        int el = *(int *) darray_access(da, i);
        TEST_ASSERT_EQUAL(el, i);
    }

    bool ok = darray_clear(da);
    TEST_ASSERT_TRUE(ok);
    TEST_ASSERT_EQUAL(0, da->len);
    TEST_ASSERT_NULL(da->data);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_darray_init);
    RUN_TEST(test_darray_access);
    RUN_TEST(test_darray_insert);
    RUN_TEST(test_darray_clear);

    return UNITY_END();
}
