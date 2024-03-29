

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

```.c
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

Unity test fixture is a testing framework for the C programming language that allows for the creation and organization of unit tests. It provides a set of functions and macros for defining and running tests, as well as for asserting the expected behavior of the code being tested.

- The `TEST_GROUP` macro is used to define a group of related test cases. Each test group has its own setup and tear-down functions that are run before and after each test in the group, respectively. This allows for common setup and cleanup operations to be performed for all tests in the group.

- The `TEST_SETUP` and `TEST_TEAR_DOWN` macros are used to define the setup and tear-down functions for a test group. These functions are run before and after each test in the group, respectively.

- The `TEST` macro is used to define an individual test case within a test group. It takes the name of the test group and the name of the test case as arguments.

- The `RUN_TEST_GROUP` and `RUN_TEST_CASE` functions are used to run all tests in a group, or a specific test within a group, respectively.

 - The `TEST_ASSERT_*` macros are used to make assertions about the expected behavior of the code being tested. For example, the `TEST_ASSERT_EQUAL` macro can be used to assert that two values are equal (int), while the `TEST_ASSERT_EQUAL_STRING` macro can be used to assert that two strings are equal.

Overall, Unity test fixture provides a powerful and easy-to-use framework for writing and organizing unit tests for C programs.

>**_Those who want really reliable software will discover that they must find means of avoiding the majority of bugs to start with, and as a result the programming process will become cheaper. If you want more effective programmers, you will discover that they should not waste their time debugging, they should not introduce the bugs to start with._**		 - **Edsger W. Dijkstra**    _"The Humble Programmer"_  	

### The Four-phase Test Pattern
The goal of using a test pattern is to create concise, readable, and well-structured tests. if you follow this pattern the test readers can quickly determine what is being tested.

- `setup : Establish the preconditions to the test`
- `Exercise : Do something to the system`
- `Verify : Check the expected outcome`
- `Cleanup : return the system under test to its initial state`
## Writing a C Module
In C programming, a module is a piece of software that has a specific purpose and contains a collection of functions and data that are designed to be used together. C modules are typically used to organize and reuse code, making it easier to develop and maintain complex software systems. you will also see that modular design is a natural outcome of TDD.

Modular programming can help make code more testable. By breaking a program up into smaller, modular pieces, individual modules can be tested separately to ensure that they are working properly. This can make it easier to identify and fix problems in the code, and can also make it easier to write automated tests to ensure the quality of the code. 

Example of a c module [Led Driver ](https://github.com/segin-GH/TDD-4-Embedded/tree/main/LedDriver).

#### What does an led driver do?
- The led driver controls 16 two-state LEDs.
- The driver can turn on/off the led's individual Led without affecting other LEDs.
- The driver can turn all LEDs on/off in one interface call.
- The user of the driver can query the state of the led.
- At power on the hardware default is for LEDs to be latched on. they must be turned off by the software.
- LEDs are memory mapped to a 16 but memory address.
- A 1-in-a-bit position lights the corresponding led on; 0 turn's it off.
- the LSB corresponds to Led 1; and the MSB corresponds to LEDs 16.

Before we start writing a module let's figure out what test we need.

#### Write a test list
It is helpful to create a test list before developing new functionality the test list is derived from the requirements. the list defines your best vision of what it means to be done. the list does not need to be perfect.  It is a temporary doc for what needs to be done, it can be written in notepad, I usually write it on the test file as a comment 
eg:-
```.c

/** @todo LED DRIVER TESTS 

*    TODO are all led's off after init
*    TODO a single led can be turned on
*    TODO a single led can be turned off
*    TODO Multiple led's can be turned off
*    TODO Multiple led's can be turned on
*    TODO Turn all led's on
*    TODO Turn all led's off
*    TODO Query Led state
*       TODO is led on
*       TODO is led off
*       TODO out-of-bound is on
*       TODO out-of-bound is off
*    TODO check boundary value
*       TODO beyond Max Breaks nothing
*       TODO under min breaks nothing
*       TODO provides RunTime error
        TODO what should really happen?
*/

