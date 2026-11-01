#include <iostream>
#include "botan.hpp"
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

std::string hash256(std::string str);
class UTXO{
public:
    std::string address;
    int value;
    std::string UTXO_ID;
    std::string encrypto_sig;
	UTXO(std::string addr,int v){
		address=addr;
		value=v;
		UTXO_ID=hash256(address+std::to_string(value));		
	}
};

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
	address addr;
	while(1){
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
		else
			exit(0);
	}
}

std::string hash256(std::string str){
	std::string cmd="echo \""+str+"\" | openssl dgst -sha256";
		FILE * f=popen(cmd.c_str(),"r");
		char buffer[100];
		fgets(buffer,sizeof(buffer),f);
		pclose(f);
		return std::string(buffer+17,64);
}
