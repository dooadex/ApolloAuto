
## Note
This Document is for RTK setup.

I'm living in Korea now, so all the environments are fit on Korea.

However, even if you are forigner, you can use this usefully.


## NovAtel Set up
### Run NovAtel connect
Enter the following command in the console.

<code>log com2 gpgga ontime 5</code> &nbsp;&nbsp;// Output gpgga data to COM2 port of receiver every 5seconds.

<code>com com2 115200 n 8 1 n off off</code> &nbsp;&nbsp;// Configure baud rate of COM2 port of receiver. This is needed to synchronize with Ntrip program.

<code>interfacemode com2 rtcm novatel off</code> &nbsp;&nbsp;// The COM2 port of receiver will get data as RTCM format.

## NTRIP Set up
Refer to (http://gnssdata.or.kr/rtcm/getRtcmView.do) for detail.

This is documentation for NTRIP usage. (http://gnssdata.or.kr/board/getDataItem.do?brdSeq=21&count=1)

### Download NTRIP
You can download the NTRIP program here. (http://gnssdata.or.kr/board/getDataItem.do?brdSeq=12&count=1)

or

I attached the program in my github.


