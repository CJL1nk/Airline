CC=gcc

TUI_CLIENT_DIR := Airline-Client/TUI
SERVER_DIR := Airline-Server

TUI_CLIENT_OUT_DIR := bin/Client/TUI

.PHONY: all build_client build_server

all: build_client build_server run_tui_client

build_client:
	cmake -S $(TUI_CLIENT_DIR) -B $(TUI_CLIENT_DIR)/build -DCMAKE_BUILD_TYPE=Release
	cmake --build ${TUI_CLIENT_DIR}/build
	mv ${TUI_CLIENT_DIR}/build/Airline_Client ${TUI_CLIENT_OUT_DIR}

run_tui_client: 

	${TUI_CLIENT_OUT_DIR}/Airline_Client

build_server: