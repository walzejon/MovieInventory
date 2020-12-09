cmake_minimum_required(VERSION 3.13)  # CMake version check
project(MovieInventory)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(store.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(movie.h movie.cpp drama.h comedy.h classic.h store.h store.cpp transaction.h
        data4commands.txt data4customers.txt data4movies.txt hashtable.h hashtable.cpp customer.h customer.cpp
        comedy.h comedy.cpp drama.h drama.cpp return.h bintree.h bintree.cpp borrow.h classic.cpp borrow.h borrow.cpp
        return.h return.cpp "transaction.cpp" "history.h" "history.cpp")
#add_executable(hashtable.cpp hashtable.h customer.cpp customer.h transaction.h)