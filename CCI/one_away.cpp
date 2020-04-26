#include<iostream>
#include <string>

using namespace std;
/*
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
EXAMPLE
p a l e , pie -> true
p a l e s , pale -> true
p a l e , bale -> true
p a l e , bake -> false
*/

bool oneAway(string edit, string edited) {
    int changes=0;
    if (edit.size() - edited.size() >= 2) {
        return false;
    }
    int i=0;
    int j=0;
    while (i<edit.size() && j<edited.size()) {
        if (edit[i] != edited[j]) {
                if(changes == 1) {
                    return false;
                }
                if (edit.size() > edited.size()) {
                    i++;
                } else if (edit.size() < edited.size()) {
                    j++;
                } else {
                    //both are the same length
                    i++;
                    j++;
                }
                changes++;
            } else {
                i++;
                j++;
            }
    }
    // if (i < edit.size() || j < edited.size()) 
    //     changes++; 
  
    return changes == 1 || changes == 0; 
}

int main() {
    string edit = "pales";
    string edited = "pale";

    if (oneAway(edit, edited) == false) {
        cout << "one away is false " << '\n';
    } else {
        cout << "one away is true " << '\n';
    }

    return 0;
}