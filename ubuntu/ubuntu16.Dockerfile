# Pull the Base Image
FROM ubuntu:16.04 as Base

ARG DNA_FOLDER="${DNA_FOLDER:-WebDNA-folder-8.6}"
ARG DNA_EXECUTABLE="${DNA_EXECUTABLE:-WebDNA-Linux-FastCGI-8.6.5}"
ARG APACHE_USER="${APACHE_USER:-www-data}"
ARG APACHE_LOC="/etc/apache2"
ARG APACHE_CONFIG="$APACHE_LOC/apache2.conf"
ARG WEBROOT="/var/www/html"
ARG WEBDNA_LOC="$WEBROOT/WebDNA"
ARG DEBIAN_FRONTEND=noninteractive

# Set Working Directory
WORKDIR /tmp

# Copy over setup scripts
COPY ../webdna.sh ./

## Build The Container
# Perform Updates
RUN apt-get update && \
    apt-get -y install wget openssl apache2 libapache2-mod-fcgid unzip  && \
    # Enable the rewrite module
    a2enmod rewrite && \
    # Run WebDNA Setup Script
    DNA_FOLDER="$DNA_FOLDER" \
    DNA_EXECUTABLE="$DNA_EXECUTABLE" \
    WEBROOT="$WEBROOT" \
    WEBDNA_LOC="$WEBDNA_LOC" \
    APACHE_USER="$APACHE_USER" \
    APACHE_LOC="$APACHE_LOC" \
    APACHE_CONFIG="$APACHE_CONFIG" \
    bash "./webdna.sh" && \ 
    rm -f "./webdna.sh" && \
    # Clean Up After Ourselves
    apt-get -y remove wget unzip && \
    apt-get -y autoremove && \
    apt-get -y clean

# Fresh Image Layer
FROM scratch AS Final

# Copy Structure
COPY --from=Base / /

ENTRYPOINT [ "apache2ctl", "-DFOREGROUND" ]

# Expose http and https
EXPOSE 80 443