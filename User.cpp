#include <iostream>
#include <fstream>
#include "sender.hpp"
#include <cstdlib>
#include <string>

int main(){
	botan::socket_s();
	std::cout<<"First operate: 1\nTransaction: 2\nenter: ";
	int a;
	std::cin>>a;
	if(a==1){
		std::cout<<"enter node address\n1: ";
		std::string node1_mac;
		std::cin>>node1_mac;
		std::cout<<"2: ";
       		std::string node2_mac;
		std::cin>>node2_mac;
		std::cout<<"3: ";
		std::string node3_mac;
		std::cin>>node3_mac;
		std::ofstream file("node_mac_addr");
		file<<node1_mac<<"\n"<<node2_mac<<"\n"<<node3_mac;
		std::cout<<"\n\n";
	}
	else{
		std::cout<<"addr list\n1: ";
		system("cat addr1");
		std::cout<<"\n2: ";
		system("cat addr2");
		std::cout<<"\n3: ";
		system("cat addr3");
		std::cout<<"\n4: ";
		system("cat addr4");
		std::cout<<"\n5: ";
		system("cat addr5");	
	}
}
