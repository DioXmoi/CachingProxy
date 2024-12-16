cmake_minimum_required (VERSION 3.10)


project ("CachingProxy" VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings to the source code
configure_file(CachingProxyConfig.h.in CachingProxyConfig.h)


add_subdirectory(CommandLine)


# Указываем CMake, где искать модули конфигурации.
if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64-bit
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../boost_1_86_0/bin/x64/lib/cmake/")
    message(STATUS "Building for 64-bit architecture")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4) # 32-bit
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../boost_1_86_0/bin/x86/lib/cmake/")
    message(STATUS "Building for 32-bit architecture")
else()
    message(FATAL_ERROR "Unsupported architecture")
endif()

# Находим пакет Boost, требуя программу options.
find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(CachingProxy CachingProxy.cpp) 

if(Boost_FOUND)
  # Связываем вашу цель с программой options.
  target_link_libraries(CachingProxy PUBLIC Boost::program_options)
else()
  message(FATAL_ERROR "Boost Program Options library not found. Please make sure Boost is installed and configured properly for CMake.")
endif()


target_link_libraries(CachingProxy PUBLIC CommandLine)

target_include_directories(CachingProxy PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/CommandLine"
                          )