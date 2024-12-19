# —оздаЄм статическую библиотеку 'cache'
add_library(Cache Cache.cpp)

# ”казываем, где лежат заголовки (публичные)
target_include_directories(Cache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})