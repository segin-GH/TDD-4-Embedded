cmake_minimum_required(VERSION 3.5)

# Include the components directory of the main application:
#
set(EXTRA_COMPONENT_DIRS "../components")

# Set the components to include the tests for.
# This can be overriden from CMake cache:
# - when invoking CMake directly: cmake -D TEST_COMPONENTS="xxxxx" ..
# - when using idf.py: idf.py -T xxxxx build
#
set(TEST_COMPONENTS "wifi_connect" CACHE STRING "wrapper componet for wifi")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(wifiConnect_wrapper_test)