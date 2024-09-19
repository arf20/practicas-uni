cmake_minimum_required(VERSION 3.10)
project(banco)

find_package(Java 17)
include(UseJava)

file (GLOB SRC
    "banco/productos/Cuenta.java"
    "banco/pruebas/Banco.java"
)

add_jar(banco ${SRC} ENTRY_POINT banco.pruebas.Banco)

