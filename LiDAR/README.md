# ApolloAuto Velodyne LiDAR setup and test

## Prerequisites
Apollo 5.0, Ubuntu16.04

<br>

## Setting

### Edit 'velodne~.pb.txt' file in conf dir.

```txt
firing_data_port: yours
use_gps_time: false
use_poll_sync: false
```

### Change the access permission of USB file in /dev dir.
```bash 
chmod 777 /dev/ttyUSB0 
```

<br>

## Launch
### Launch velodyne.launch file.
```bash
cyber_launch start modules/drivers/velodyne/launch/velodyne.launch
```

<br>

## Check
### Run cyber_monitor to check the message
```bash
cyber_monitor
```

<img src="https://user-images.githubusercontent.com/72431755/98070668-e88da980-1ea4-11eb-82f4-98f6e5545126.png" width="50%" height="50%"></img>

### Run visualizer
```bash
cyber_vizualizer
```

#### Click 'Show Pointcloud', and select channel

<img src="https://user-images.githubusercontent.com/72431755/98070812-33a7bc80-1ea5-11eb-80e4-ab0e0761747f.png" width="50%" height="50%"></img>


## How to log the GNSS message
### To log
<code>cyber_recorder record -a</code>

### To play
<code>cyber_recorder record play -f ~.record</code>
