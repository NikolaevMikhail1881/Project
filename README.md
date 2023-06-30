docker build -t 221-352_mironov:latest -f myShop.DockerFile .

docker run -p = 33333:33333 221-352_mironov:latest

docker container commit "Container ID" 221-352_mironov:latest

docker tag 221-352_mironov:latest Miron1968/221-352_mironov:latest

docker push Miron1968/221-352_mironov:latest

Docker: https://hub.docker.com/repository/docker/miron1968/221-352_mironov
