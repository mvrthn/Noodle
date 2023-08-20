cmake_minimum_required(VERSION 3.18.4)
project(Noodle)

file(GLOB main_files "./src/*.cpp" "./src/*.hpp") 
file(GLOB flavors_files "./src/Flavors/*.cpp" "./src/Flavors/*.hpp")
file(GLOB ingredinets_files "./src/Ingredients/*.hpp")
file(GLOB specials_files "./src/Specials/*.hpp")

add_executable(Noodle ${main_files} ${flavors_files} ${ingredinets_files} ${specials_files})