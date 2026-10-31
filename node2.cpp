#include <iostream>
#include <string>
#include "botan.hpp"
#include <stdio.h>

int main() {
	char buffer[256];
	FILE *fp=popen("whoami","r");
	fgets(buffer,sizeof(buffer),fp);
}
