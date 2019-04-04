FROM centos
RUN yum -y install sudo gcc gcc-c++ wget curl cmake gdb vim \
    && wget -c https://storage.googleapis.com/golang/go1.8.3.linux-amd64.tar.gz\
    && tar -C /usr/local/ -zxvf go1.8.3.linux-amd64.tar.gz\
    && echo 'export PATH=$PATH:/usr/local/go/bin/' >> /etc/profile\
    && mkdir -p /code/go/\
    && echo 'export GOPATH=/code/go' >> /etc/profile\
    && source /etc/profile