#include <iostream>
#include "botan.hpp"
#include <cstring>
#include <string>
#include <fstream>

class UTXO{
public:
    std::string adress;
    float value;
    std::string UTXO_ID;
    std::string origin_sig;
    std::string encryto_sig;
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
	std::ifstream file("mac_addr",line);
	addr.node1_mac=std::getline(file,line);
	addr.node2_mac=std::getline(file,line);
	addr.node3_mac=std::getline(file,line);
	addr.User_mac=std::getline(file,line);
	std::cout<<addr.node1_mac<<"\n"<<addr.node2_mac<<"\n"<<addr.node3_mac<<"\n"<<addr.User_mac;

	
}
