
## Note
This Document is for RTK setup using VRS.

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


### Configure and Connect with NTRIP
I will proceed with the English version.

#### Run NTRIP program
If you run the NTRIP program, you can see as below.

<img src="https://user-images.githubusercontent.com/72431755/95308547-04615800-08c5-11eb-8aab-ae24da797ecf.png" width="50%" height="50%"></img>


#### Serial Port Setting
Click Edit of Serial Port

<img src="https://user-images.githubusercontent.com/72431755/95405764-a3349580-0953-11eb-8585-c9619e3de573.png" width="50%" height="50%"></img>

Then, set the values corresponding to yours. After that, click Connect.


#### NTRIP Setting
<img src="https://user-images.githubusercontent.com/72431755/95406278-fa873580-0954-11eb-88aa-bbef4cfa09a2.png" width="50%" height="50%"></img>

All of the settings are same with the picure except for \<Username\>.

To use Korean VRS, RTCM system, you need to sign up for National Geographic Information Institute of Korea. (http://www.gnssdata.or.kr/main/getMainView.do)

Then, search NTRIP base station, and choose what you want. (ex. INCH-RTCM32)

<img src="https://user-images.githubusercontent.com/72431755/95407346-b6496480-0957-11eb-9d87-61233defc85a.png" width="50%" height="50%"></img>

After you enter all the information, click Connect.
<br>

## Check it works

To check whether it works or not, follow below.

Open NovAtel Connect, and see or click the 'Position' window.

<img src="https://user-images.githubusercontent.com/72431755/95407784-f9f09e00-0958-11eb-8763-244e58fad2e5.png" width="80%" height="80%"></img>

If the solution type is 'Narrow Integer' or 'Narrow Float', It's fine.

And the deviation of 'Heigt', 'Longitude', 'Latitude' will be under 0.05m. (might be around 0.02m)
