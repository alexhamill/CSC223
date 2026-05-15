#ifndef BDSC
#include <stdio.h>
#endif

unsigned tests;
unsigned pass_tests;
unsigned fail_tests;

unsigned asserts;
unsigned pass_asserts;
unsigned fail_asserts;

unsigned cur_asrt;
unsigned fail_tst;
unsigned first_test;

START_TESTING(file)
char* file; 
{
    tests = 0;
    pass_tests = 0;
    fail_tests = 0;
    
    asserts = 0;
    pass_asserts = 0;
    fail_asserts = 0;
    
    fail_tst = 0;
    cur_asrt = 0;
    first_test = 1;
    
    printf("\n\t\033[36m---\033[0m %s \033[36m---\033[0m\n", file);
}

inc_pass()
{
    if (tests != 1 && !fail_tst) {
        pass_tests++;
    }
}

/* Test case macro */
#define TEST_CASE(desc) printf("\n\t%s\n", desc); tests++; inc_pass(); cur_asrt = 0; fail_tst = 0; first_test = 0;

/* Color helpers */
#define OK(msg)  printf("\t\t\033[0;32m%s\033[0;37m.\n", msg)
#define FAIL_MSG(msg) printf("\t\t\033[0;31m%s\033[0;37m.\n", msg)

ASSERT(expr, msg)
int expr;
char* msg;
{
    if (expr) {
        PASS();
        OK(msg);
    } else {
        FAIL();
        FAIL_MSG(msg);
    }
}

ASSERT_EQ(v1, v2, msg)
int v1; int v2;
char* msg;
{
    if (v1 == v2) {
        PASS();
        OK(msg);
    } else {
        FAIL();
        printf("\t\t\033[0;31m%s: %d != %d\033[0;37m.\n", msg, v1, v2);
    }
}

STR_EQ(s1, s2, msg)
char* s1; char* s2;
char* msg;
{
    if (strcmp(s1, s2) == 0) {
        PASS();
        OK(msg);
    } else {
        FAIL();
        printf("\t\t\033[0;31m%s: '%s' != '%s'\033[0;37m.\n", msg, s1, s2);
    }
}

STR_NEQ(s1, s2, msg)
char* s1; char* s2;
char* msg;
{
    if (strcmp(s1, s2) != 0) {
        PASS();
        OK(msg);
    } else {
        FAIL();
        printf("\t\t\033[0;31m%s: '%s' != '%s'\033[0;37m.\n", msg, s1, s2);
    }
}

ARR_INCR(arr, n, msg)
int arr[];
int n;
char* msg;
{
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            FAIL();
            printf("\t\t\033[0;31m%s: index %d: %d > %d\033[0;37m.\n", 
                   msg, i, arr[i], arr[i + 1]);
            return;
        }
    }
    PASS();
    OK(msg);
}

ARR_DECR(arr, n, msg)
int arr[];
int n;
char* msg;
{
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i+1]) {
            FAIL();
            printf("\t\t\033[0;31m%s: index %d: %d < %d\033[0;37m.\n", 
                   msg, i, arr[i], arr[i + 1]);
            return;
        }
    }
    PASS();
    OK(msg);
}

ARR_EQ(exp, act, n, msg)
int exp[];
int act[];
int n;
char* msg;
{
    int i;
    for (i = 0; i < n; i++) {
        if (exp[i] != act[i]) {
            FAIL();
            printf("\t\t\033[0;31m%s: index %d: exp %d, got %d\033[0;37m.\n", 
                   msg, i, exp[i], act[i]);
            return;
        }
    }
    PASS();
    OK(msg);
}

PASS() {
    asserts++;
    cur_asrt++;
    pass_asserts++;
    printf("\t\033[0;32m[%d] PASS\033[0;37m\n", cur_asrt);
}

FAIL() {
    asserts++;
    cur_asrt++;
    if (!fail_tst) {
        fail_tst = 1;
        fail_tests++;
    }
    fail_asserts++;
    printf("\t\033[0;31m[%d] FAIL\033[0;37m\n", cur_asrt);
}

/* Test suite summary */
END_TESTING() {
    inc_pass();
    
    printf("\n\t====================================\n"); 
    (tests == 1) ? printf("\t1 test.\n") : printf("\t%d tests.\n", tests);
    printf("\t\033[0;32m%d passed\033[0;37m, \033[0;31m%d failed\033[0;37m.",
           pass_tests, fail_tests);
    
    (asserts == 1) ? printf("\n\n1 assertion.\n") : printf("\n\n\t%d assertions.\n", asserts);
    printf("\t\033[0;32m%d passed\033[0;37m, \033[0;31m%d failed\033[0;37m.",
           pass_asserts, fail_asserts);
    printf("\n\t====================================\n");
}
