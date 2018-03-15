#ifndef darray_tests_h
#define darray_tests_h

#include <stdio.h>
#include "darray.h"

#include "darray_tests_unit_1.h"
#include "darray_tests_unit_2.h"
#include "darray_tests_unit_3.h"
#include "darray_tests_unit_4.h"
#include "darray_tests_unit_5.h"
#include "darray_tests_unit_6.h"

long long current_timestamp(void);
void test_prepare(int *test_id, int *test_ok);
void test_result(int test_ok);
void darray_run_tests(void);

#endif /* darray_tests_h */
