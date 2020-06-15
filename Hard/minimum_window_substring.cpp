#include <iostream>
#include <cassert> 
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> mymap;
    if(t.length() > s.length()){return "";}
    for(auto c : t){
        mymap[c]++;
    } 
    int len=INT_MAX;
    int start=0,end=0;
    int count = mymap.size();
    string result="";
    
    while(end!=s.length()){
        char endChar = s[end];
        if(mymap.find(endChar)!=mymap.end()){
            mymap[endChar]--;
            if(mymap[endChar]==0){count--;}
        }
        end++;
        // while count=0, check whether the end-begin < len 
        while(count==0){
            if(end-start < len){
                len = end-start;
                result = s.substr(start,end-start);
            }
            //check if the s[begin] is in the map, if it isn't then we just eliminate it
            // if it is, then we still eliminate it, but increment the mymap[s[begin]], 
            // and the counter if mymap[s[begin]] > 0
            char beginChar = s[start];
            if(mymap.count(beginChar) == 1){
                mymap[beginChar]++;
                if(mymap[beginChar] > 0){count++;}
            }
            start++;
        }
    }
    return result;
}

int main() {
    string s ="ADOBECODEBANC";
    string t="ABC";
    assert(minWindow(s,t)=="BANC");
    return 0;
}