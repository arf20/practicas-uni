all:
	arduino-cli compile -b arduino:avr:uno prac1.ino
	arduino-cli upload prac1.ino -p /dev/ttyACM3 -b arduino:avr:uno
	arduino-cli monitor -p /dev/ttyACM3

