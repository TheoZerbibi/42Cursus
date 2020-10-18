FROM debian:buster
LABEL maintainer="thzeribi@student.42.fr"

# INSTALL PACKAGE
RUN echo "INSTALL PACKAGE"
RUN apt-get update -yq && apt-get upgrade -yq \
	&& apt-get install curl wget nginx certbot libnss3-tools mariadb-server supervisor -yq \
	&& apt-get install php-fpm php-mysql -y \
	&& apt-get clean -yd

#SETUP WORKDIR & PORT
WORKDIR /var/www/
EXPOSE 443
EXPOSE 80

#SETUP NGINX
RUN echo "SETUP NGINX"
COPY srcs/config/nginx.conf /etc/nginx/sites-available/
RUN rm /etc/nginx/sites-enabled/default
RUN mkdir -p /var/www/ft_server/html /var/www/ft_server/logs \
	&& touch /var/www/ft_server/logs/{error.log,access.log}
RUN mv /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-available/localhost \
	&& ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

#SSL SETUP
RUN mkdir /var/mkcert \
	&& cd /var/mkcert \
	&& wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 \
	&& mv mkcert-v1.4.1-linux-amd64 mkcert \
	&& chmod +x mkcert \
	&& ./mkcert -install \
	&& ./mkcert localhost

#SQL SETUP
COPY srcs/sql/create_db .
COPY srcs/sql/wordpress.sql .
RUN service mysql start \
	&& mysql -u root < create_db \
	&& mysql wordpress -u root --password= < wordpress.sql

#PHPMYADMIN SETUP
RUN echo "SETUP PHPMYADMIN"
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz -P /var/www/ft_server/html/
RUN cd /var/www/ft_server/html \
	&& tar -xf phpMyAdmin-5.0.4-all-languages.tar.gz \
	&& mv phpMyAdmin-5.0.4-all-languages phpMyAdmin \
	&& rm phpMyAdmin-5.0.4-all-languages.tar.gz
COPY srcs/config/config.inc.php /var/www/ft_server/html/phpMyAdmin/

#WORDPRESS SETUP
RUN echo "SETUP WORDPRESS"
COPY srcs/wordpress-5.5.1-fr_FR.tar.gz /var/www/ft_server/html/
RUN cd /var/www/ft_server/html \
	&& tar -xf wordpress-5.5.1-fr_FR.tar.gz \
	&& rm wordpress-5.5.1-fr_FR.tar.gz

#FIX NGINX PERMISSIONS
RUN echo "NGINX PERMISSIONS"
RUN chown -R www-data:www-data /var/www/* \
	&& chmod -R 755 /var/www/*

#SUPERVISORSETUP
RUN mkdir -p /var/log/supervisor \
	&& mkdir -p /etc/supervisor/conf.d
ADD srcs/config/supervisor.conf /etc/supervisor.conf

#START ALL SERVICE
WORKDIR /var/www/ft_server/
RUN echo "START SERVICES"
CMD ["supervisord", "-c", "/etc/supervisor.conf"]
