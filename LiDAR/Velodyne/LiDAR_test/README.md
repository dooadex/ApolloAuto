## Note
Velodyne LiDAR is connected to an Ethernet port.

So you have to configure some network setting.
<br>

## Prerequisites
Ubuntu, ROS1
<br>

## Configure for Ethernet communication

### Configure Network setting of Ubuntu
You can refer to (http://wiki.ros.org/velodyne/Tutorials/Getting%20Started%20with%20the%20Velodyne%20VLP16) for detail. (I referred this site.)

Access the Gnome Menu (Super key), type "Networks Connections" then run it. Select the connection's name and click on "edit". Choose the IPV4 Settings tab and change the "Method" field to "Manual".

Click on "add" and set the IP address field to 192.168.1.100 (“100” can be any number except in a range between 1 and 254, except 201).

Set the “Netmask” to 255.255.255 and the "Gateway" to 0.0.0.0.

To finish it click on "save".

<img src ="https://user-images.githubusercontent.com/72431755/95305938-a2ebba00-08c1-11eb-8bf3-1707aabb2a73.png" width="50%" height="50%"></img>
<br>

### setting communication setting
At /opt/ros/melodic/share/velodyne_pointcloud/launch

edit the launch file what you want like 'VLP16_points.launch'.

for example:

<code>\<arg name="port" default="2370" /\></code>

<br>

Join 192.168.1.100 through web browser, and check IP/PORT of Velodne Lidar. 

for example: \<ip 203, port 2370 \>
<br>

## Test 
### velodyne launch files to test
```bash
roslaunch velodyne_pointcloud VLP16_points.launch
```

### Vizualize the data
```bash
rviz
```
Click add button, then choose pointcloud2.

In Global Option tab, type the channel what you want in Fixed Frame, (ex. map --> /velodyne).

At PointClou2 tab, change the value of Topic:/velodyne_points

#### Result
<img src="https://user-images.githubusercontent.com/72431755/95299366-8e56f400-08b8-11eb-8edd-5c5225037dbd.png" width="50%" height="50%"></img>


## Logging Lidar message.
### To log
```bash
rosbag record -a
```
### To play logged message
```bash
roscore
rosbag play .bag
rostopic echo /velodyne_points
```
