
# Ethernet Bridge Module

This is to use Ethernet communication with CyberRT Channel.

This module can read message from CyberRT Channel and send the message to other computer through IP Address.

Also, can receive message from other computer through IP Addess and write the message on CyberRT Channel.


## Prerequisites
Apollo 5.0, Ubuntu16.04, UDP communication test program (It's provided in my github ())

## Download and build code

### Code download
At ${HOME}

``` bash
git clone https://github.com/dooadex/ApolloAuto.git
cd ApolloAuto/ethernet_bridge/
./autoupdate.sh
```

### Build code in ApolloAuto docker
At ${HOME}/apollo
```bash
bash apollo.sh build
```

## Test the code
