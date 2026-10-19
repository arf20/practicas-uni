#!/bin/bash

ip route add 10.0.1.0/24 via 192.168.123.100

/usr/sbin/apache2ctl start

tail -f /dev/null
