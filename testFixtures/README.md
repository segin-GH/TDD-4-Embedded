## Flowchart

```mermaid
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#0000', 'edgeLabelBackground':'#ffffee','fontSize':'20px', 'tertiaryColor': '#000000'}}}%%

graph LR
A[app_main] -- Calls --> B[run_all_tests]
B -- calls --> C[TEST_1]
C -- calls --> D[TEST_1_SETUP]
C -- calls --> E[noFormatOperation]
C -- calls --> F[insertString]
C -- calls --> G[TEST_1_TEAR_DOWN]

```
