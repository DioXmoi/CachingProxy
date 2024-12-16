


add_library(CLI ConsoleCommand.cpp CommandLineOptions.cpp)

find_package(Boost REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
  target_link_libraries(CLI PUBLIC Boost::program_options)
else()
  message(FATAL_ERROR "Boost Program Options library not found. Please make sure Boost is installed and configured properly for CMake.")
endif()