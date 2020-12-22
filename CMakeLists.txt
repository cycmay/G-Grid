cmake_minimum_required(VERSION 3.17)
project(_G_Grid)

set(CMAKE_CXX_STANDARD 11)

add_executable(_G_Grid main.cpp GraphGrid.cpp GraphGrid.h Cell.cpp Cell.h Vertex.cpp Vertex.h Edge.cpp Edge.h ObjectTable.cpp ObjectTable.h MessageList.cpp MessageList.h Index.cpp Index.h)