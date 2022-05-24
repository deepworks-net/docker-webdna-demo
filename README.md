# A Demonstration of WebDNA in a Docker Container!

Documentation will continuously be added in future updates. Right now the goal is to create a very basic docker container with WebDNA and demonstrate its capabilities. This project is **NOT** meant for production use and is just the bare minimum as a proof of concept. Best practices are not always followed in this project- utilize in production at your own risk!

To save space in our docker repository, we only will store the most recent version of the images. Past images can be built manually if needed.

## Required Stuff

[Docker Desktop](https://www.docker.com/products/docker-desktop/) should be installed in order to run and build the containers. 

[VSCode](https://code.visualstudio.com/) is recommended for building/running/working with containers- due to the many extensions and integrations it has built in- but is not required. The use of powershell/terminal to build the images is required.

## Why would I want to run WebDNA in a container?
There are a lot of reason why you might want to run WebDNA in a container, [containers](https://www.docker.com/resources/what-container/) are a powerful technology for developing, managing, and running web applications.

The biggest reason though would be having a highly portable, cross platform, easily set up environment for WebDNA development. Build your own or pull a public image from the docker repository, spin it up in docker desktop and start coding in WebDNA on localhost!

## Demonstration Images Quick Start

[Download the repository](https://github.com/deepworks-net/docker-webdna/archive/refs/heads/main.zip) and place it somewhere on your computer. Open a terminal and navigate to the location of the repository:
```SHELL
cd '/YOUR/LOCATION/TO/REPO'
```

Choose the OS/WebDNA Version to run/build from the [docker-compose.yml](docker-compose.yml) file. Current choices are:

- [AlmaLinux](almalinux/README.md)
- [Alpine](alpine/README.md)
- [CentOS](centos/README.md)
- [RockyLinux](rockylinux/README.md)
- [Ubuntu](ubuntu/README.md)

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