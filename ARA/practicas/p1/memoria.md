# ARA Practica 1

## 1.

```
AR2#ping 3f32::1
 
Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 3F32::1, timeout is 2 seconds:
!!!!!
Success rate is 100 percent (5/5), round-trip min/avg/max = 48/64/72 ms
AR2#traceroute 3f32::1
 
Type escape sequence to abort.
Tracing the route to 3F32::1
 
  1 2D32:0:1::1 12 msec 12 msec 40 msec
  2 3F32:0:1::1 12 msec 28 msec 32 msec
  3 3F32::1 60 msec 44 msec 36 msec
AR2#


AR1#ping 2f32::1
 
Type escape sequence to abort.
Sending 5, 100-byte ICMP Echos to 2F32::1, timeout is 2 seconds:
!!!!!
Success rate is 100 percent (5/5), round-trip min/avg/max = 20/56/104 ms
AR1#traceroute 2f32::1
 
Type escape sequence to abort.
Tracing the route to 2F32::1
 
  1 3F32:0:1::1 16 msec 16 msec 20 msec
  2 2D32:0:1::1 20 msec 40 msec 40 msec
  3 2F32::1 68 msec 68 msec 36 msec
AR1#
```

## 2.

```
root@cn:~# ip a s dev eth0
2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether 0c:81:84:ba:00:00 brd ff:ff:ff:ff:ff:ff
    inet6 3f32::e81:84ff:feba:0/64 scope global mngtmpaddr dynamic 
       valid_lft 2591959sec preferred_lft 604759sec
    inet6 fe80::e81:84ff:feba:0/64 scope link 
       valid_lft forever preferred_lft forever
```

Es global porque la ha obtenido mediante SLAAC del RA1

```
root@cn:~# ip -6 r
3f32::/64 dev eth0  proto kernel  metric 256  expires 2591911sec
fe80::/64 dev eth0  proto kernel  metric 256 
default via fe80::c802:14ff:fe52:6 dev eth0  proto ra  metric 1024  expires 1711sec hoplimit 64
```

El router por defecto es la LLA de RA1 en la interfaz de esa red

## 3.

Aparece un NS de AR1 preguntando por MAC de LLA de CN

## 4.

