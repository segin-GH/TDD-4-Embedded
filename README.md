

# Test-Driven Devlopment-4-Embedded

### What is TDD?
Test-Driven Developement is a technique for building software incremenatlly. simply put no prodection code is written before without first writing a failing unit test  _**Tests are small.**_ _**Test are automated**_  Test-driving is logical Insted of diving into the prodection code, leaving testing  for latter the Tdd pratitioner expersses the desired behavior of the code in test. only then do they write the code making test pass.

### RED  GREEN REFACTOR
The rhythm of tdd is refferd  to as _Red-Green-Refactor._

![rumbling-about-test-driven-development](https://user-images.githubusercontent.com/98380527/203617797-2ecde856-e67c-44a8-a632-329ee0d74849.jpeg)

### TDD Benefits
just as with any  skills.  ttd skills take time to develope. Many devs have adopted would not go back to debug-later programing 

- `Fewer bugs`
- `Less debug time`
- `Documentaion that dies not lie`
- `Improved design`
-  `Fun and rewarding`

## Test-Driving tools and Conventions

### Unit Test Harness

A unit test harness is a software package that allows a programmer
to experss how production code should behave.

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
    TEST_ASSERT_EQUAL(4, sprintf(output, "hey")); // Test ment to fail
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
```

```
 Running sprintf...
../main/main.c:14:sprintf:FAIL: Expected 4 Was 3

-----------------------
1 Tests 1 Failures 0 Ignored 
FAIL
```

For more examples on how to write tests like the above check [FirstUnitTest](https://github.com/segin-GH/TDD-4-Embedded/tree/main/FirstUnitTest) 

