

The folder structure
```
.
├── CMakeLists.txt
├── components
│   ├── ledDriver
│   │   ├── CMakeLists.txt
│   │   ├── include
│   │   │   └── ledDriver.h
│   │   ├── ledDriver.c
│   │   └── test
│   │       ├── CMakeLists.txt
│   │       └── test_ledDriver.c
│   ├── runTimeErr
│   │   ├── CMakeLists.txt
│   │   ├── include
│   │   │   └── runTimeErr.h
│   │   └── runTimeErr.c
│   └── runTimeErrStub
│       ├── CMakeLists.txt
│       ├── include
│       │   └── runTimeErrStub.h
│       └── runTimeErrStub.c
├── main
│   ├── CMakeLists.txt
│   └── main.c
├── README.md
├── sdkconfig
└── test
    ├── CMakeLists.txt
    ├── main
    │   ├── CMakeLists.txt
    │   └── test_runner_main.c
    ├── sdkconfig
    └── sdkconfig.defaults

```
