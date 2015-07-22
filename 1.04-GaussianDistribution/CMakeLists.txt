project(ofxNOC-1.4-GaussianDistribution)
set(APP ofxNOC-1.4-GaussianDistribution)

cmake_minimum_required(VERSION 2.8)

include(../../of/openFrameworks.cmake)

ofxaddon(ofxGui)

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
