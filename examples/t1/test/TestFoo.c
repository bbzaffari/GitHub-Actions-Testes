#include "unity_fixture.h"
#include "foo.h"

TEST_GROUP(Foo);

TEST_SETUP(Foo) {}
TEST_TEAR_DOWN(Foo) {}

// === Casos válidos (Classes de equivalência e limites) ===
TEST(Foo, RegularDay) {
    TEST_ASSERT_EQUAL_STRING("11/05/2021", foo(29,03,2021));
}

TEST(Foo, EndOf30DayMonth) {
    TEST_ASSERT_EQUAL_STRING("01/05/2021", foo(4,30,2021));
}

TEST(Foo, EndOf31DayMonth) {
    TEST_ASSERT_EQUAL_STRING("01/02/2021", foo(1,31,2021));
}

TEST(Foo, Feb28CommonYear) {
    TEST_ASSERT_EQUAL_STRING("01/03/2021", foo(2,28,2021));
}

TEST(Foo, Feb28LeapYear) {
    TEST_ASSERT_EQUAL_STRING("29/02/2020", foo(2,28,2020));
}

TEST(Foo, Feb29LeapYear) {
    TEST_ASSERT_EQUAL_STRING("01/03/2020", foo(2,29,2020));
}

TEST(Foo, EndOfYear) {
    TEST_ASSERT_EQUAL_STRING("01/01/2022", foo(12,31,2021));
}

// === Casos inválidos (Valores fora de intervalo) ===
TEST(Foo, MonthTooLow) {
    TEST_ASSERT_EQUAL_STRING("E01", foo(0,10,2000));
}

TEST(Foo, MonthTooHigh) {
    TEST_ASSERT_EQUAL_STRING("E01", foo(13,10,2000));
}

TEST(Foo, DayTooLow) {
    TEST_ASSERT_EQUAL_STRING("E02", foo(5,0,2000));
}

TEST(Foo, DayTooHigh31Month) {
    TEST_ASSERT_EQUAL_STRING("E02", foo(1,32,2000));
}

TEST(Foo, DayTooHigh30Month) {
    TEST_ASSERT_EQUAL_STRING("E02", foo(4,31,2000));
}

TEST(Foo, InvalidFebDate) {
    TEST_ASSERT_EQUAL_STRING("E02", foo(2,29,2019));
}

TEST(Foo, YearTooLow) {
    TEST_ASSERT_EQUAL_STRING("E03", foo(1,1,1899));
}

TEST(Foo, YearTooHigh) {
    TEST_ASSERT_EQUAL_STRING("E03", foo(1,1,2100));
}

TEST(Foo, OverflowYear) {
    TEST_ASSERT_EQUAL_STRING("E04", foo(12,31,2099));
}

