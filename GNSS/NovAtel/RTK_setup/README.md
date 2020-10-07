
## Note
This Document is for RTK setup.

I'm living in Korea now, so all the environments are fit on Korea.

However, even if you are forigner, you can use this usefully. Because the process is similar with others.
<br>

## NovAtel Set up
### Run NovAtel connect
Enter the following command in the console.

<code>log com2 gpgga ontime 5</code> &nbsp;&nbsp;// Output gpgga data to COM2 port of receiver every 5seconds.

<code>com com2 115200 n 8 1 n off off</code> &nbsp;&nbsp;// Configure baud rate of COM2 port of receiver. This is needed to synchronize with Ntrip program.

<code>interfacemode com2 rtcm novatel off</code> &nbsp;&nbsp;// The COM2 port of receiver will get data as RTCM format.
<br>

## NTRIP Set up
Refer to (http://gnssdata.or.kr/rtcm/getRtcmView.do) for detail.

This is documentation for NTRIP usage. (http://gnssdata.or.kr/board/getDataItem.do?brdSeq=21&count=1)

### Download NTRIP
You can download the NTRIP program here. 
(http://lefebure.com/software/ntripclient/) (English)
(http://gnssdata.or.kr/board/getDataItem.do?brdSeq=12&count=1) (Korean)

or

I attached the program in my repository. (https://github.com/dooadex/Autonomous-Driving/tree/master/GNSS/NTRIP)


I will proceed in English.

If you run the NTRIP program, you can see as below.

<img src="https://user-images.githubusercontent.com/72431755/95308547-04615800-08c5-11eb-8aab-ae24da797ecf.png" width="50%" height="50%"></img>

