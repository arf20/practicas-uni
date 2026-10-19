FROM ubuntu:18.04
  
RUN apt-get update
RUN apt-get check
RUN apt-get dist-upgrade -y
RUN apt-get install -y wget iputils-ping tcpdump net-tools haproxy keepalived
RUN mkdir /mnt/haproxy
COPY ./haproxy.cfg /usr/local/etc/haproxy/
	
CMD tail -f /dev/null
