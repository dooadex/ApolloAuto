
# Ethernet Bridge Module

This is to use Ethernet communication with CyberRT Channel.

This module can read message from CyberRT Channel and send the message to other computer through IP Address.

Also, can receive message from other computer through IP Addess and write the message on CyberRT Channel.
<br>

## Prerequisites
Apollo 5.0, Ubuntu16.04, UDP communication test program (It's provided on my github: (https://github.com/dooadex/Network/tree/master/UDP_communication))
<br><br><br>

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

#### &emsp;Note
&emsp;You can test in two different ways. One is to use two computer, and the other one is to user only one computer.

&emsp;It's so simple. You only need to edit just one line of the code.

&emsp;```c++ client_addr.sin_addr.s_addr=inet_addr("IP Address"); //IP address where you want to send, for example ("192.168.0.7") ```

&emsp;If you set the ("IP Address") value as "127.0.0.1".

You can refer to the page what I provided right above for detail.
<br><br>

**Open three terminals**

**In Terminal A**
```bash
cyber_monitor
```
#### &nbsp;&nbsp;&nbsp;Note
&nbsp;&nbsp;&nbsp; If you can't run the command, enter ```bash source cyber/setup.bash``` at /apollo in each terminals.
<br><br>

**In Terminal B**
```bash
./bazel-bin/modules/ethernet/ethernet_receiver
```

**In Terminal C**
```bash
./bazel-bin/modules/ethernet/ethernet_sender
```
<br>

**Run 'client' program of UDP_communication.**

send message what you want.
<br><br>

## Result

<img src="https://user-images.githubusercontent.com/72431755/95432667-ee699b00-0989-11eb-84fc-0f7b489531a1.png" width="50%" height="50%"></img>

