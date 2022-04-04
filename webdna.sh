#!/bin/sh

DNA_FOLDER="${DNA_FOLDER:WebDNA-folder-8.6}"
DNA_EXECUTABLE="${DNA_EXECUTABLE:WebDNA-Linux-FastCGI-8.6.5}"
WEBROOT="${WEBROOT:/var/www/html}"
WEBDNA_LOC="${WEBDNA_LOC:$WEBROOT/WebDNA}"
APACHE_USER="${APACHE_USER:apache}"
APACHE_LOC="${APACHE_LOC:/etc/httpd}"
APACHE_CONFIG="${APACHE_CONFIG:/etc/httpd/conf/httpd.conf}"

 # Pull in the WebDNA folder and fcgi
wget http://webdna.us/download/${DNA_FOLDER}.zip
unzip -d . "${DNA_FOLDER}.zip"
rm -f "${DNA_FOLDER}.zip"
wget http://www.webdna.us/download/${DNA_EXECUTABLE}.zip
unzip -d . "${DNA_EXECUTABLE}.zip"
rm -f "${DNA_EXECUTABLE}.zip"

# 'Install' WebDNA
mv "${DNA_EXECUTABLE}/WebDNA.fcgi" "WebDNA/WebDNA.fcgi"
chmod 0755 "WebDNA/WebDNA.fcgi"
cp -R "WebDNA" ${WEBDNA_LOC}
chown -R $APACHE_USER:$APACHE_USER ${WEBDNA_LOC}

# Remove WebDNA Artifacts
#rm -rf "${DNA_EXECUTABLE}"
#rm -rf "${DNA_FOLDER}"

# Quick Config of Apache
mkdir -p "$WEBROOT/public"
sed -i -e "s/Options Indexes FollowSymLinks/Options -Indexes +FollowSymLinks +ExecCGI/g" "${APACHE_CONFIG}"
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
Options -Indexes +FollowSymLinks +ExecCGI
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