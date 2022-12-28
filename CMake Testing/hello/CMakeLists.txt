cmake_minimum_required(VERSION 3.11-3.18)

project(hello)
add_library(hello src/hello.cpp)
target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_compile_features(hello PUBLIC cxx_std_20)