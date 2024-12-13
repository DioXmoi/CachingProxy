cmake_minimum_required (VERSION 3.10)


project ("CachingProxy" VERSION 1.0)


add_library(caching_proxy_compiler_flags INTERFACE)


target_compile_features(caching_proxy_compiler_flags INTERFACE cxx_std_20)

# configure a header file to pass some of the CMake settings to the source code
configure_file(CachingProxyConfig.h.in CachingProxyConfig.h)


# add the executable
add_executable(CachingProxy CachingProxy.cpp)


target_link_libraries(CachingProxy PUBLIC caching_proxy_compiler_flags)


#It is necessary to find CachingProxyConfig.h
target_include_directories(CachingProxy PUBLIC 
                          "${PROJECT_BINARY_DIR}"
)