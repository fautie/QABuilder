set(TEXCALLER_BASEDIR ${CMAKE_SOURCE_DIR}/3rdparty/texcaller)

include_directories(${TEXCALLER_BASEDIR})

set(TEXCALLER_SOURCES
    ${TEXCALLER_BASEDIR}/texcaller.c
    )


set(TEXCALLER_LIBRARY texcaller)
add_library(texcaller STATIC ${TEXCALLER_SOURCES})
target_compile_definitions(${TEXCALLER_LIBRARY} PRIVATE
    -D__STATIC=static)
target_link_libraries(${PROJECT_NAME} ${TEXCALLER_LIBRARY})
