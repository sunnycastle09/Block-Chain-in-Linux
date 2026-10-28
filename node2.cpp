#include <iostream>
#include <string>
#include "botan.hpp"

int main() {
	botan::socket();
	int size = botan::recv();
	if (size < 0) {
  		return 1;
	}
	std::string port(
        reinterpret_cast<char*>(botan::buffer + 14),
        size - 14
    	);
	if(port=="1"){
		botan::framing(6,"7af4b31d278e","5eee4440467a","5eee4440467a");
	}
	botan::close_socket();
	return 0;
}
