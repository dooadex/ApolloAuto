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
#include <typeinfo>

using namespace std;

void MessageCallback(const std::shared_ptr<apollo::ethernet_test::SAMPLE_STRING>& msg) {
  // --- create socket() ---
  //(address system, socket type, protocol) AF_INET == IPv4, SOCK_DGRAM == UDP, return socket descriptor 
  int socket_descriptor=socket(AF_INET, SOCK_DGRAM, 0);
  
  // --- bind() ---
  //socket structure sockaddr_in: sin_familty(address system), sin_port(port_number), sin_addr(32bit IP address), sin_zero[8](not used)
  sockaddr_in client_addr;
  bzero(&client_addr, sizeof(client_addr)); //Initialize to zero
  client_addr.sin_family=AF_INET;
  client_addr.sin_port=htons(8901); //transform host Byte order into Network Byte order(Big Endian)
  client_addr.sin_addr.s_addr=inet_addr("IP Address"); //IP address where you want to send, for example ("192.168.0.7")
  
  const char* sending_data = msg->test_data().c_str();
  ssize_t return_value;
  
  if(sending_data==NULL){return;}
  if(strlen(sending_data)==0) {return;}

  return_value = sendto(socket_descriptor, sending_data, strlen(sending_data), 0, (sockaddr*)&client_addr, sizeof(client_addr));
  cout << endl << "Sent message -> " << msg->test_data() << endl;
  cout << "[UDP Client] " << return_value << "Byte sent." << endl;
  
}

int main(int argc, char* argv[]) {

  //init_socket();

  // init cyber framework
  apollo::cyber::Init(argv[0]);
  // create listener node
  auto reader_node = apollo::cyber::CreateNode("reader");
  // create listener
  auto reader = reader_node->CreateReader<apollo::ethernet_test::SAMPLE_STRING>("ethernet_test/SAMPLE_STRING", MessageCallback);

  apollo::cyber::WaitForShutdown();
  return 0;
}
