

# Test-Driven Devlopment-4-Embedded

### What is TDD?
Test-Driven Development is a technique for building software incrementally. simply put no protection code is written before without first writing a failing unit test  _**Tests are small.**_ _**Tests are automated**_  Test-driving is logical instead of diving into the production code, leaving testing for later the Tdd practitioner expresses the desired behavior of the code in the test. only then do they write the code making the test pass.

### RED  GREEN REFACTOR
The rhythm of TDD is referred to as _Red-Green-Refactor._

```mermaid

%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#0000', 'edgeLabelBackground':'#ffffee','fontSize':'30px', 'tertiaryColor': '#fff0f0'}}}%%

graph LR;
RED-->GREEN-->REFACTOR-->RED
```


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
For more examples of how to write tests like the above check [FirstUnitTest](https://github.com/segin-GH/TDD-4-Embedded/tree/main/FirstUnitTest/main/main.c) 

>**NOTE:** It's a judgment call on how far to take tests. you will see when we get into TDD  how to decide which test to write

With these kinds of tests written in [FirstUnitTest](https://github.com/segin-GH/TDD-4-Embedded/tree/main/FirstUnitTest/main/main.c)  you can see that some subtle duplication creeping into the test for eg `ouput[x]=""`  in every test case there is `output[x]=""` to avoid this we can use something called _test fixture_.

### Test Fixtures in Unity
An example of a test fixture can be found at [TestFixtures](https://github.com/segin-GH/TDD-4-Embedded/blob/main/testFixtures/main/main.c)
Duplication reduction is the motivation for test fixtures it may not be 
noticeable in small tests but in larger tests, it can simplify your tests.

>_Those who want really reliable software will discover that they must find means of avoiding the majority of bugs to start with, and as a result the programming process will become cheaper. If you want more effective programmers, you will discover that they should not waste their time debugging, they should not introduce the bugs to start with._		 - **Edsger W. Dijkstra**    _"The Humble Programmer"_  	

### The Four-phase Test Pattern
The goal of using a test pattern are to create a concise, readable, and well-structured tests. if you follow this pattern  the test readers  can quickily determine what is being tested.

- `setup : Establish the precodictions to the test`
- `Exercise : Do something to the system`
- `Verify : Check the expected outcome`
- `Cleanup : return the system under test to its initial state`
