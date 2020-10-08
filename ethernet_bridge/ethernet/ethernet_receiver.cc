#include "cyber/cyber.h"
#include "modules/ethernet/proto/ethernet_test.pb.h"
#include "cyber/node/node.h"
#include "cyber/node/reader.h"
#include "string"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#define BUFSIZE 512
using namespace std;
 
using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::ethernet_test::SAMPLE_STRING;

int main(int argc, char *argv[]) {
  // init cyber framework
  apollo::cyber::Init(argv[0]);
  // create writer node
  auto writer_node = apollo::cyber::CreateNode("writer");
  // create writer
  auto writer = writer_node->CreateWriter<SAMPLE_STRING>("ethernet_test/SAMPLE_STRING");

  Rate rate(1.0);
  uint64_t seq = 0;

  int socket_descriptor=socket(AF_INET, SOCK_DGRAM, 0); 
  ssize_t return_value = 0;

     sockaddr_in serveraddr;
     bzero(&serveraddr, sizeof(serveraddr)); //Initialize to zero
     serveraddr.sin_family=AF_INET;
     serveraddr.sin_port=htons(8901); //transform host Byte order into Network Byte order(Big Endian)
     serveraddr.sin_addr.s_addr=htonl(INADDR_ANY); //transform host Byte order into Network Byte order(Big Endian)
     return_value=bind(socket_descriptor, (sockaddr*)&serveraddr, sizeof(serveraddr)); //designate IP address and Port number for socket.
     
     // variables for communication with clients.
     sockaddr_in clientaddr;
     int addrlen = 0;
     char buf[BUFSIZE+1];
     char can_byte[8];

    while (apollo::cyber::OK()) {

    addrlen=sizeof(clientaddr);
    //return value is length of recieved Byte
 
    return_value=recvfrom(socket_descriptor, buf, BUFSIZE, 0, (sockaddr*)&clientaddr, (socklen_t*)&addrlen);

    //print recieved data
    buf[return_value]='\0';
    //inet_ntoa == transform network Byte order(Big Endian) to Decimal address.
    //ntohs == transform Network Byte order(Big Endian) into host Byte order. 
    cout << "[UDP/" << inet_ntoa(clientaddr.sin_addr) << ":" << ntohs(clientaddr.sin_port) << "] " << buf << endl;


    // CAN test ------
    copy(buf, buf+8, can_byte);  
    for(int i=0;i<8;i++){
        cout << "[" << i << "]: " << can_byte[i] << " " << endl;
    }

    auto msg = std::make_shared<SAMPLE_STRING>();
       
    msg->set_timestamp(Time::Now().ToNanosecond());
    msg->set_seq(seq);
    msg->set_test_data(can_byte);

    writer->Write(msg);
    seq++;
    rate.Sleep();
  }
  close(socket_descriptor);

  return 0;
}
