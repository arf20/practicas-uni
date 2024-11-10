cmake_minimum_required(VERSION 3.10)

project(ejerciciocursos)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/cursos/*.java"
)

add_jar(ejerciciocursos ${SRC} ENTRY_POINT cursos.Programa)

