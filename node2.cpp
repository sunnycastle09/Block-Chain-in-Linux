#include <iostream>
#include "botan.hpp"
#include <string>

int main(){
	botan::socket();
	int ifindex=6;
	std::string node1="7af4b31d278e";
	std::string node2="5eee4440467a";
	botan::recv();
	char port=botan::buffer[14];
	if(port=='1'){
		botan::framing(ifindex,node1,node2,"helloim2");
	}
}
