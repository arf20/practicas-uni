JAVAC := javac
JFLAGS := -cp gson-2.15.0.jar -d build/

all: server.jar client.jar

server.jar: build/Server.class build/ServerThread.class build/com/google/gson/Gson.class
	jar -c -f build/server.jar --main-class Server -C build . #Server.class ServerThread.class

client.jar: build/Client.class build/com/google/gson/Gson.class
	jar -c -f build/client.jar --main-class Client -C build .

build/com/google/gson/Gson.class: gson-2.15.0.jar
	cd build && jar xf ../gson-2.15.0.jar

build:
	mkdir build

build/Server.class build/ServerThread.class: Server.java build
	javac $(JFLAGS) Server.java

build/Client.class: Client.java build
	javac $(JFLAGS) Client.java

.PHONY: clean
clean:
	rm -rf build


