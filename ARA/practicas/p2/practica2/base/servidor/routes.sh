#!/bin/bash

ip route add 176.3.2.0/24 via 180.2.3.220

/usr/sbin/apache2ctl start

tail -f /dev/null
