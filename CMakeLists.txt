cmake_minimum_required(VERSION 3.17)
project(ChallongeLib)

set(CMAKE_CXX_STANDARD 17)

add_library(
	ChallongeLib
	src/Exceptions.hpp
	src/Socket.hpp
	src/Socket.cpp
	src/SecuredSocket.hpp
	src/SecuredSocket.cpp
	src/Client.cpp
	src/Client.hpp
	src/Tournament.cpp src/Tournament.hpp src/Time.cpp src/Time.hpp src/JsonUtils.cpp src/JsonUtils.hpp src/Match.cpp src/Match.hpp src/Participant.cpp src/Participant.hpp)

target_link_libraries(ChallongeLib crypto ssl ws2_32)

add_executable(test test/main.cpp)
target_include_directories(test PRIVATE src)
target_compile_definitions(test PRIVATE USERNAME="${USERNAME}" PASSWD="${PASSWD}")
target_link_libraries(test ChallongeLib)