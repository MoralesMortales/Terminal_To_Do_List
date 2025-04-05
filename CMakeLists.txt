cmake_minimum_required(VERSION 3.10)
project(ToDoList_cpp VERSION 1.0.0 LANGUAGES CXX)

# Configuración estándar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # Para herramientas de análisis de código

# Configuración de warnings
if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Fuentes y cabeceras (mejor práctica: listado explícito)
set(SOURCES 
main.cpp
    src/menu.cpp
    src/fileConfig.cpp
    src/toDoAction.cpp
)

set(HEADERS
    include/menu.h
    include/fileConfig.h
    include/toDoAction.h
)

# Ejecutable principal
add_executable(ToDoApp ${SOURCES} ${HEADERS})

# Directorios de inclusión (versión moderna)
target_include_directories(ToDoApp 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Instalación (con rutas estándar)
include(GNUInstallDirs)
install(TARGETS ToDoApp
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ToDoList_cpp
    PATTERN "*.h"  # Solo instala archivos .h
)
