

# Test-Driven Devlopment-4-Embedded

### What is TDD?
Test-Driven Development is a technique for building software incrementally. simply put no protection code is written before without first writing a failing unit test  _**Tests are small.**_ _**Tests are automated**_  Test-driving is logical instead of diving into the production code, leaving testing for later the Tdd practitioner expresses the desired behavior of the code in the test. only then do they write the code making the test pass.

### RED  GREEN REFACTOR
The rhythm of TDD is referred to as _Red-Green-Refactor._

![rumbling-about-test-driven-development](https://user-images.githubusercontent.com/98380527/203617797-2ecde856-e67c-44a8-a632-329ee0d74849.jpeg)

### TDD Benefits
just as with any skills.  TDD skills take time to develop. Many devs have adopted would not go back to debug-later programming 

- `Fewer bugs`
- `Less debug time`
- `Documentation that dies not lie`
- `Improved design`
-  `Fun and rewarding`

## Test-Driving tools and Conventions

### Unit Test Harness

A unit test harness is a software package that allows a programmer
to express how production code should behave.

_*An example of a Test Harness  `unity`*_

```
#include <stdio.h>
#include <unity.h>

void app_main(void)
{
    UNITY_BEGIN();
    unity_run_test_by_name("Test 1");
    UNITY_END();
}

TEST_CASE("Test 1", "Test for sprintf")
{
    char output[5];
    TEST_ASSERT_EQUAL(4, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
```

*output in CLI :-*

```
 Running sprintf...
../main/main.c:14:sprintf:FAIL: Expected 4 Was 3

-----------------------
1 Tests 1 Failures 0 Ignored 
FAIL
```
For more examples of how to write tests like the above check [FirstUnitTest](https://github.com/segin-GH/TDD-4-Embedded/tree/main/FirstUnitTest) 

>**NOTE:** It's a judgment call on how far to take tests. you will see when we get into TDD  how to decide which test to write

With these kinds of tests written in [FirstUnitTest](https://github.com/segin-GH/TDD-4-Embedded/tree/main/FirstUnitTest)  you can see that some subtle duplication creeping into the test for eg `ouput[x]=""`  in every test case there is `output[x]=""` to avoid this we can use something called _test fixture_.

### Test Fixtures in Unity
example of test fixture:-
```
#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <unity_fixture.h>

/**
 *  @brief way to write test in test fixtures
 */


static char output[100];
static const char *expected;

TEST_GROUP(TEST_1);

/**
 *  @brief similar to a constructor
 */
TEST_SETUP(TEST_1)
{
    memset(output,0xaa, sizeof output);
    expected ="";
}

/**
 *  @brief similar to a deconstructor 
 */
TEST_TEAR_DOWN(TEST_1){}

/**
 *  @brief tests for sprintf
 */

TEST(TEST_1,noFormatOperation)
{
    char output[5] = "";
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}

TEST(TEST_1,insertString)
{
    char output[20] = "";
    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "world"));
    TEST_ASSERT_EQUAL_STRING("Hello world\n", output);
}

/**
 *  @brief grups all similar tests
 */
TEST_GROUP_RUNNER(TEST_1)
{
    RUN_TEST_CASE(TEST_1,noFormatOperation);
    RUN_TEST_CASE(TEST_1,insertString);
}

/**
 *  @brief a func that runs all the tests
 */
static void run_all_tests(void)
{
    RUN_TEST_GROUP(TEST_1);
}

/** 
 * @brief calling tests in main
 */
void app_main(void)
{
    UNITY_MAIN_FUNC(run_all_tests);
}


```
