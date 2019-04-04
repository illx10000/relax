#!/bin/sh
#usage: config centos as dev 


docker pull centos                              #pull centos7 from docker hub
docker run -itd centos /bin/bash                #run images and get containerID
containerID=`docker ps -a | awk '{if($2=="centos") print $1}'`
docker attach $containerID                      #attach to container

#in container
#install build tool
yum install sudo gcc gcc-c++ wget curl cmake gdb vim

#input Y to confirm

#install go env
wget -c https://storage.googleapis.com/golang/go1.8.3.linux-amd64.tar.gz
tar -C /usr/local/ -zxvf go1.8.3.linux-amd64.tar.gz

echo 'export PATH=$PATH:/usr/local/go/bin/' >> /etc/profile
mkdir -p /code/go/
echo 'export GOPATH=/code/go' >> /etc/profile
source /etc/profile
exit

#commit 
docker commit $containerID centos-dev

#remove old 
docker rm  $containerID
#docker rmi centos



docker run -it -v --privileged /Users/luoxi/Desktop:code centos-dev /bin/sh
source /etc/profile