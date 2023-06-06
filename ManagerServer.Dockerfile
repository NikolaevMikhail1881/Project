FROM ubuntu:latest

ENV TZ=Europe/Moscow
# author = "Vanin"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

EXPOSE 33333

WORKDIR /root/
RUN mkdir Vanin
WORKDIR /root/Vanin/
COPY * /root/Vanin/


RUN qmake echoServer_351.pro
RUN make 

ENTRYPOINT [ "./echoServer_351" ]


# docker build -t name:latest -f ManagerServer.Dockerfile .
# docker run -p = 33333:33333 name:latest
# docker container commit "Container ID" name:latest
# docker tag name:latest dockerUser/name:latest
# docker push dockerUser/name:latest