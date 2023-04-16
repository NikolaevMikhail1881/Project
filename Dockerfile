FROM archlinux:latest

RUN apt-get update
RUN apt-get install qtbase6-dev qtchooser qt6-qmake qtbase6-dev-tools -y

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server
COPY *.cpp /root/server
COPY *.h /root/server
COPY *.pro /root/server

RUN qmake .pro
RUN make 