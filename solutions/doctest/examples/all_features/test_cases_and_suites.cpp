// test_cases_and_suites.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "doctest.h"

#include "header.h"

static void doStuff() {
    int a = 5;
    a += 2;
    // asserts and other doctest functionality can be used in user code if checked for a testing context
    if(doctest::isRunningInTest())
        CHECK(a == 7);
}

TEST_CASE("an empty test that will succeed - not part of a test suite") {}

TEST_CASE("should fail because of an exception") {
    doStuff();

    throw_if(true, 0);
}

TEST_SUITE("scoped test suite") {
    TEST_CASE("part of scoped") {
        FAIL("");
    }

    TEST_CASE("part of scoped 2") {
        FAIL("");
    }
}

TEST_SUITE_BEGIN("some TS"); // begin "some TS"

TEST_CASE("part of some TS") {
    FAIL("");
}

TEST_SUITE_END(); // ends "some TS"

TEST_CASE_FIXTURE(SomeFixture, "fixtured test - not part of a test suite") {
    data /= 2;
    CHECK(data == 85);
}

TEST_CASE("normal test in a test suite from a decorator" * doctest::test_suite("ts1") *
          doctest::timeout(0.000001)) {
    MESSAGE("failing because of the timeout decorator!");
}

static bool shouldSkip() { return false; }

TEST_SUITE("skipped test cases" * doctest::skip()) {
    TEST_CASE("unskipped" * doctest::skip(shouldSkip()) *
              doctest::description("this test has overrided its skip decorator")) {
        FAIL("");
    }
    TEST_CASE("skipped - inherited from the test suite") { FAIL(""); }
}

TEST_SUITE("test suite with a description" * doctest::description("regarding failures")) {
    TEST_CASE("fails - and its allowed" * doctest::may_fail()) { FAIL(""); }
    TEST_CASE("doesn't fail which is fine" * doctest::may_fail()) {}

    TEST_CASE("fails as it should" * doctest::should_fail()) { FAIL(""); }
    TEST_CASE("doesn't fail but it should have" * doctest::should_fail()) {}

    TEST_CASE("fails 1 time as it should" * doctest::expected_failures(1)) { FAIL(""); }
    TEST_CASE("fails more times as it should" * doctest::expected_failures(1)) {
        FAIL_CHECK("");
        FAIL_CHECK("");
    }
}
