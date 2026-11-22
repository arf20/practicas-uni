FROM ubuntu:18.04

RUN apt-get update
RUN apt-get check
RUN apt-get dist-upgrade -y
RUN apt-get install -y lynx iproute2 iputils-ping tcpdump net-tools

COPY ./routes.sh .
RUN chmod +x routes.sh
ENTRYPOINT []
CMD ["./routes.sh"]
