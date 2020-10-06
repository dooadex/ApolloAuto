#!/bin/bash

sudo apt install -y gcc-4.8 gcc-4.8-multilib g++-4.8 g++-4.8-multilib gcc gcc-multilib g++ g++-multilib cmake autoconf automake
/usr/bin/update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 99 --slave /usr/bin/g++ g++ /usr/bin/g++-4.8
gcc -v   # check gcc version
