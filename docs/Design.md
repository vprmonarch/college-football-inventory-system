# Design Decisions

## Core Improvements
1. **Memory Management**
   - Replaced raw pointers with `std::unique_ptr`
   - Used `std::vector` for dynamic storage

2. **Bug Fixes**
   - Fixed zero-quantity item memory leak
   - Added proper input validation

3. **Performance**
   - Used STL algorithms (`std::find_if`)
   - Reduced unnecessary copies

## Trade-offs
- Used `std::unique_ptr` instead of `std::shared_ptr` since ownership is strictly with Inventory
- Trade memory efficiency for cleaner code (vector vs linked list)