# ������ ����������� ���������� 'cli'
add_library(CLI CommandLineOptions.cpp ConsoleCommand.cpp)

# ���������, ��� ����� ��������� (���������)
target_include_directories(CLI PUBLIC 
						   ${CMAKE_CURRENT_SOURCE_DIR}
						   ${Boost_INCLUDE_DIRS}
						  )