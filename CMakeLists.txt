cmake_minimum_required(VERSION 3.26)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp
        scripts/Paddle.cpp
        scripts/Paddle.h
        scripts/GameBackGround.cpp
        scripts/Block.h
        scripts/Block.h
        scripts/Block.cpp
        scripts/Ball.h
        scripts/Ball.cpp
        scripts/Menu.cpp
        scripts/Menu.h
        scripts/Button.h
        scripts/Button.cpp
        scripts/HoverAndClickMainMenuButtons.h
        scripts/HoverAndClickMainMenuButtons.cpp
        scripts/LevelSelect.h
        scripts/LevelSelect.cpp
        scripts/HoverAndClickLevelSelectButtons.cpp
        scripts/HoverAndClickLevelSelectButtons.h
        scripts/showResultScreen.cpp
        scripts/showResultScreen.h
        scripts/showBackToLevelsButton.cpp
        scripts/showBackToLevelsButton.h
        scripts/showRestartLevelButton.cpp
        scripts/showRestartLevelButton.h
        scripts/showSettings.cpp
        scripts/showSettingsScreen.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(c:/SFML/include)
target_link_libraries(project sfml-system sfml-window sfml-graphics sfml-audio)