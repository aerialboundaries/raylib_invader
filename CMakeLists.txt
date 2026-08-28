cmake_minimum_required(VERSION 3.20)

project(MyRaylibGame VERSION 1.0.0 LANGUAGES C)

# C標準規格の設定
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# w64devkit のインクルードディレクトリとライブラリディレクトリの定義
set(W64DEVKIT_DIR "C:/raylib/w64devkit")
set(W64DEVKIT_INCLUDE_DIR "${W64DEVKIT_DIR}/include")
set(W64DEVKIT_LIB_DIR "${W64DEVKIT_DIR}/lib")

# カレントディレクトリ内のすべての .c ファイルを自動的に取得
file(GLOB SOURCES "*.c")

# 実行ファイルの定義
add_executable(my_game ${SOURCES})

# 自身のディレクトリおよび w64devkit の include を追加
target_include_directories(my_game PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${W64DEVKIT_INCLUDE_DIR}
)

# raylibや依存ライブラリのリンク指定
target_link_directories(my_game PRIVATE ${W64DEVKIT_LIB_DIR})
target_link_libraries(my_game PRIVATE 
    raylib 
    opengl32 
    gdi32 
    winmm
)

# コンパイル警告オプション
target_compile_options(my_game PRIVATE -Wall -Wextra -Wpedantic)