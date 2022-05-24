# Docker WebDNA Demos Changelog

## (05/20/2022) v0.6.0-beta:
## (05/24/2022) v0.6.0-beta:
- Added FCGI 8.6.5, 8.6.4, 8.6.3, and 8.6.1 Support for RockyLinux 8.5.20220308
- Added FCGI 8.6.5, 8.6.4, 8.6.3, and 8.6.1 Support for AlmaLinux 8.5-20220510
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for CentOS 7
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for CentOS 8 (8.4)
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for Ubuntu 16.04
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for Ubuntu 18.04
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for Ubuntu 20.04
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for Ubuntu 21.10
- Added FCGI 8.6.4, 8.6.3, and 8.6.1 Support for Ubuntu 22.04
- Added Support for passing the WebDNA Executable as an Argument `DNA_EXECUTABLE` to the Dockerfile(s)
- Added Support for passing the WebDNA Folder as an Argument `DNA_FOLDER` to the Dockerfile(s)
- Added Support for passing the WebDNA User as an Argument `APACHE_USER` to the Dockerfile(s)
- Added README files for each Platform
- Updated service names to reflect their version of WebDNA (ie fcgi-865 for FastCGI 8.6.5)
- Updated License
- Modified Dockerfile naming convention
- Modified Changelog

## (04/07/2022) v0.5.1-beta:
- Moved Ubuntu Dockerfiles to their own folder
- Moved Alpine Dockerfiles to their own folder
- Moved CentOS Dockerfiles to their own folder

## (04/05/2022) v0.5.0-beta:
- Added FCGI 8.6.5 Support for Alpine 3.12.12
- Optimized WebDNA Folder source placement reducing image size

## (04/05/2022) v0.4.0-beta:
- Added FCGI 8.6.5 Support for Ubuntu 18.04
- Added FCGI 8.6.5 Support for Ubuntu 21.10
- Added FCGI 8.6.5 Support for Ubuntu 22.04

## (04/05/2022) v0.3.0-beta:
- Added FCGI 8.6.5 Support for CentOS 8
- Added FCGI 8.6.5 Support for Ubuntu 20.04

## (04/04/2022) v0.2.0-beta:
- Added FCGI 8.6.5 Support for Ubuntu 16.04
- Optimized Webdna script
- Optimized CentOS 7 Dockerfile

## (03/31/2022) v0.1.0-beta:
- Initial Build - Added FCGI 8.6.5 Support for CentOS 7