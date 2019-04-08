#include<iostream>
#include <string>

using namespace std;

/* 
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3, If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
Hints: #92, if 110
*/

string Compress(vector<char>& chars) {

    if (chars.size()<2) {
        return chars.size();
    }
    int counter = 1,j= -1;
    string c = chars[0];
    for (int i=1; i<s.size(); i++ ) {
        if (s[i] == s[i-1]) {
            counter++;
        } else {
            chars[++j] = c;
            if (counter > 1) {
                string s = to_string(counter);
                for(int x=0; x<s.size(); x++ j++) {
                    chars[j++]= s[x];
                }
                counter=1;
                c=chars[i];
            }
            // str.append(s[i-1]);
            // str.append(to_string(counter));
            // counter = 1;
        }
    }
    chars[++j] = c;
    if (counter > 1) {
        string s = to_string(counter);
        for(int x=0;x<s.size();x++, j++) {
            chars[j+1]=s[x];
        }
    }
    for(int i=j +1;i<size;i++) {
        chars.pop_back();
    }
    
    return j+1;
}

int main() {
    string test = "aabcccccaaa";
    string s = Compress(test);
    cout << s << '\n';
}