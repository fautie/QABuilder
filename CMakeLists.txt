cmake_minimum_required(VERSION 3.10)

project(QABuilder VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/3rdparty/texcaller/texcaller.c
)
add_executable(QABuilder ${SOURCES})

add_subdirectory(3rdparty/drogon)
target_link_libraries(${PROJECT_NAME} PRIVATE drogon)

include_directories(3rdparty/texcaller)

aux_source_directory(${SRC_DIR}/db MODEL_SRC)
aux_source_directory(${SRC_DIR}/utils UTILS_SRC)
aux_source_directory(${SRC_DIR}/controllers CONTROLLER_SRC)
aux_source_directory(${SRC_DIR}/filters FILTER_SRC)
target_sources(${PROJECT_NAME} PRIVATE ${SRC_DIR}
                                       ${MODEL_SRC}
                                       ${CONTROLLER_SRC}
                                       ${UTILS_SRC}
                                       ${FILTER_SRC} )