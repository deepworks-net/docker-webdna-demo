# A Demonstration of WebDNA in a Docker Container!

Documentation will continuously be added in future updates. Right now the goal is to create a very basic docker container with WebDNA and demonstrate its capabilities. This project is **NOT** meant for production use and is just the bare minimum as a proof of concept. Best practices are not always followed in this project- utilize in production at your own risk!

## Required Stuff

[Docker Desktop](https://www.docker.com/products/docker-desktop/) should be installed in order to run and build the containers. 

[VSCode](https://code.visualstudio.com/) is recommended for building/running/working with containers- due to the many extensions and integrations it has built in- but is not required. The use of powershell/terminal to build the images is required.

## Why would I want to run WebDNA in a container?
There are a lot of reason why you might want to run WebDNA in a container, [containers](https://www.docker.com/resources/what-container/) are a powerful technology for developing, managing, and running web applications.

The biggest reason though would be having a highly portable, cross platform, easily set up environment for WebDNA development. Build your own or pull a public image from the docker repository, spin it up in docker desktop and start coding in WebDNA on localhost!

## Demonstration Images Quick Start

[Download the repository](https://github.com/deepworks-net/docker-webdna-demo/archive/refs/heads/main.zip) and place it somewhere on your computer. Open a terminal and navigate to the location of the repository:
```SHELL
cd '/YOUR/LOCATION/TO/REPO'
```

Choose the service to run/build from the [docker-compose.yml](docker-compose.yml) file. Current services are:

- [AlmaLinux](almalinux/README.md)
    - AlmaLinux 8.5
        - almalinux85-fcgi-865 (AlmaLinux 8.5-20220510, WebDNA FCGI 8.6.5)
        - almalinux85-fcgi-864 (AlmaLinux 8.5-20220510, WebDNA FCGI 8.6.4)
        - almalinux85-fcgi-863 (AlmaLinux 8.5-20220510, WebDNA FCGI 8.6.3)
        - almalinux85-fcgi-861 (AlmaLinux 8.5-20220510, WebDNA FCGI 8.6.1)
- [Alpine](alpine/README.md)
    - Alpine 3.12.12
        - alpine312-fcgi-865 (Alpine 3.12.12, WebDNA FCGI 8.6.5)
- [CentOS](centos/README.md)
    - CentOS 7
        - centos7-fcgi-865 (CentOS 7.9.2009, WebDNA FCGI 8.6.5)
    - CentOS 8
        - centos8-fcgi-865 (CentOS 8.4.2105, WebDNA FCGI 8.6.5)
        - centos8-fcgi-864 (CentOS 8.4.2105, WebDNA FCGI 8.6.4)
        - centos8-fcgi-863 (CentOS 8.4.2105, WebDNA FCGI 8.6.3)
        - centos8-fcgi-861 (CentOS 8.4.2105, WebDNA FCGI 8.6.1)
- [RockyLinux](rockylinux/README.md)
    - RockyLinux 8.5
        - rockylinux85-fcgi-865 (RockyLinux 8.5.20220308, WebDNA FCGI 8.6.5)
        - rockylinux85-fcgi-864 (RockyLinux 8.5.20220308, WebDNA FCGI 8.6.4)
        - rockylinux85-fcgi-863 (RockyLinux 8.5.20220308, WebDNA FCGI 8.6.3)
        - rockylinux85-fcgi-861 (RockyLinux 8.5.20220308, WebDNA FCGI 8.6.1)
- [Ubuntu](ubuntu/README.md)
    - Ubuntu 16.04
        - ubuntu16-fcgi-865 (Ubuntu 16.04, WebDNA FCGI 8.6.5)
        - ubuntu16-fcgi-864 (Ubuntu 16.04, WebDNA FCGI 8.6.4)
        - ubuntu16-fcgi-863 (Ubuntu 16.04, WebDNA FCGI 8.6.3)
        - ubuntu16-fcgi-861 (Ubuntu 16.04, WebDNA FCGI 8.6.1)
    - Ubuntu 18.04
        - ubuntu18-fcgi-865 (Ubuntu 18.04, WebDNA FCGI 8.6.5)
    - Ubuntu 20.04
        - ubuntu20-fcgi-865 (Ubuntu 20.04, WebDNA FCGI 8.6.5)
    - Ubuntu 21.10
        - ubuntu21-fcgi-865 (Ubuntu 21.10, WebDNA FCGI 8.6.5)
    - Ubuntu 22.04
        - ubuntu22-fcgi-865 (Ubuntu 22.04, WebDNA FCGI 8.6.5)

### Run the Project:
Then use the following command to run the demo by again substituting {SERVICE} with service name:
```SHELL
# docker-compose up -d {SERVICE}
# To run ubuntu22-fcgi-865 after building:
docker-compose up -d ubuntu22-fcgi-865
```

### Build the project:
From there run the following command to build the demo substituting {SERVICE} with service name:
```SHELL
# docker-compose build {SERVICE}
# To build ubuntu22-fcgi-865:
docker-compose build ubuntu22-fcgi-865
```

Then use the following command to run the demo by again substituting {SERVICE} with service name:
```SHELL
# docker-compose up -d {SERVICE}
# To run ubuntu22-fcgi-865 after building:
docker-compose up -d ubuntu22-fcgi-865
```
Once the container is running, navigate to http://localhost/public/index.dna to see it in action! Anything in the 'public' folder will be served by apache and processed by WebDNA.

The WebDNA admin pages are located at http://localhost/WebDNA with the default username:password of admin:admin.