#!/bin/bash

file_path=${HOME}/ApolloAuto/apollo5.0_autoinstall

docker run hello-world
sudo systemctl enable docker


bash ${file_path}/install_set_gcc.sh
bash ${file_path}/install_nvidia_docker_container_toolkit.sh

#cp ${HOME}/apollo5.0_autoinstall/setup.bash ${HOME}/apollo/cyber/ ## If cyber_node info doesn't work, run this command.

cd ${HOME}/apollo
bash docker/scripts/dev_start.sh
bash docker/scripts/dev_into.sh

#bash ./apollo.sh config
#bash apollo.sh build or bash apollo.sh build_opt_gpu
