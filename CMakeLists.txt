cmake_minimum_required(VERSION 3.10)
project(CollegeFootballInventory)

set(CMAKE_CXX_STANDARD 17)

add_executable(inventory
    src/InventorySystem.cpp
    src/main.cpp
)

# Testing (optional)
enable_testing()
find_package(GTest REQUIRED)
add_executable(test_inventory tests/test_inventory.cpp)
target_link_libraries(test_inventory GTest::GTest)
add_test(NAME InventoryTest COMMAND test_inventory)