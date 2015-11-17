cmake_minimum_required (VERSION 2.6)
project (examples)

set(MS_LIBS "gdi32.lib comdlg32.lib user32.lib kernel32.lib opengl32.lib shell32.lib zlibstatic.lib libpng15_static.lib")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../nana/include)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/nana/ ${CMAKE_BINARY_DIR}/zlib-1.2.8 ${CMAKE_BINARY_DIR}/lpng158)

add_executable(homepage homepage.cpp)
add_executable(helloworld helloworld.cpp)
add_executable(notepad notepad.cpp)
add_executable(calculator calculator.cpp)
add_executable(widget_show widget_show.cpp)

TARGET_LINK_LIBRARIES(homepage nana.lib ${MS_LIBS})
TARGET_LINK_LIBRARIES(helloworld nana.lib ${MS_LIBS})
TARGET_LINK_LIBRARIES(notepad nana.lib ${MS_LIBS})
TARGET_LINK_LIBRARIES(calculator nana.lib ${MS_LIBS})
TARGET_LINK_LIBRARIES(widget_show nana.lib ${MS_LIBS})
