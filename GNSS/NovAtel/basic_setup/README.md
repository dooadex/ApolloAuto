## NovAtel basic setup
This is for basic setup to use NovAtel product.

You can refer to (https://docs.novatel.com/oem7/Content/PDFs/PwrPak7_Installation_Operation_Manual.pdf)

To use Serial Port Communications, you have to configure properly.

The receiver's default port settings are:
<ul><li>9600 bps</li>
<li>no parity</li>
<li>8 data bits</li>
<li>1 stop bit</li>
<li>no handshaking</li>
<li>echo off</li>
<li>break on</li></ul>


### Install Novatel Connect and USB Driver
Install Novatel Connect and USB Driver at (https://novatel.com/support/firmware-options-pc-software/novatel-connect)


<img src="https://user-images.githubusercontent.com/72431755/95290272-cace2400-08a7-11eb-98ba-680f56a7c53d.png" width="50%" height="50%"></img>


### Connect NovAtel receiver with PC
Connect the receiver of NovAtel with PC using 'USB port'.

### Run NovAtel Connect
To change the settings on a COM port, use the SERIALCONFIG command. 

For example: To change the data rate of COM2 to 115200, enter: <code>SERIALCONFIG COM2 115200</code>
