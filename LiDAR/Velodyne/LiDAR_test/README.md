## Note
Velodyne is


## Prerequisites
ROS1


## Setting up Velodyne
You can refer to (http://wiki.ros.org/velodyne/Tutorials/Getting%20Started%20with%20the%20Velodyne%20VLP16) for detail.

### Configure communication setting
At /opt/ros/melodic/share/velodyne_pointcloud/launch

edit the launch file what you want like 'VLP16_points.launch'.

for example:

<code>\<arg name="port" default="2370" /\></code>

<br>

Join 192.168.1.101 through web browser, and check IP/PORT of Velodne Lidar. 

&nbsp; // ("101" can be any number except in a range between 1 and 254, except 201)

for example: \<ip 203, port 2370 \>

-------

## Test 
### velodyne launch files to test
```bash
roslaunch velodyne_pointcloud VLP16_points.launch
```

### Vizualize the data
```bash
rviz
```
## Click add, choose pointcloud2, in Global Option tab, type the channel what you want ## in Fixed Frame (ex. map --> /velodyne).
## At PointClou2 tab, change the value of Topic:/velodyne_points

# 5. How to log the Lidar message.
## To log
rosbag record -a
## To play logged message
roscore
rosbag play .bag
rostopic echo /velodyne_points
