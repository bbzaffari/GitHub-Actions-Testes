#include "unity_fixture.h"

TEST_GROUP_RUNNER(Foo) {
    // Testes de fluxo normal
    RUN_TEST_CASE(Foo, RegularDay);
    RUN_TEST_CASE(Foo, EndOf30DayMonth);
    RUN_TEST_CASE(Foo, EndOf31DayMonth);
    RUN_TEST_CASE(Foo, Feb28CommonYear);
    RUN_TEST_CASE(Foo, Feb28LeapYear);
    RUN_TEST_CASE(Foo, Feb29LeapYear);
    RUN_TEST_CASE(Foo, EndOfYear);
    // Testes de valores fora do intervalo
    RUN_TEST_CASE(Foo, MonthTooLow);
    RUN_TEST_CASE(Foo, MonthTooHigh);
    RUN_TEST_CASE(Foo, DayTooLow);
    RUN_TEST_CASE(Foo, DayTooHigh31Month);
    RUN_TEST_CASE(Foo, DayTooHigh30Month);
    RUN_TEST_CASE(Foo, InvalidFebDate);
    RUN_TEST_CASE(Foo, YearTooLow);
    RUN_TEST_CASE(Foo, YearTooHigh);
    RUN_TEST_CASE(Foo, OverflowYear);
}

