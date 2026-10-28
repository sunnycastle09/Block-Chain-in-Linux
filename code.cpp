#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    std::cout << "(seperate with /)File: ";

    std::string f;
    std::cin >> f;
    int i=0;
    int t=0;
    while(i<f.size()) //  l/ll/  t-2 i-4
    {
        if(f[i]=='/'){
            system((std::string("git add ") + std::string(&f[t],i-t)).c_str());
            t=i+1;
        }
        i++;
    }
    system("git commit -m \".\" && git push origin master");
}
