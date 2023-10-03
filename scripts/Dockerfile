FROM balenalib/raspberrypi3:bullseye

# Update apt repos
RUN apt update --allow-unauthenticated
RUN apt upgrade -y

# Install packages
RUN apt -y install git
RUN apt -y install curl wget
RUN apt -y install libtool
RUN apt -y install cmake make automake
RUN apt -y install g++ clang
RUN apt -y install python-dev

# set user; everything below is under user webserver
ENV HOME=/home/webserver
RUN useradd -ms /bin/bash webserver
USER webserver
WORKDIR /home/webserver

RUN git clone https://github.com/calvindo95/eg-cs.git && \
    cd eg-cs/include && wget https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp && cd .. && \
    mkdir build && cd build && \
    cmake .. && \
    cmake --build . -j4

#CMD ["/home/webserver/source_directory/scripts/run_server.sh"]