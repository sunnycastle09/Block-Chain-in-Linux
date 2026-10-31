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
    std::string node1_mac=std::string(13,'\0');
    std::string node2_mac=std::string(13,'\0');
    std::string node3_mac=std::string(13,'\0');
    std::string User_mac=std::string(13,'\0');
    std::string node1_addr=std::string(9,'\0');
    std::string node2_addr=std::string(9,'\0');
    std::string node3_addr=std::string(9,'\0');
    std::string User_addr=std::string(9,'\0');
};

int main(){
	address addr;
	std::string line;
	std::ifstream file("node_addr");
	std::getline(file,addr.node1_mac);
	std::getline(file,addr.node2_mac);
	std::getline(file,addr.node3_mac);
	std::getline(file,addr.User_mac);
	addr.node1_addr="92934949";
	std::vector<UTXO> utxo;
	utxo.push_back(UTXO(addr.node1_addr,100));
	std::cout<<"address: "<<utxo[0].address<<"\nvalue: "<<utxo[0].value<<"\nUTXO ID: "<<utxo[0].UTXO_ID.substr(0,64);
}

std::string hash256(std::string str){
	std::string cmd="echo \""+str+"\" | openssl dgst -sha256";
		FILE * f=popen(cmd.c_str(),"r");
		char buffer[100];
		fgets(buffer,sizeof(buffer),f);
		pclose(f);
		return std::string(buffer+17,64);
}
