cmake_minimum_required(VERSION 3.1.0) #2.8.9)
project(sand_table)
 
#Bring the headers into the project
include_directories(include)
 
#Link pthreads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#Link wiringPi
find_package(WiringPi REQUIRED)
include_directories(${WIRINGPI_INCLUDE_DIRS})

#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp src/Table.cpp src/Motor.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(sand_table ${SOURCES})

target_link_libraries(sand_table PRIVATE Threads::Threads)
target_link_libraries(sand_table ${WIRINGPI_LIBRARIES})