add_library(GaloisFieldPoly
    GaloisFieldPoly.cpp
)

target_include_directories(GaloisFieldPoly
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)