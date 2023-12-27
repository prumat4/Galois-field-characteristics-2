add_library(GaloisFieldNormal
    GaloisFieldNormal.cpp
)

target_include_directories(GaloisFieldNormal
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)