``` 
One key point is that write test first and then let it fail, then write production code to pass the test. (hint **Fake it until you make it**) 
How will you make this function pass the test - **virtual led**
you just create a virtual led or hardcode the value, this can help you in two ways you can make your test pass and you don't need physical 
hardware connected to do unit tests.

First Test
```.c
TEST(LedDriver, are_all_the_led_off_after_init)
{
    uint16_t virtualLed = 0xffff;

    /* passing the virtualLed to the driver is use of dependency injection */
    ledDriverInit(&virtualLed);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLed);
}
```

this will fail because our `ledDriverInit` is not implemented.
```.c
void ledDriverInit(uint16_t *memoryMappedAddr)
{
    //
}
```

To make the test pass hardcode some value.
```.c
static  uint16_t *virtualLed;

void ledDriverInit(uint16_t *memoryMappedAddr)
{
    virtualLed = memoryMappedAddr;
    *virtualLed = 0;
}
```
that's it you just hard code the value and the test passes "hurray"
this may feel like a bit weird but believe me, this works the concept of __virtual leds__ 

#### Test-Drive the Interface Before the Internals
A good interface is critical for a well-designed module the first few tests drive the interface design the focus in the interface means that we're working from the outside of the code that is being developed to the inside. The test is the first user of the interface that gives the callers 
(or client code ) a perspective of how to use the code being developed. starting from the user's perspective leads to a more usable interface.

---
**Bob Martin's three Laws of TDD**

- Do not write production code unless it is to make a failing unit test pass.
- Do not write more of a unit test than is sufficient to fail, and build failures are failures
- Do not write more production code than is sufficient to pass the one failing unit test
---


#### Tests are FIRST
in _Agile in a Flash_ Tim Ottinger and Jeff langer tells five critical attributes of unit tests Tests need to be First to be most effective.

- **F**  ---   Fast: Tests are fast, so fast that developers run them with every small change without waits that break the flow.
-  **I**  ---  Isolated: Tests are isolated. One test does not set up the next test. Tests also isolate the failures
-  **R** --- Repeatable: Tests are repeatable; repeatable means automated test run in a loop always giving the same result
- **S** --- Self-verifying:  Test Verify their outcome, reporting a simple "OK" when they pass while providing concise detail when they fail.
- **T** --- Timely: Tests are timely. programmers write them just in time, in lock-step (but just before) the production code, preventing bugs.

### What is stub?
In software testing, a stub is a piece of code that stands in for some other programming functionality. It is often used in testing to simulate the behavior of a real piece of code that has not yet been implemented or is unavailable for use.

For example, consider a program that needs to communicate with a database to retrieve data. If the database is not yet available or if the database connection is not yet implemented, a stub could be used to simulate the behavior of the database connection and return dummy data in its place. This allows the rest of the program to be tested and debugged without having to rely on the actual database connection.

In the context of C programming, a stub is simply a C function that is written to stand in for some other function or piece of code. It can be used in a variety of testing scenarios to simulate the behavior of real code and allow for testing to proceed.

Here is an example of a stub function in C:
```.c
#include <stdio.h>

// Dummy function that stands in for a database connection
int connect_to_database(char* host, char* user, char* password) {
  // In a real implementation, this function would attempt to connect
  // to a database with the given host, user, and password.
  // For this example, we will just print a message and return 0.
  printf("Connecting to database...\n");
  return 0;
}

int main() {
  // Test the database connection stub
  int result = connect_to_database("localhost", "user", "password");
  printf("Result: %d\n", result);
  return 0;
}

