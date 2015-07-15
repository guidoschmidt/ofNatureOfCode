project(ofxNOC-1.10-PerlinLandscape)
set(APP ofxNOC-1.10-PerlinLandscape)

cmake_minimum_required(VERSION 2.8)

include(../../of/openFrameworks.cmake)

ofxaddon(ofxGui)
ofxaddon(ofxMSAPerlin)

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
    src/RandomWalker.cpp
    src/Generator.cpp
)

add_executable(
    ${APP}
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_link_libraries(
    ${APP}
    ${OPENFRAMEWORKS_LIBRARIES}
)

cotire(${APP})
