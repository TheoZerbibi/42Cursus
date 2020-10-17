FROM debian:buster
LABEL maintainer="thzeribi@student.42.fr"

# INSTALL PACKAGE
RUN echo "INSTALL PACKAGE"
RUN apt-get update -yq && apt-get upgrade -yq \
	&& apt-get install curl wget nginx certbot libnss3-tools mariadb-server -yq \
	&& apt-get install php-fpm php-mysql -y \
	&& apt-get clean -yd

#SETUP WORKDIR & PORT
WORKDIR /var/www/
EXPOSE 443
EXPOSE 80

#SETUP NGINX
RUN echo "SETUP NGINX"
COPY srcs/nginx.conf /etc/nginx/sites-available/
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

#WORDPRESS SETUP
RUN echo "SETUP WORDPRESS"
RUN mkdir -p /var/www/ft_server/html/wordpress
COPY srcs/wordpress-5.5.1-fr_FR.tar.gz /var/www/ft_server/html/wordpress/
RUN cd /var/www/ft_server/html/wordpress \
	&& tar -xf wordpress-5.5.1-fr_FR.tar.gz \
	&& rm wordpress-5.5.1-fr_FR.tar.gz

#SQL SETUP

#PHPMYADMIN SETUP

#START ALL SERVICE
RUN echo "START SERVICES"
ENTRYPOINT ["nginx", "-g", "daemon off;"]
RUN service mysql start
RUN /etc/init.d/php7.3-fpm start
RUN service nginx restart
