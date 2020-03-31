FROM ubuntu
LABEL maintainer="Medov Dmitriy dermdv@gmil.com"
RUN apt-get update && apt-get install -y gcc
WORKDIR /lab3_mdd
COPY /lab3 .
