#!/bin/bash

cd ${HOME}
git clone https://github.com/ApolloAuto/apollo.git
cd ${HOME}/apollo
git checkout r5.0.0
echo "export APOLLO_HOME=$(pwd)" >> ~/.bashrc && source ~/.bashrc
