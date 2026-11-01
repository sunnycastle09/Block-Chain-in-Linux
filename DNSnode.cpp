#include <iostream>
#include <fstream>
#include <string>
#include "botan.hpp"
class address{
public:
    std::string node1_mac=std::string(13,'\0');
    std::string node2_mac=std::string(13,'\0');
    std::string node3_mac=std::string(13,'\0');
    std::string User_mac=std::string(13,'\0');
    std::string DNS_mac=std::string(13,'\0');
    std::string node1_addr=std::string(9,'\0');
    std::string node2_addr=std::string(9,'\0');
    std::string node3_addr=std::string(9,'\0');
    std::string User_addr=std::string(9,'\0');
};

int main(){
    std::ifstream file("DNS_setting.txt");
    std::string line;
    std::cout<<"enter Interface index: ";
    int if_idx;
    std::cin>>if_idx;
    address addr;
    std::getline(file, addr.node1_mac);
    std::getline(file, addr.node2_mac);
    std::getline(file, addr.node3_mac);
    std::getline(file, addr.User_mac);
    std::getline(file, addr.DNS_mac);
    std::getline(file, addr.node1_addr);
    std::getline(file, addr.node2_addr);
    std::getline(file, addr.node3_addr);
    std::getline(file, addr.User_addr);
    std::string payload="1 "+addr.node1_mac+addr.node2_mac+addr.node3_mac+addr.User_mac+addr.node1_addr+addr.node2_addr+addr.node3_addr+addr.User_addr;
    botan::framing(if_idx,addr.node1_mac,addr.DNS_mac,payload);
}
