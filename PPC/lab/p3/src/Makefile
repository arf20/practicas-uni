JAVAC := javac
JFLAGS := -cp gson-2.15.0.jar:javax.mail.jar:javax.activation.jar -d build/ -Xlint:deprecation

all: server.jar client.jar

server.jar: build/Server.class build/com/google/gson/Gson.class
	jar -c -f server.jar --main-class Server -C build . #Server.class ServerThread.class

client.jar: build/Client.class build/com/google/gson/Gson.class build/javax/mail/Version.class build/javax/activation/MimeType.class
	jar -c -f client.jar --main-class Client -C build .

build/com/google/gson/Gson.class: gson-2.15.0.jar
	cd build && jar xf ../gson-2.15.0.jar

build/javax/mail/Version.class: javax.mail.jar
	cd build && jar xf ../javax.mail.jar

build/javax/activation/MimeType.class: javax.activation.jar
	cd build && jar xf ../javax.activation.jar

build:
	mkdir build

build/Server.class: Server.java build
	javac $(JFLAGS) Server.java

build/Client.class: Client.java build
	javac $(JFLAGS) Client.java

.PHONY: clean
clean:
	rm -rf build


