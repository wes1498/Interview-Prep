#include <string>

using namespace std;

string countAndSay(int n) {
    if(n==1){return "1";}
    string str=countAndSay(n-1);
    string ans="";
    int count=1;
    char tmp;
    for (int i=0; i<str.size();){
        if(i+1>=str.size() || str[i]!=str[i+1]){
            ans+=to_string(count)+str[i];
            count=0;
        }
        i++;
        count++;
    }
    return ans;
}

int main() {
    assert(countAndSay(6)=="312211");
    return 0;
}