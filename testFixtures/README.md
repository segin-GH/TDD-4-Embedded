## Flowchart

```mermaid
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#0000', 'edgeLabelBackground':'#ffffee','fontSize':'20px', 'tertiaryColor': '#fff0f0'}}}%%

graph TD

UNITY_MAIN_FUNC --> run_all_tests
run_all_tests --> RUN_TEST_GROUP
RUN_TEST_GROUP --> TEST_GROUP_RUNNER
TEST_GROUP_RUNNER --> RUN_TEST_CASE
RUN_TEST_CASE --> TEST_1
TEST_1 --> TEST_SETUP
TEST_1 --> TEST_TEAR_DOWN
TEST_1 --> TEST

```
