# ������ ����������� ���������� 'cache'
add_library(Cache Cache.cpp)

# ���������, ��� ����� ��������� (���������)
target_include_directories(Cache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})