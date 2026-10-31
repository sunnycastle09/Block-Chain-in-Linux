#include <iostream>
#include "botan.hpp"
#include <cstring>
#include <string>
#include <fstream>
#include <vector>

char buffer[100];
int HextoInt(char a,char b);
class UTXO{
public:
    std::string address;
    int value;
    char UTXO_ID;
    std::string encrypto_sig;
	UTXO(std::string addr,int v){
		address=addr;
		value=v;
		std::string cmd="echo \""+address+std::to_string(value)+"\" | openssl dgst -sha256";
		FILE * f=popen(cmd.c_str(),"r");
		fgets(buffer,sizeof(buffer),f);
		pclose(f);
		std::memcpy(UTXO_ID.data(),buffer+17,64);
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
	std::cout<<"address: "<<utxo[0].address<<"\nvalue: "<<utxo[0].value<<"\nUTXO ID: ";
	for(int i=0;i<32;i++)
		std::cout<<utxo[0].UTXO_ID[i];
}
int HextoInt(char a,char b) {
	std::string tmp;
	tmp+=a;
	tmp+=b;
	return std::stoi(tmp,nullptr,16);
}
