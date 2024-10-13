PROJECT := maquinas

JAR := jar
JAVAC := javac
JAVAFLAGS := 

SRC := $(wildcard src/maquinas/*.java)
CLASS := class/maquinas/Moneda.class class/maquinas/Monedero.class

all: test

test: $(PROJECT).jar
	java -jar $(PROJECT).jar

$(PROJECT).jar: classes
	$(JAR) -cf $(PROJECT).jar class/* META-INF/

.PHONY: classes
classes: class/maquinas/ $(SRC)
	$(JAVAC) -d class/maquinas/ $(SRC)

class/maquinas/:
	mkdir -p class/maquinas/

.PHONY: clean
clean:
	rm -rf class
	rm *.jar
	