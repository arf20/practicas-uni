cmake_minimum_required(VERSION 3.10)

project(sesion1)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"src/geometria/Punto.java"
	"src/geometria/Circulo.java"
	"src/pruebas/PruebaPunto.java"
	"src/pruebas/PruebaCirculo.java"
)

add_jar(sesion1 ${SRC} ENTRY_POINT pruebas.PruebaCirculo)

