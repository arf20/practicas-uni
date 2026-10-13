JAVAC := javac
JFLAGS := -cp json.jar -d build/

all: server.jar client.jar

server.jar: build/Server.class build/ServerThread.class build/org/json/JSONObject.class
	jar -c -f build/Server.jar --main-class Server -C build . #Server.class ServerThread.class

client.jar: build/Client.class build/org/json/JSONObject.class
	jar -c -f build/Client.jar --main-class Client -C build Client.class

build/org/json/JSONObject.class: json.jar
	cd build && jar xf ../json.jar

build:
	mkdir build

build/Server.class build/ServerThread.class: Server.java build
	javac $(JFLAGS) Server.java

build/Client.class: Client.java build
	javac $(JFLAGS) Client.java

.PHONY: clean
clean:
	rm -rf build


