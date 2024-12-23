# Pull the Base Image
FROM alpine:3.12.12 as Base

ARG DNA_FOLDER="${DNA_FOLDER:-WebDNA-folder-8.6}"
ARG DNA_EXECUTABLE="${DNA_EXECUTABLE:-WebDNA-Alpine-FastCGI-8.6.5}"
ARG APACHE_USER="${APACHE_USER:-apache}"
ARG APACHE_LOC="/etc/apache2"
ARG APACHE_CONFIG="$APACHE_LOC/httpd.conf"
ARG WEBROOT="/var/www/localhost/htdocs"
ARG WEBDNA_LOC="$WEBROOT/WebDNA"

# Set Working Directory
WORKDIR /tmp

# Copy over setup scripts
COPY ../webdna.sh ./

## Build The Container
# Perform Updates
RUN apk -U upgrade --no-cache && \
    apk add wget bash libstdc++ apache2 apache-mod-fcgid openssl unzip --no-cache && \
    # Enable the rewrite module
    sed -i -e "s|#LoadModule rewrite_module modules/mod_rewrite.so|LoadModule rewrite_module modules/mod_rewrite.so|g" "$APACHE_CONFIG" && \
    # Run WebDNA Setup Script
    DNA_FOLDER="$DNA_FOLDER" \
    DNA_EXECUTABLE="$DNA_EXECUTABLE" \
    WEBROOT="$WEBROOT" \
    WEBDNA_LOC="$WEBDNA_LOC" \
    APACHE_USER="$APACHE_USER" \
    APACHE_LOC="$APACHE_LOC" \
    APACHE_CONFIG="$APACHE_CONFIG" \
    bash "./webdna.sh" && \
    rm -f ./webdna.sh && \
    # clean up after ourselves
    apk del wget unzip && \
    # Delete Cache
    rm -rf /var/cache/apk/*

# Fresh Image Layer
FROM alpine.21.0 AS Final

# Copy Structure
COPY --from=Base / /

# Start Apache in the Foreground when the container starts
ENTRYPOINT [ "httpd", "-DFOREGROUND" ]

# Expose http and https
EXPOSE 80 443
