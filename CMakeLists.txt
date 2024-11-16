cmake_minimum_required(VERSION 3.16)

project(figure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(figure main.cpp
    figure.cc
    figure.hh
    point_couleur.cc
    point_couleur.hh
    carte.cc
    carte.hh
    element.cc
    element.hh
    taillePosition.cc
    taillePosition.hh
    objetramassable.cc
    objetramassable.hh
    obstacle.cc
    obstacle.hh
    personnage.cc
    personnage.hh
)

include(GNUInstallDirs)
install(TARGETS figure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
