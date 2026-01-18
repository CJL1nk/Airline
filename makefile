CC=gcc

CLIENT_DIR := Airline-Client
SERVER_DIR := Airline-Server

CLIENT_OUT_DIR := bin/Client

.PHONY: all build_client build_server

all: build_client build_server run_client

build_client:
	cmake -S $(CLIENT_DIR) -B $(CLIENT_DIR)/build -DCMAKE_BUILD_TYPE=Release
	cmake --build ${CLIENT_DIR}/build
	mv ${CLIENT_DIR}/build/Airline_Client ${CLIENT_OUT_DIR}

run_client: 

	${CLIENT_OUT_DIR}/Airline_Client

build_server: