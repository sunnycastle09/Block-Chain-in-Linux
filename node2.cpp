#include <iostream>
#include "sender.hpp"
#include "recv.hpp"
#include <string>

int main(){
	botan::socket_r();
	std::cout<<"enter ifindex: ";
	int ifindex=6;
	std::string node1="7af4b31d278e";
	std::string node2="5eee4440467a";
	botan::recv();
	int port=(int)(botan::buffer[14]);
	if(port==1){
		botan::framing(ifindex,node1,node2,"8b75d19b");
	}

}