```
In this example, the `connect_to_database` function is a stub that stands in for a real database connection. It simply prints a message and returns 0, simulating the behavior of a successful database connection. The `main` function calls the `connect_to_database` function and prints the result, which in this case would be 0.

Note that this is just a very simple example and a real stub function for a database connection would likely be much more complex and include more detailed simulation of the database connection process.

### what is mock in c test?
A mock is a type of test double (a simulated object used in place of a real object for testing purposes) that is used to mimic the behavior of a real object in a controlled way. In software testing, mocks are often used to simulate the behavior of complex, real-world objects and interactions in a controlled manner, allowing you to test the behavior of your code in isolation from external dependencies.

In the context of C programming, a mock is simply a C function or object that is written to mimic the behavior of a real function or object in a controlled way. It is often used in conjunction with stubs to create more comprehensive and robust tests.

Here is an example of a mock function in C:
```.c
#include <stdio.h>

// Mock function that stands in for a database connection
int connect_to_database(char* host, char* user, char* password) {
  // In a real implementation, this function would attempt to connect
  // to a database with the given host, user, and password.
  // For this example, we will just check the input values and return 0
  // if they are correct and -1 if they are incorrect.
  if (strcmp(host, "localhost") == 0 && strcmp(user, "user") == 0 && strcmp(password, "password") == 0) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  // Test the database connection mock
  int result = connect_to_database("localhost", "user", "password");
  printf("Result: %d\n", result);
  return 0;
}
```
In this example, the `connect_to_database` function is a mock that stands in for a real database connection. It checks the input values passed to it (the host, user, and password) and returns 0 if they are correct and -1 if they are incorrect. The `main` function calls the `connect_to_database` function and prints the result, which in this case would be 0.

Mock objects can be used to simulate a wide range of behaviors and interactions, allowing you to thoroughly test the behavior of your code in a variety of different scenarios.

#### what is Cmock?
CMock is a tool that is used to generate mock functions for use in unit testing in the C programming language. It is designed to make it easier to create mock functions that can be used to test the behavior of C code in isolation from external dependencies.

To use CMock, you provide it with a header file that declares the functions that you want to mock. CMock will then generate mock versions of those functions that can be used in your unit tests. The mock functions behave in a similar way to stubs, in that they stand in for the real functions and allow you to test the behavior of your code without actually calling the real functions. However, CMock takes this a step further by allowing you to specify the behavior of the mock functions in advance, including what they should return and how they should behave when called. This allows you to create more comprehensive and robust unit tests.

Here is an example of how you might use CMock to generate mock functions in a C project:

1.  First, create a header file that declares the functions that you want to mock. For example:

```.c
#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H

int connect_to_database(char* host, char* user, char* password);
int query_database(char* query);

#endif

```
2.  Next, run CMock on the header file to generate the mock functions. This will typically involve running a command like `cmock --mock=mock_functions.h`. This will generate a file called `mock_functions.c` that contains the mock versions of the functions declared in the header file.
    
3.  In your unit tests, include the generated `mock_functions.c` file and use the mock functions as needed. For example:
```.c
#include "mock_functions.h"

void test_database_connection() {
  // Test the database connection mock
  int result = connect_to_database("localhost", "user", "password");
  assert(result == 0);
}

int main() {
  test_database_connection();
  return 0;
}

