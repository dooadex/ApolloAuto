#!/bin/bash

wget https://github.com/ApolloAuto/apollo-kernel/releases/download/1.5.5/linux-4.4.32-apollo-1.5.5.tar.gz
tar zxvf linux-4.4.32-apollo-1.5.5.tar.gz
cd install
bash install_kernel.sh

