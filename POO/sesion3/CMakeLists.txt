cmake_minimum_required(VERSION 3.10)

project(sesion3)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/geometria/Punto.java"
	"src/geometria/Point.java"
	"src/geometria/Direction.java"
	"src/geometria/Rectangulo.java"
	"src/pruebas/PruebaPunto.java"
)

add_jar(sesion3 ${SRC} ENTRY_POINT pruebas.PruebaPunto)

