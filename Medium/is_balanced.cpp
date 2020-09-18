#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string, int> lhs_elem_count;
unordered_map<string, int> rhs_elem_count;

vector<string> getReaction(string s) {
    vector<string>ret;
    size_t equal_position = s.find('=');
    if(equal_position!=std::string::npos) {
        ret.push_back(s.substr(0,equal_position));
        s.erase(0,equal_position+1);
    }
    ret.push_back(s);
    return ret;
}

vector<string> getMolecules(string s) {
    vector<string>ret;
    size_t equal_position;
    // while loop keeps storing molecules as long as + are found, delete after each time found
    while((equal_position = s.find('+'))!=std::string::npos) {
        ret.push_back(s.substr(0,equal_position));
        s.erase(0,equal_position+1);
    }
    ret.push_back(s);
    return ret;
}

void countElements(vector<string> molecules, int side) {
    for(auto m : molecules) {
        int coefficient = 0;
        for(int i=0; i<m.size(); i++) {
            if(m[i] == ' '){continue;}
            while(m[i] >= '0' && m[i] <= '9') {
                int digit = m[i]-'0';
                // first digit is most significant, so
                //(coefficient << 3) + (coefficient << 1)
                coefficient = coefficient*10 + digit;
                i++;
            }
            coefficient = coefficient == 0 ? 1 : coefficient;
            
            string element = "";
            int counter = 0;
            if(m[i] <= 'Z' && m[i] >= 'A') {
                element+=m[i];
                i++;
                while(m[i] <= 'z' && m[i] >= 'a'){
                    element+=m[i];
                    i++;
                }
                while(m[i] >= '0' && m[i] <= '9') {
                    int digit = m[i]-'0';
                    // first digit is most significant, so
                    //(coefficient << 3) + (coefficient << 1)
                    counter = counter*10 + digit;
                    i++;
                }
                i--;
            }
            counter = counter == 0 ? 1 : counter;
            if(element != "") {
                if(side == 0){
                    lhs_elem_count[element] += counter * coefficient;
                } else {rhs_elem_count[element] += counter * coefficient;}
            }
            
        }
    }
}

bool isReactionBalanced(std::string s) {
    // string manipulation: 
    // 1. you need to split the reaction string based on character "="
    vector<string> chemicals = getReaction(s);
    if(chemicals.size() != 2){return false;}
    // 2. next you need to get the molecules in the reaction sides based on character "+"
    vector<string> lhs = getMolecules(chemicals[0]);
    //for(auto c : lhs){cout<<c<<endl;}
    vector<string> rhs = getMolecules(chemicals[1]);
    
    // 3. Count the elements in each side (lhs, rhs) based on:
    //          Element found when:
    //              1. capital letter next
    //              2. space next
    //              3. end of string next
    //              4. number next
    // store each elements occurrences in a table
    countElements(lhs, 0);
    countElements(rhs, 1);
    
    // 4. Check each row in lhs,rhs tables and see if their elements & count matches
    for(auto& row : lhs_elem_count) {
        //cout<<row.first << " | " << row.second << endl;
        if(rhs_elem_count.find(row.first) == rhs_elem_count.end()){
            cout<<"here"<<endl;
            return false;
        }
        // if found, subtract element count from rhs_elem_count
        rhs_elem_count[row.first] -= row.second;
    }
    for(auto& row : rhs_elem_count) {
        if(row.second != 0){
            cout<<"here2"<<endl;
            return false;}
    }
    return true;
}
