
# Ethernet Bridge Module

This is to use Ethernet communication with CyberRT Channel.

This module can read message from CyberRT Channel and send the message to other computer through IP Address.

Also, can receive message from other computer through IP Addess and write the message on CyberRT Channel.
<br>

## Prerequisites
Apollo 5.0, Ubuntu16.04, UDP communication test program (It's providing on my github: (https://github.com/dooadex/Network/tree/master/UDP_communication))
<br>

## Download and build

### Module download
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
<br>

## Test the module
Download UDP communication test code (https://github.com/dooadex/Network/tree/master/UDP_communication).
<br>

#### &nbsp;&nbsp;&nbsp;Note
&nbsp;&nbsp;&nbsp; You can test in two different ways. One is to use two computer, and the other one is to user only one computer.

&nbsp;&nbsp;&nbsp; It's so simple. You only need to edit just one line of the code. You can refer to the page what I provided right above for detail.
<br>

Open three terminals

In Terminal A
```bash
cyber_monitor
```
#### &nbsp;&nbsp;&nbsp;Note
&nbsp;&nbsp;&nbsp; If you can't run the command, enter ```bash source cyber/setup.bash``` at /apollo in each terminals.
<br>

In Terminal B
```bash
./bazel-bin/modules/ethernet/ethernet_receiver
```

In Terminal C
```bash
./bazel-bin/modules/ethernet/ethernet_sender
```

run 'client' program of UDP_communication.

send message what you want.

