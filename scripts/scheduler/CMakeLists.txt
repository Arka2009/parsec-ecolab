cmake_minimum_required(VERSION 3.0.2)
project(date2019_scheduler)
set(CMAKE_BUILD_TYPE Release)
 
#Bring the headers
include_directories(include)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")
 
#Buid products
add_executable(sched ${SOURCES})
 
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
#install(TARGETS ecoaffine DESTINATION /usr/lib)
