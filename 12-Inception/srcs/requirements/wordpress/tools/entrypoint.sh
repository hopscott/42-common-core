#!/bin/bash
# set -eux
set -eu

# if [ -d ./wp ]
# then

# echo "Wordpress already installed"

# else

# # install wp & setup wp dir
# curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# chmod +x wp-cli.phar
# rm -rf wp
# mv wp-cli.phar /usr/local/bin/wp
# wp core download --path=wp --allow-root
# wp db create --path=wp --allow-root

# fi


# if [ -f ./wp-config.php ]
# then

# echo "Wordpress already configured"

# else

# # setup wp-config.php file and db
# service mysql start
# wp config create --path=wp --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb:3306 --allow-root
# wp core install --path=wp --url=swillis.42.fr --title="Inception" --admin_user=$WP_USER --admin_password=$WP_PASSWORD --admin_email=$WP_EMAIL --allow-root

# fi

# exec "$@"

# -----------------------------

if [ -f /usr/local/bin/wp/wp-cli.phar ]
then

echo "Wordpress already installed"

else

# install wp
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

fi

if [ -d ./wp-content ]
then

echo "Wordpress already downloaded"

else

# setup wp dir
wp core download --allow-root

fi

if [ -f ./wp-config.php ]
then

echo "Wordpress already configured"

else

# wait for mariadb
sleep 10

# setup wp-config.php file and db
service mysql start
wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb:3306 --allow-root
wp core install --url=swillis.42.fr --title="Inception" --admin_user=$WP_USER --admin_password=$WP_PASSWORD --admin_email=$WP_EMAIL --allow-root
wp user create $WP_EDITOR $WP_EDITOR_EMAIL --user_pass=$WP_EDITOR_PASSWORD --role=editor --allow-root

fi

exec "$@"
