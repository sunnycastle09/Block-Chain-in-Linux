#include <iostream>
#include <cstdlib>
#include <sstream>

int main(){
	std::cout<<"File: ";
	std::string f;
	std::cin>>f;
	std::stringstream a(f);
	std::string t;
	while(a>>t)
		system("(\"git add \"+t).c_str()");
	system("git commit -m \".\" && git push origin master");
	
}
