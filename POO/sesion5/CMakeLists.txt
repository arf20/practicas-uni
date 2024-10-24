cmake_minimum_required(VERSION 3.10)

project(sesion5)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/subastas/*.java"
)

add_jar(sesion5 ${SRC} ENTRY_POINT subastas.Programa)

