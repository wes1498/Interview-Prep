#include<iostream>
#include <vector>
#include <cassert> 

using namespace std;

bool isSubsequence(string s, string t) {
    if (t=="" && s==""){
        return true;
    }
    string::iterator comp = s.begin();
    for(auto sub : t){
        if (*comp == sub){
            comp++;
        }
        if(comp == s.end()){
            return true;
        }
    }
    
    return false;
}

int main() {
    string a="abc";
    string b="ahbgdc";
    assert(isSubsequence(a,b)==true);
    return 0;
}