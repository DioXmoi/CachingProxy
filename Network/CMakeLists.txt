

# —оздаЄм статическую библиотеку 'network'
add_library(Network 
			Listener.cpp 
			Session.cpp 
			Logger.cpp)


# ”казываем, где лежат заголовки (публичные)
target_include_directories(Network PUBLIC 
						   ${CMAKE_CURRENT_SOURCE_DIR}
						   ${Boost_INCLUDE_DIRS}
						   "${CMAKE_CURRENT_SOURCE_DIR}/Cache"
						   )

# ”казываем зависимость от Cache через им€ библиотеки
target_link_libraries(Network PUBLIC Cache)