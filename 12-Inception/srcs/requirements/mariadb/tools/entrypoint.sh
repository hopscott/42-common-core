#!/bin/bash
# set -ux

service mysql start

if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then

echo "Database already exists"

else

# wait for mysql to start
sleep 5

mysql_install_db
mysql_secure_installation <<EOF

Y
$MYSQL_ROOT_PASSWORD
$MYSQL_ROOT_PASSWORD
Y
n
Y
Y
EOF

# https://stackoverflow.com/questions/19101243/error-1130-hy000-host-is-not-allowed-to-connect-to-this-mysql-server

mysql -uroot -p$MYSQL_ROOT_PASSWORD <<EOF
DROP USER 'root'@'localhost';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -uroot -p$MYSQL_ROOT_PASSWORD <<EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -u$MYSQL_USER -p$MYSQL_PASSWORD <<EOF
SHOW DATABASES;
EOF

mysqladmin -uroot -p$MYSQL_ROOT_PASSWORD shutdown

fi

service mysql stop

exec "$@"
