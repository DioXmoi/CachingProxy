

# ������ ����������� ���������� 'network'
add_library(Network 
			Listener.cpp 
			Session.cpp 
			Logger.cpp)


# ���������, ��� ����� ��������� (���������)
target_include_directories(Network PUBLIC 
						   ${CMAKE_CURRENT_SOURCE_DIR}
						   ${Boost_INCLUDE_DIRS}
						   "${CMAKE_CURRENT_SOURCE_DIR}/Cache"
						   )

# ��������� ����������� �� Cache ����� ��� ����������
target_link_libraries(Network PUBLIC Cache)