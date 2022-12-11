## Flowchart

```mermaid
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#0000', 'edgeLabelBackground':'#ffffee','fontSize':'20px', 'tertiaryColor': '#fff0f0'}}}%%

graph LR
A[app_main] -- Calls --> B[run_all_tests]
B -- Calls --> C[TEST_1]
C -- 1 --> D[TEST_1_SETUP]
C -- 2 --> E[noFormatOperation]
C -- 3 --> F[insertString]
C -- 4 --> G[TEST_1_TEAR_DOWN]

```
