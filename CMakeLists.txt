cmake_minimum_required(VERSION 3.0.0)
project(Proyecto-JTC VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Proyecto-JTC main.cpp Escenario.h Escenario.cpp Jugador.h Jugador.cpp Obstaculo.h Obstaculo.cpp ObsArbol.h ObsArbol.cpp ObsCarro.h ObsCarro.cpp Poder.h Poder.cpp PoderInvenci.h PoderInvenci.cpp PoderDisTri.h PoderDisTri.cpp PoderCorazon.h PoderCorazon.cpp Proyectiles.cpp Proyectiles.h Tanque.h Tanque.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
