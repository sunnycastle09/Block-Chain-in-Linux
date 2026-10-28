#include <iostream>
#include <string>
#include "botan.hpp"

int main() {
    botan::socket();

    std::string node1 = "7af4b31d278e";
    std::string node2 = "5eee4440467a";

    // 실제 node1 네임스페이스의 ifindex 확인
    int ifindex = 4;

    std::cout << "Sending frame to node2...\n";

    int sent = botan::framing(
        ifindex,
        node2,  // destination MAC
        node1,  // source MAC
        "1"     // payload
    );

    std::cout << "Sent " << sent << " bytes\n";

    botan::close_socket();
    return 0;
}
