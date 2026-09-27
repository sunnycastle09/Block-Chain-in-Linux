#include <iostream>
#include "sender.hpp"
#include "recv.hpp"
#include <string>

#int main(){
	botan::socket_r();
	std::cout<<"enter ifindex: ";
	int ifindex;
	std::cin>>ifindex;
	std::cout<<"enter node1 mac_addr: ";
	std::string node1;
	std::cin>>node1;
	std::cout<<"enter node2 mac_addr: ";
	std:string node2;
	std::cin>>node2;
	int port=(int)(buffer[14]);
	if(port==1){
		botan::framing(ifindex,node1,node2,"8b75d19b");
	}

}
