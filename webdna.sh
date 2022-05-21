#!/bin/sh

DNA_FOLDER="${DNA_FOLDER:-WebDNA-folder-8.6}"
DNA_EXECUTABLE="${DNA_EXECUTABLE:-WebDNA-Linux-FastCGI-8.6.5}"

WEBROOT="${WEBROOT:-/var/www/html}"
WEBDNA_LOC="${WEBDNA_LOC:-$WEBROOT/WebDNA}"
APACHE_USER="${APACHE_USER:-apache}"
APACHE_LOC="${APACHE_LOC:-/etc/httpd}"
APACHE_CONFIG="${APACHE_CONFIG:-$APACHE_LOC/conf/httpd.conf}"

PATTERN='WebDNA-(Linux|Alpine)-(FastCGI|Server)-([0-9].[0-9].[0-9])'

GET_VALUE(){
    [[ $1 =~ $PATTERN ]] && echo "${BASH_REMATCH[$2]}"
}

SET_VERSION(){ 
    DNA_VERSION="$(GET_VALUE $DNA_EXECUTABLE 3)" 
}

SET_PLATFORM(){
    DNA_PLATFORM="$(GET_VALUE $DNA_EXECUTABLE 1)"
}

SET_TYPE(){
    DNA_TYPE="$(GET_VALUE $DNA_EXECUTABLE 2)"
}

# Set Stuff
SET_VERSION
SET_PLATFORM
SET_TYPE

 # Pull in the WebDNA folder and fcgi
wget https://webdna.us/download/${DNA_FOLDER}.zip
unzip -d . "${DNA_FOLDER}.zip"
rm -f "${DNA_FOLDER}.zip"
wget https://www.webdna.us/download/${DNA_EXECUTABLE}.zip
unzip -d . "${DNA_EXECUTABLE}.zip"
rm -f "${DNA_EXECUTABLE}.zip"

# 'Install' WebDNA
if [ "${DNA_TYPE}" == "FastCGI" ]; then

    if [ "${DNA_VERSION}" == "8.6.5" ]; then
        mv "${DNA_EXECUTABLE}/WebDNA.fcgi" "WebDNA/WebDNA.fcgi";
        # Remove WebDNA Artifacts
        rm -rf "${DNA_EXECUTABLE}";
    else
        mv "WebDNA.fcgi" "WebDNA/WebDNA.fcgi";
    fi
    chmod 0755 "WebDNA/WebDNA.fcgi"
    mv "WebDNA" ${WEBDNA_LOC}

fi

chown -R $APACHE_USER:$APACHE_USER ${WEBDNA_LOC}

# Quick Config of Apache
mkdir -p "$WEBROOT/public"
sed -i -e "s/Options Indexes FollowSymLinks/Options Includes FollowSymLinks ExecCGI/g" "${APACHE_CONFIG}"
echo "
AddType text/html .dna
AddType text/html .tpl
<FilesMatch  \".*\.(hdr)$\">
    Deny from all
</FilesMatch>
<Location ~  \"/.*/ErrorLog($|\.txt)\">
    deny from all
</Location>
<Directory "$WEBROOT">
Options Includes FollowSymLinks ExecCGI
FcgidWrapper ${WEBDNA_LOC}/WebDNA.fcgi .dna
FcgidWrapper ${WEBDNA_LOC}/WebDNA.fcgi .html
FcgidWrapper ${WEBDNA_LOC}/WebDNA.fcgi .tpl
FcgidWrapper ${WEBDNA_LOC}/WebDNA.fcgi .htm
AddHandler fcgid-script .dna .html .tpl .htm
<IfModule mod_rewrite.c>
    RewriteEngine on
    RewriteRule .* - [E=HTTP_AUTHORIZATION:%{HTTP:Authorization},L]
</IfModule>
</Directory>
DefaultMaxClassProcessCount 1
" >> "${APACHE_CONFIG}"
# Quick Configure WebDNA
sed -i -e "s/UnixUser.*/UnixUser	$APACHE_USER/g" "${WEBDNA_LOC}/webdna.ini"