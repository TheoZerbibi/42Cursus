FROM debian:buster
LABEL maintainer="thzeribi@student.42.fr"

# INSTALL PACKAGE
RUN echo "INSTALL PACKAGE"
RUN apt-get update -yq && apt-get upgrade -yq \
	&& apt-get install curl wget nginx certbot php-mysql libnss3-tools mariadb-server -yq \
	&& apt-get clean -yd

#SETUP WORKDIR & PORT
WORKDIR /var/www/
EXPOSE 443
EXPOSE 80

#SETUP NGINX
RUN echo "SETUP NGINX"
COPY srcs/nginx.conf /etc/nginx/sites-available/
RUN mkdir -p /var/www/ft_server/html && mkdir -p /var/www/ft_server/logs \
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

#SQL SETUP

#PHPMYADMIN SETUP

#START ALL SERVICE
RUN echo "START SERVICES"
CMD ["nginx", "-g", "daemon off;"]
