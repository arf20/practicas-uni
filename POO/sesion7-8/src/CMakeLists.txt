cmake_minimum_required(VERSION 3.10)

project(sesion7-8)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/*.java"
)

add_jar(sesion7-8 ${SRC} ENTRY_POINT Programa)

