#include <iostream>
#include <string>
#include "botan.hpp"

int main() {
    botan::socket();

    if (botan::fd < 0)
        return 1;

    std::cout << "Waiting for node1...\n";

    int size = botan::recv();

    if (size < 0) {
        botan::close_socket();
        return 1;
    }

    // EtherType 2바이트까지 포함한 이더넷 헤더는 14바이트
    if (size < 14) {
        std::cerr << "Frame too short\n";
        botan::close_socket();
        return 1;
    }

    // EtherType 확인
    if (botan::buffer[12] != 0x88 ||
        botan::buffer[13] != 0xb5) {
        std::cerr << "Unexpected EtherType\n";
        botan::close_socket();
        return 1;
    }

    std::string payload(
        reinterpret_cast<char*>(botan::buffer + 14),
        size - 14
    );

    std::cout << "Received payload: " << payload << '\n';

    botan::close_socket();
    return 0;
}
