# GNSS test with NovAtel
This is for test the GNSS system is operated well in LINUX with NovAtel product.

### Environment
LINUX, ROS1

NovAtel: NovAtel Receiver(I used PwrPak7D), Receiver(Anttena)


### Prerequisites
#### Basic setup
If you didn't do anything yet with NovAtel, refer to (https://github.com/dooadex/Autonomous-Driving/blob/master/GNSS/NovAtel/basic_setup.md)
#### Binary mode
Set getting data format of Novatel as Binary.


## Test

### Make workspace
At ${HOME}
<code>mkdir novatel</code>

### Change access permission of USB file for novatel.
<code>chmod 777 /dev/ttyUSB0</code>

### Install novatel ros driver.
Refer to (https://github.com/swri-robotics/novatel_gps_driver) for detail.

```bash
sudo apt-get install ros-${ROS_DISTRO}-novatel-gps-driver
```
```bash
mkdir -p novatel/src
cd novatel
catkin init
catkin config --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo
cd src
git clone https://github.com/swri-robotics/novatel_gps_driver
rosdep install . --from-paths -i
catkin build
```

### launch gps laucnh files to test.
```bash
roslaunch novatel_gps_driver tester_for_usb.launch
```

### Check rostopic
```bash
rostopic list
rostopic echo /fix
```

## How to log the GNSS message.
### To log
```bash
rosbag record -a
```
### To play logged message
```bash
roscore
rosbag play .bag
rostopic echo /fix
```
