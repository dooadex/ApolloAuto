
<h1>Apollo GNSS test</h1>


<h2>Prerequisites</h2>
Apollo 5.0, Ubuntu16.04

<br>

<h2>Setting</h2>
<n3>Configure the command format</h3>

Set the command format(getting data format) of Novatel as Binary. (You can refer to (https://docs.novatel.com/oem7/Content/Commands/Command_Formats.htm?TocPath=Commands%7C_____1))

<br>

<h> Edit gnss_conf.pb.txt file. </h3>

The location of file is <code>${HOME}/apollo/modules/drivers/gnss/conf</code>

The format must be NOVATEL_BINARY like below.

<img src="https://user-images.githubusercontent.com/72431755/95695697-4991db00-0c73-11eb-964a-e92a19d38378.png" width="50%" height="50%"></img>

<br>
You need to edit the 'device' part.

For example, device: "/dev/novatel1" -> "/dev/ttyUSB0" like below.

<img src="https://user-images.githubusercontent.com/72431755/95695758-72b26b80-0c73-11eb-9b67-d7f03226954d.png" width="50%" height="50%"></img>

<br>
Then comment out thr 'rtk_from' part like below.

<img src="https://user-images.githubusercontent.com/72431755/95695773-8231b480-0c73-11eb-94f6-35a2b7455899.png" width="50%" height="50%"></img>

<br>


<h3>Change access permisstion of USB file</h3>

<code>chmod 777 /dev/ttyUSB0</code>

<br>

<h2>Test</h2>
<h3>Launch gnss.launch file to test</h3>

<code>cyber_launch start /modules/drivers/gnss/launch/gnss.launch</code>

<h3>Run cyber_monitor to check the message</h3>

<code><cyber_monitor/code>
  
<h2>How to logr the GNSS message/<h2>
<h3>To log</h3>
<code>cyber_recorder record -a</code>
<br>
<h3>To play</h3>
<code>cyber_recorder record play -f ~.record</code>

