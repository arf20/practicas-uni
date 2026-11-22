# notas

## docker

```
docker compose build
docker compose up
docker compose down
```

```
docker ps
docker exec -it <nombre> /bin/bash
```

## load balancer

```
haproxy -D -f /tmp/haproxy.cfg
keepalived -n -l -f /tmp/keepalived-lb1.conf
```

la IP virtual no contesta a ARP, pq no esta en ninguna interfaz física

estado actual VRRP keepalived funciona: si quitas master, backup se pone master, y si lo vuelves a poner, se vuelve a poner

