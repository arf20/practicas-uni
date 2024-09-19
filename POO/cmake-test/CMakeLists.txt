cmake_minimum_required(VERSION 3.10)
project(cmake-test)

find_package(Java 17)
include(UseJava)

file(GLOB SRC
	"src/testpackage/test.java"
)

add_jar(test ${SRC} ENTRY_POINT testpackage.test)

