#include <iostream>
#include <cassert> 
#include <unordered_map>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s2.size() < s1.size()){return false;}
    
    // store a count for each char in string
    unordered_map<char, int> table;
    for(auto s : s1){
        table[s]++;
    }
    int begin=0,end=0,counter=table.size();
    
    while(end < s2.length()) {
        char endChar = s2[end];
        if(table.count(endChar) == 1) {
            table[endChar]--;
            if(table[endChar] == 0){counter--;}
        }
        end++;
        
        while(counter == 0) {
            if(end - begin == s1.length()) {
                return true;
            }
            
            char startChar = s2[begin];
            if(table.count(startChar) == 1) {
                table[startChar]++;
                if(table[startChar]>0){counter++;}
            }
            begin++;
        }
    }
    return false;   
}

int main() {
    assert(checkInclusion("ab","eidbaooo") == true);
    return 0;
}