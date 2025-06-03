cmake_minimum_required(VERSION 3.16)
project(viz)

set(CMAKE_CXX_STANDARD 17)

# Путь до SFMLConfig.cmake
set(SFML_DIR "C:/Libraries/SFML-3.0.0/lib/cmake/SFML")

# Вызов с конкретными компонентами (новыми!)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(viz viz.cpp)

# Линковка с интерфейсными целями
target_link_libraries(viz
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
