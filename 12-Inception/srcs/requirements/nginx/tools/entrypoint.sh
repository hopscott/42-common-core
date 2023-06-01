#!/bin/bash
set -eux

php-fpm7.3
service mysql start
nginx -g 'daemon off;'
