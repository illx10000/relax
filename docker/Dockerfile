FROM centos
RUN yum -y install sudo gcc gcc-c++ wget curl cmake gdb vim git\
    && wget https://dl.google.com/go/go1.12.1.linux-amd64.tar.gz -O go1.12.1.linux-amd64.tar.gz \
    && tar -C /usr/local/ -zxvf go1.12.1.linux-amd64.tar.gz\
    && echo 'export PATH=$PATH:/usr/local/go/bin/' >> /etc/profile\
    && mkdir -p /code/go/\
    && echo 'export GOPATH=/code/go' >> /etc/profile\
    && source /etc/profile