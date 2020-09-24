#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

string defangIPaddr(string address) {
    std::string::iterator it;
    for(it = address.begin(); it != address.end();) {
        if(*it == '.'){
            it = address.insert(it,'[');
            it = address.insert(it+2,']');
            if(it+1 == address.end()){
                return address;
            } else {
                it = it + 2;
            }
        } else {it++;}
        
    }
    return address;
}

int main() {
    assert(defangIPaddr("255.255.255.255") == "255[.]255[.]255[.]255");
}