# Practica monitor

## Setup

sudo iw phy phy0 interface add mon0 type monitor
sudo ip link set mon0 up
sudo iw dev mon0 set channel 36 ht20

### PLCP

data rate: 1Mb/s

### 2.

captura dhcp

ok


### 3.

72Mbps

6

no


### 4.

Configurado el router con threshold RTS de 200

```
RTS     0       28
CTS     146     28
frame   442     252
ACK     955     28

sobrecarga = 442us

Tt = 983us
Tu = 252us  (26%)
Ti = 731us  (74%)
    Tw = 647us  (65%)
    Tc = 84us   (9%)
```

