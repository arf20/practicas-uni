JAVAC := javac
JFLAGS :=

all: server.jar client.jar

server.jar: build/Server.class build/ServerThread.class
	jar -c -f build/Server.jar --main-class Server -C build . #Server.class ServerThread.class

client.jar: build/Client.class
	jar -c -f build/Client.jar --main-class Client -C build Client.class

build:
	mkdir build

build/Server.class build/ServerThread.class: Server.java build
	javac -d build/ Server.java

build/Client.class: Client.java build
	javac -d build/ Client.java

.PHONY: clean
clean:
	rm -rf build


