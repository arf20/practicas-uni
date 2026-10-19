#!/bin/bash

ip route add 192.168.123.0/24 via 10.0.1.200
tail -f /dev/null