```
In this example, the `connect_to_database` function is a mock function that was generated by CMock. It stands in for the real function and allows you to test the behavior of your code without actually calling the real function.

CMock is a powerful tool that can help you create more comprehensive and robust unit tests for your C code, making it easier to catch and fix bugs and ensure the quality of your software.


#### Executable Reminders

If you don't know how to test a function you can use something like an executable reminder, this will help you not to forget that you have one test pending.
`IGNORE_TEST` here is an example:-

```c
IGNORE_TEST(LedDriver, out_of_bound_value_produces_run_time_error)
{
    RUNTIME_ERROR("LED DRIVER: out-of-bounds LED",-1);

    ledDriverTurnON(-1);
    TEST_ASSERT_EQUAL_STRING("LED DRIVER: out-of-bounds LED",
         runTimeErrStub_getLastError());
    TEST_ASSERT_EQUAL(-1, runTimeErrStub_getLastParameter());
}
```
When you think you are done take a step back and look at your work and see whether
there is any cleanup that you need to do.  After a quick review, the production code looks clean; functions are short and focused names are readable and we got rid of magic numbers as we proceed.
How far to take the refactoring is a judgment call. The judgment should be based on detecting code smell and envisioning a better form for the code. 


## Embedded TDD Strategy

In the previous example shows how an [led driver](https://github.com/segin-GH/TDD-4-Embedded/tree/main/LedDriver) a hardware-dependent piece of code, is developed using TDD and tested off the target on the eval dev board you may wonder is this test even valid? when they are not even running on target hardware? the answer is they are valuable but along with benefits, some risks must be considered and contained.

Testing off the target hardware also allows difficult-to-cause errors to be easily injected without this ability, a lot of code goes untested until the fateful day when the hardware error we anticipate occurs but the corrective action is wrong.

#### The Target hardware bottleneck
Most of the time concurrent hardware and software development is a reality for many embedded projects if the software can only run on target you will likely suffer unnecessarily from one or more of these time wasters.
 - Target hardware is not ready until late in the project, delaying software testing.
 - Target hardware is expensive and scares This makes developers wait and build up mounds of unverified work.
 - when target hardware is finally ready it may have bugs of its own. the mound of untested software has its bugs too. Putting both of them together you get long days of debugging and plenty of finger-pointing.
 - Long target builds and long target uploads take a lot of time.

#### Dual-Targeting
Dual targeting means that from day one your code is designed to run on at least two platforms the final target and a dev board or
on a development system.
The goal is not some esoteric or academic pursuit; it is a pragmatic technique to keep development going at a steady pace.


#### Benefits of dual-targeting 

- When you try to run newly written software on your embedded platform you are tackling many unknowns simultaneously.  A problem on the board, the microcontroller circuitry, or connectors can masquerade as a software bug; there if you can isolate your software before running it in your embedded platform we can figure out whether is the software the culprit or if it is a hardware issue.
- It allows you to test the code before the hardware gets ready.
- You can avoid hardware bottlenecks.
- You can avoid simultaneous debugging of hardware and software.
- Hardware independency will remove some of the burdens in future platform migrations. 
- Hardware will change that's a given. When it does you better be prepared. having automated unit tests and code that already runs on multiple target platforms.

#### Risks of dual-targeting
- compilers may support different language features.
- The target compiler may have one set of bugs while the development-system has a different set of bugs.
- the runtime libraries may be different.
- the included file name and features may be different.
- Primitive data types might have different sizes.
- byte ordering and data structure alignments may be different.

### Testing with Hardware
- Automated hardware test.
- Partialy automated hardware test.
- Automated hardware tests with external Instruments.-

##### AUTOMATED HARDWARE TEST
Your embedded hardware will have areas that are well-suited for automated testing other areas of hardware will probably need a special instrument to test the hardware functionality where possible you should write a test that helps you learn what the hardware does and give you confidence that the hardware is working. These tests are automaticaly done.
##### PARTIALLY AUTOMATED HARDWARE TEST
The ledDriver example shows how a hardware-dependent code can be tested outside of the target but how do you know it turns on the right led? this is a good example where we can do a partially automated test in partially automated test displays a cue prompting the operator to manually interact with the system output, in this case, we would verify that a specific LED is either on or off this would be reapeted with every led.  this could also be part of the builtin test that can be shipped with the product.


##### AUTOMATED HARDWARE TEST WITH EXTERNAL INSTRUMENTS
These kinds of tests are done with external instruments like function generators so rather than manually pressing buttons to test the device using the full capability of the device by using its Serial port to automatically send data can be good when we have to do repetitive work this can be useful since humans tend to make errors all the time.



## Introducing Test Doubles

### Collaborators
A collaborator is some function, data, module, or device outside the code under test (CUT) that the (CUT) depends upon.
### Test Doubles
A test double impersonates some function, data, module, or a lib during a test the CUT does not know it is using a test double.

### When to use a Test double
* hardware independence.
* inject difficult-to-produce inputs.
* speed up a slow collaborator.
* Dependency on something volatile (eg clock).
* Dependency on something under development.
* Dependency on something difficult to configure.
