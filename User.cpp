#include <iostream>
#include <string>
#include "botan.hpp"

class address{
public:
    std::string node1_mac=std::string(12,'\0');
    std::string node2_mac=std::string(12,'\0');
    std::string node3_mac=std::string(12,'\0');
    std::string User_mac=std::string(12,'\0');
    std::string node1_addr=std::string(8,'\0');
    std::string node2_addr=std::string(8,'\0');
    std::string node3_addr=std::string(8,'\0');
    std::string User_addr=std::string(8,'\0');
};

int main(){
	botan::socket();
	botan::recv();
		if('1'==botan::buffer[14]){
			addr.node1_mac=std::string(botan::buffer+16,12);
			addr.node2_mac=std::string(botan::buffer+28,12);
			addr.node3_mac=std::string(botan::buffer+40,12);
			addr.User_mac=std::string(botan::buffer+52,12);
			addr.node1_addr=std::string(botan::buffer+64,8);
			addr.node2_addr=std::string(botan::buffer+72,8);
			addr.node3_addr=std::string(botan::buffer+80,8);
			addr.User_addr=std::string(botan::buffer+88,8);
		}
}
