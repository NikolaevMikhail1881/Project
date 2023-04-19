FROM ubuntu:latest

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server
COPY *.cpp /root/server
COPY *.h /root/server
COPY *.pro /root/server

RUN qmake .pro
RUN make 

ENTRYPOINT [ "./Server" ]