JAVAC := javac
JFLAGS := -cp json.jar -d build/

all: server.jar client.jar

server.jar: build/Server.class build/ServerThread.class build/org/json/JSONObject.class
	jar -c -f build/server.jar --main-class Server -C build . #Server.class ServerThread.class

client.jar: build/Client.class build/org/json/JSONObject.class
	jar -c -f build/client.jar --main-class Client -C build .

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


