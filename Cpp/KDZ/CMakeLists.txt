cmake_minimum_required(VERSION 3.12.3)
project(KDZ)

set(CMAKE_CXX_STANDARD 14)

add_executable(KDZ main.cpp Vertex.h EdmondsKarpVertex.cpp EdmondsKarpVertex.h FordFulkersonVertex.cpp FordFulkersonVertex.h DinicVertex.cpp DinicVertex.h muTimer.cpp Diniz.cpp Diniz.h EdmondsKarp.cpp EdmondsKarp.h FordFulkerson.cpp FordFulkerson.h)