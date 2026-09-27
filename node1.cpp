#include <iostream>
#include "recv.hpp"
#include "sender.hpp"
#include <cstring>

class UTXO{
	std::string adress;
	float value;
	std::string UTXO_ID;
	std::string origin_sig
	std::string encryto_sig; 	
};
class address{
	std::string node1_mac;
	std::string node2_mac;	
	std::string node3_mac;
	std::string User_mac;
	std::string node1_addr(9,'\0');
	std::string node2_addr(9,'\0');
	std::string node3_addr(9,'\0');
	std::string User_addr(9,'\0');
};
int main(){
	class addr;
	std::cout<<"Enter Mac address\nnode1: ";
	std::cin>>addr.node1_mac;
	std::cout<<"node2: ";
	std::cin>>addr.node2_mac;
	std::cout<<"node3: ";	
	std::cin>>addr.node3_mac;
	std::cout<<"Uesr: "
	std::cin>>addr.User_mac;	
	botan::socket_s();
	std::cout<<"enter ifindex: ";
	int ifindex;
	std::cin>>ifindex;	
	botan::framing(ifindex,addr.node2_mac,addr.node1_addr,"1");
	int size=botan::recv();
	std::memcpy(addr.node2_mac.data(),botan::buffer+14,8);
	std::cout<<addr.node2_mac;
	
}
