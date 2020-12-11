
# ApolloAuto GNSS setup and test

## Prerequisites
Apollo 5.0, Ubuntu16.04

<br>

## Setting
### Configure the command format

Set the command format(getting data format) of Novatel as Binary. (You can refer to (https://docs.novatel.com/oem7/Content/PDFs/OEM7_Commands_Logs_Manual.pdf))

<br>

### Edit gnss_conf.pb.txt file.

The location of file is <code>${HOME}/apollo/modules/drivers/gnss/conf</code>

The format must be NOVATEL_BINARY like below.

<img src="https://user-images.githubusercontent.com/72431755/95695697-4991db00-0c73-11eb-964a-e92a19d38378.png" width="50%" height="50%"></img>

<br>
You need to edit the 'device' part.

For example, device: "/dev/novatel1" -> "/dev/ttyUSB0" like below.

<img src="https://user-images.githubusercontent.com/72431755/95695758-72b26b80-0c73-11eb-9b67-d7f03226954d.png" width="50%" height="50%"></img>

<br>
Then comment out the 'rtk_from' part like below.

<img src="https://user-images.githubusercontent.com/72431755/95695773-8231b480-0c73-11eb-94f6-35a2b7455899.png" width="50%" height="50%"></img>

<br>


### Change access permisstion of USB file

<code>chmod 777 /dev/ttyUSB0</code>

<br>

## Test
### Launch gnss.launch file to test

<code>cyber_launch start /modules/drivers/gnss/launch/gnss.launch</code>

### Run cyber_monitor to check the message

<code><cyber_monitor/code>
## How to log the GNSS message
### To log
<code>cyber_recorder record -a</code>

### To play
<code>cyber_recorder record play -f ~.record</code>
