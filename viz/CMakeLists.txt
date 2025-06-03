cmake_minimum_required(VERSION 3.16)
project(viz)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Libraries/SFML-3.0.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(viz 
    viz.cpp 
    "C:/Visual Studio/SD_proj3/DataStructures_HashTableDictionary/src/dictionary_avl.cpp"
    "C:/Visual Studio/SD_proj3/DataStructures_HashTableDictionary/src/avl_tree.cpp"
)

target_link_libraries(viz
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
