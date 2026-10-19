FROM ubuntu:18.04

RUN apt-get update
RUN apt-get check
RUN apt-get dist-upgrade -y
RUN apt-get install -y apache2
RUN apt-get install -y iproute2 tcpdump iputils-ping net-tools 

RUN a2enmod rewrite
RUN chown -R www-data:www-data /var/www

ENV APACHE_RUN_USER  www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR   /var/log/apache2
ENV APACHE_PID_FILE  /var/run/apache2/apache2.pid
ENV APACHE_RUN_DIR   /var/run/apache2
ENV APACHE_LOCK_DIR  /var/lock/apache2
ENV APACHE_LOG_DIR   /var/log/apache2

RUN mkdir -p $APACHE_RUN_DIR
RUN mkdir -p $APACHE_LOCK_DIR
RUN mkdir -p $APACHE_LOG_DIR

EXPOSE 80

COPY ./routes.sh .
RUN chmod +x routes.sh
ENTRYPOINT []
CMD ["./routes.sh"]
EXPOSE 80

