#!/bin/bash

file_path=${HOME}/ApolloAuto/apollo5.0_autoinstall
sudo apt install -y git tar curl
bash ${file_path}/install_apollo5.0.sh
bash ${file_path}/install_docker.sh
