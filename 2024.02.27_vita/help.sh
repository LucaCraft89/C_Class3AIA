#!/bin/bash

# Define the path to the old Docker volumes
old_volumes_path="/mnt/olddisk/var/lib/docker/volumes"

# Find the WordPress and MySQL volumes
old_wordpress_volume=$(find $old_volumes_path -name '*_wordpress*' -type d)
old_mysql_volume=$(find $old_volumes_path -name '*_db*' -type d)

# Check if the WordPress and MySQL volumes were found
if [ -z "$old_wordpress_volume" ] || [ -z "$old_mysql_volume" ]; then
  echo "Could not find the WordPress or MySQL volume."
  exit 1
fi


# Define the paths to the old and new WordPress and MySQL data
old_wordpress_path="$old_wordpress_volume/_data"
old_mysql_path="$old_mysql_volume/_data"
new_wordpress_path="/root/wordpressDNT/wordpress_data"
new_mysql_path="/root/wordpressDNT/mysql_data"

# Create the directories for the new WordPress and MySQL data
mkdir -p $new_wordpress_path
mkdir -p $new_mysql_path

# Copy the WordPress data to the new machine
cp -r $old_wordpress_path $new_wordpress_path

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
            WORDPRESS_DB_USER: wordpress
            WORDPRESS_DB_PASSWORD: K0v4lsk1!
            WORDPRESS_DB_NAME: wordpress
        volumes:
            - $new_wordpress_path:/var/www/html

    db:
        image: mysql:5.7
        restart: always
        environment:
            MYSQL_DATABASE: wordpress
            MYSQL_USER: wordpress
            MYSQL_PASSWORD: K0v4lsk1!
            MYSQL_RANDOM_ROOT_PASSWORD: '1'
        volumes:
            - $new_mysql_path:/var/lib/mysql
EOF

# Start the Docker containers
docker-compose up -d

# Wait for the MySQL container to start
sleep 60

# Import the old MySQL data
docker exec db sh -c 'exec mysql -uroot -p"$MYSQL_ROOT_PASSWORD" "$MYSQL_DATABASE"' < $old_mysql_path