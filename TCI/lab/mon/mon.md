# Practica monitor

## Setup

sudo iw phy phy0 interface add mon0 type monitor
sudo ip link set mon0 up
sudo iw dev mon0 set channel 36 ht20

### PLCP

data rate: 1Mb/s



