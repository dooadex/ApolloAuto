#!/bin/bash
rm ${HOME}/apollo/docker/scripts/dev_start.sh
cp ${HOME}/ApolloAuto/ethernet_bridge/dev_start.sh ${HOME}/apollo/docker/scripts/dev_start.sh
cp -r ${HOME}/ApolloAuto/ethernet_bridge/ethernet ${HOME}/apollo/modules
