#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void get_shift_number(int &key) {
    cout <<  "Enter a shift number\n";
    cin >> key;
    return;
}
char shift(char orig, int shift) {
    int pos=(int)orig+shift;
    if(pos>(int)'Z'){
        shift =pos-(int)'Z';
        char place = 'A'+ shift-1;
        return place;
    }
    return orig+=shift;
}
string get_msg(string filename) {

    std::ifstream ifs(filename);
    std::string content((std::istreambuf_iterator<char>(ifs)),
                                (std::istreambuf_iterator<char>()));
    return content;
    
}

string encrypt_msg(int key, string msg) {
    string ret="";
    char shifted;
    for (int i=0; i<msg.length(); i++) {
        if (isdigit(msg[i])) {
            ret+=msg[i];
        } else if (isalpha(msg[i])) {
            if (islower(msg[i])) {
                ret += shift(toupper(msg[i]), key);
            } else {
                ret+= shift(msg[i],key);
            }
        }
    }
    return ret;
}
int main() {
    int key=0;
    get_shift_number(key);

    string filename="";
    cout << "what file do you wish to Encrypt\n";
    cin >> filename;
    string filecontent = get_msg(filename);

    string result = encrypt_msg(key, filecontent);
    cout << result + "\n";
    return 0;

}
