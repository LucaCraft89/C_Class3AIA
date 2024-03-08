#!/bin/bash

# Define the path to the old Docker volumes
old_volumes_path="/mnt/olddisk/var/lib/docker/volumes"

# Find the WordPress and MySQL volumes
old_wordpress_volume=$(find $old_volumes_path -name '*_wordpress' -type d)
old_mysql_volume=$(find $old_volumes_path -name '*_db' -type d)

# Check if the WordPress and MySQL volumes were found
if [ -z "$old_wordpress_volume" ] || [ -z "$old_mysql_volume" ]; then
    echo "Could not find the WordPress or MySQL volume."
    exit 1
fi

# Define the paths to the old and new WordPress and MySQL data
old_wordpress_path="$old_wordpress_volume/_data"
old_mysql_path="$old_mysql_volume/_data"
new_wordpress_path="/path/to/new/wordpress"
new_mysql_path="/path/to/new/mysql"

# Copy the WordPress and MySQL data to the new machine
cp -r $old_wordpress_path $new_wordpress_path
cp -r $old_mysql_path $new_mysql_path

# Create a docker-compose.yml file for the new WordPress and MySQL containers
cat << EOF > docker-compose.yml
version: '3.1'

services:
    wordpress:
        image: wordpress
        restart: always
        ports:
            - 8080:80
        environment:
            WORDPRESS_DB_HOST: db
            WORDPRESS_DB_USER: exampleuser
            WORDPRESS_DB_PASSWORD: examplepass
            WORDPRESS_DB_NAME: exampledb
        volumes:
            - $new_wordpress_path:/var/www/html

    db:
        image: mysql:5.7
        restart: always
        environment:
            MYSQL_DATABASE: exampledb
            MYSQL_USER: exampleuser
            MYSQL_PASSWORD: examplepass
            MYSQL_RANDOM_ROOT_PASSWORD: '1'
        volumes:
            - $new_mysql_path:/var/lib/mysql
EOF

# Start the Docker containers
docker-compose up -d