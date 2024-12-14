cmake_minimum_required (VERSION 3.10)


project ("CachingProxy" VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings to the source code
configure_file(CachingProxyConfig.h.in CachingProxyConfig.h)

include_directories("../boost_1_86_0")

add_executable(CachingProxy CachingProxy.cpp) 

target_include_directories(CachingProxy PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          )

if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64-bit
    target_link_libraries(CachingProxy "../boost_1_86_0/bin/x64/lib")
    message(STATUS "Building for 64-bit architecture")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4) # 32-bit
    target_link_libraries(CachingProxy "../boost_1_86_0/bin/x86/lib")
    message(STATUS "Building for 32-bit architecture")
else()
    message(FATAL_ERROR "Unsupported architecture")
endif()