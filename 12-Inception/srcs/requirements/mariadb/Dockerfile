# ----------------------------------------
# https://mariadb.com/kb/en/creating-a-custom-docker-image/
# https://tuto.grademe.fr/inception/
# https://www.cherryservers.com/blog/how-to-install-and-start-using-mariadb-on-ubuntu-20-04
# https://stackoverflow.com/questions/24270733/automate-mysql-secure-installation-with-echo-command-via-a-shell-script
# https://stackoverflow.com/questions/17666249/how-do-i-import-an-sql-file-using-the-command-line-in-mysql
# ----------------------------------------> v1 = nginx <> php-fpm + wordpress <> mariadb

FROM debian:buster

RUN apt-get update \
	&& apt-get install -y mariadb-server mariadb-client\
	&& mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld \
	&& chown -R mysql /var/lib/mysql

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/entrypoint.sh /etc/entrypoint.sh
RUN chmod +x /etc/entrypoint.sh
ENTRYPOINT ["/etc/entrypoint.sh"]

CMD ["mysqld"]
