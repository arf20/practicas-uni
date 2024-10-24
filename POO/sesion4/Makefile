PROJECT := maquinas

JAR := jar
JAVAC := javac
JAVAFLAGS := 

SRC := $(wildcard src/maquinas/*.java)
#CLASS := class/maquinas/Moneda.class class/maquinas/Monedero.class

all: test

test: $(PROJECT).jar
	java -jar $(PROJECT).jar

$(PROJECT).jar: classes
	$(JAR) -cf $(PROJECT).jar maquinas/ META-INF/

.PHONY: classes
classes: maquinas/ $(SRC)
	$(JAVAC) -d . $(SRC)

maquinas/:
	mkdir -p maquinas/

.PHONY: clean
clean:
	rm -rf maquinas
	rm *.jar
	