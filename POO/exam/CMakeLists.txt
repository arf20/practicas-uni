cmake_minimum_required(VERSION 3.10)

project(exam)

find_package(Java)
include(UseJava)

file(GLOB SRC
	"*.java"
)

add_jar(exam ${SRC} ENTRY_POINT Programa)
