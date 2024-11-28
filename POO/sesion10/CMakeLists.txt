cmake_minimum_required(VERSION 3.10)

project(sesion10)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/*.java"
)

add_jar(sesion10 ${SRC} ENTRY_POINT Programa)

