#include <iostream>
#include "botan.hpp"
#include <cstring>
#include <string>
#include <fstream>
#include <cstring>
#include <array>

char buffer[50];
int HextoInt(char c);
class UTXO{
public:
    std::string address;
    float value;
    char UTXO_ID[32];
    std::string encrypto_sig;
	UTXO(std::string addr,float v){
		FILE * f=popen("echo "+address+std::to_string(value)+" | openssl dgst -sha256");
		fgets(buffer,sizeof(buffer),f);
		char temp[64];
		std::memcpy(temp.data(),buffer+17,64);
		for(int i=0;i<32;i++){
			UTXO_ID[i]=reinterpret_cast<char>(HextoInt(temp[i*2],temp[(i*2)+1]));
		}
	}
};

class address{
public:
    std::string node1_mac;
    std::string node2_mac;
    std::string node3_mac;
    std::string User_mac;
    std::string node1_addr=std::string(9,'\0');
    std::string node2_addr=std::string(9,'\0');
    std::string node3_addr=std::string(9,'\0');
    std::string User_addr=std::string(9,'\0');
};

int main(){
	address addr;
	std::string line;
	std::ifstream file("mac_addr");
	std::getline(file,addr.node1_mac);
	std::getline(file,addr.node2_mac);
	std::getline(file,addr.node3_mac);
	std::getline(file,addr.User_mac);
	
}
int HextoInt(char a,char b) {
	std::string tmp;
	tmp+=a;
	tmp+=b;
	return std::stoi(tmp);
}
