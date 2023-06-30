FROM ubuntu:18.04
#LABLE author = "Mironov_Miron"
ENV TZ=Europe/Moscow   
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone   
RUN apt-get update   
RUN apt-get install qt5-default qtbase5-dev qt5-qmake -y   
RUN apt-get install build-essential -y 

EXPOSE 33333

WORKDIR /root/
RUN mkdir 221_352_Mironov_Miron
WORKDIR /root/221_352_Mironov_Miron
COPY *.cpp /root/221_352_Mironov_Miron
COPY *.h /root/221_352_Mironov_Miron
COPY *.pro /root/221_352_Mironov_Miron

RUN qmake echoServer1.pro
RUN make

ENTRYPOINT [ "./echoServer" ]

# docker build -t name:latest -f myShop.Dockerfile .
# docker run -p = 33333:33333 name:latest
# docker container commit "Container ID" name:latest
# docker tag name:latest dockerUser/name:latest
# docker push dockerUser/name:latest