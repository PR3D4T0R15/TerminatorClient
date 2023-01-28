cmake_minimum_required(VERSION 3.20)

project("TerminatorClient" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## QT ##
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (WIN32) 
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
elseif(UNIX)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

######## QT PACKAGES ########
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)

qt_standard_project_setup()
######## END ########

## DIR SETUP ##
set(resources_DIR "${CMAKE_SOURCE_DIR}/resources")
set(forms_DIR "${CMAKE_SOURCE_DIR}/forms")
set(include_DIR "${CMAKE_SOURCE_DIR}/include")
set(source_DIR "${CMAKE_SOURCE_DIR}/source")


include_directories(${resources_DIR})
include_directories(${forms_DIR})
include_directories(${include_DIR})
include_directories(${source_DIR})


file(GLOB_RECURSE SOURCES
    "${resources_DIR}/img/*.png"
    "${resources_DIR}/*.qrc"

    "${forms_DIR}/*/*.cpp"
    "${forms_DIR}/*/*.h"
    "${forms_DIR}/*/*.ui"

    "${include_DIR}/*.h"
    "${source_DIR}/*.cpp"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${forms_DIR})


## EXECUTABLE ##
if (WIN32) 
    add_executable("${PROJECT_NAME}" WIN32 ${SOURCES})
    #add_executable(TerminatorClient ${SOURCES})
elseif(UNIX)
    add_executable("${PROJECT_NAME}" ${SOURCES})
endif()

## TARGET INCLUDE ##
target_include_directories(${PROJECT_NAME} PRIVATE ${img_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${networkClass_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${loginWindow_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${newUser_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${mainWindow_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${dialogSelectUser_DIR})

######## LINK LIBRARIES ########
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Network)
######## END ########