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

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_darray_init);

    return UNITY_END();
}