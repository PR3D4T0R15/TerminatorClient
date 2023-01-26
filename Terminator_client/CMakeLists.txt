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
    #set(CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

######## QT PACKAGES ########
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)

qt_standard_project_setup()
######## END ########

## DIR SETUP ##
set(img_DIR "${CMAKE_SOURCE_DIR}/src/img")
set(networkClass_DIR "${CMAKE_SOURCE_DIR}/src/networkClass")

set(loginWindow_DIR "${CMAKE_SOURCE_DIR}/src/loginWindow")
set(newUser_DIR "${CMAKE_SOURCE_DIR}/src/newUser")
set(mainWindow_DIR "${CMAKE_SOURCE_DIR}/src/mainWindow")
set(dialogSelectUser_DIR "${CMAKE_SOURCE_DIR}/src/dialogSelectUser")

include_directories(${img_DIR})
include_directories(${networkClass_DIR})
include_directories(${loginWindow_DIR})
include_directories(${newUser_DIR})
include_directories(${mainWindow_DIR})
include_directories(${dialogSelectUser_DIR})

file(GLOB_RECURSE SOURCES
    "${img_DIR}/*.png"
    "${networkClass_DIR}/*.h"
    "${networkClass_DIR}/*.cpp"
    "${networkClass_DIR}/*.ui"

    "${loginWindow_DIR}/*.h"
    "${loginWindow_DIR}/*.cpp"
    "${loginWindow_DIR}/*.ui"

    "${newUser_DIR}/*.h"
    "${newUser_DIR}/*.cpp"
    "${newUser_DIR}/*.ui"

    "${mainWindow_DIR}/*.h"
    "${mainWindow_DIR}/*.cpp"
    "${mainWindow_DIR}/*.ui"

    "${dialogSelectUser_DIR}/*.h"
    "${dialogSelectUser_DIR}/*.cpp"
    "${dialogSelectUser_DIR}/*.ui"

    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/*.qrc"
)




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