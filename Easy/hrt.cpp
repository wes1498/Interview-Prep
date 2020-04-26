// SOLUTION 1
// you can use includes, for example:
// #include <algorithm>
#include <stdio.h>
#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A) {
    // instead of iterating each digit as is, I decided to convert to a string
    std::string str = std::to_string(A);
    for (unsigned int i=0; i<str.size(); i++){
        // if first digit is 6, always make it into 9 since it'll be highest
        if (str[i] == '6' && i==0) {
            str[i] = '9';
            break;
        // convert the first 6 you encounter to a 9 (highest order)
        } else if (str[i] == '6') {
            str[i]= '9';
            break;
        }
    }
    // if none, (only 9's) return itself
    std::string::size_type sz; 
    return stoi(str,&sz);
}

// SOLUTION 2
// you can use includes, for example:
// #include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void addToRes(string& res, int n, char c){
    while(n>0){
        res+= c;
        n--;
    }
}
string getDiversity(std::priority_queue<pair<int,char>> queue){
    string res ="";
    char ptr='*';
    while (!queue.empty()) {
        pair<int, char> pair1 = queue.top();
        queue.pop();
        // ptr is used if priority pair equals current char in res, to avoid breaking diversity ('aaa'), you switch out for the second highest priority in queue
        if (pair1.second == ptr){

            if (!queue.empty()){
                pair<int, char> pair2 = queue.top();
                queue.push(pair1);
                pair1 = pair2;
                // if queue is empty, dont bother adding the highest priority to maintain diversity
            }else {break;}
        }
        // highest priority remove 2 from first
        if (pair1.first >= 2) {
            addToRes(res,2,pair1.second);
            pair1.first = pair1.first-2;
            
        } else if (pair1.first ==1 ) {
            addToRes(res,1,pair1.second);
            pair1.first = pair1.first-1;
        }
        if (!queue.empty()) {
            pair<int, char> pair3 = queue.top();
            queue.pop();
            
            addToRes(res,1,pair3.second);
            pair3.first = pair3.first-1;
            
            ptr=pair3.second;
            if(pair3.first>0){
                queue.push(pair3);
            }
            if (pair1.first >0) {
                queue.push(pair1);
            }
        } else {break;}
    }
    return res;
}

string solution(int A, int B, int C) {
    // data structure uses a priority queue to keep largest pair infront
    // each time, I will take out 2 from largest, then grab second pair and take one, add back to queue until pair.first=0 (leave removed)
    std::priority_queue<pair<int, char>> queue;
    if (A>0){queue.push({A,'a'});}
    if (B>0){queue.push({B,'b'});}
    if (C>0){queue.push({C,'c'});}
    return getDiversity(queue);
}




// SOLUTION 3
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
char checkInsert(string &S, string &T){
    //check if S is already bigger
    if (S.size()+1 != T.size()){return NULL;}
    for (unsigned int i=0; i<T.size(); i++) {
        if (S[i] != T[i]){
            string temp = S.substr(0,i) + T[i] + S.substr(i,S.size());
            if (temp.compare(T) == 0) {
                return T[i];
            } else {return NULL;}
        }
        if (i == T.size()-1) {
            string temp = S + T[i];
            if (temp.compare(T) == 0) {
                return T[i];
            } else {return NULL;}
        }
    }
    return NULL;
    
}
char checkRemove (string &S, string &T) {
        //check if S is already bigger
    if (S.size()-1 != T.size()){return NULL;}
    for (unsigned int i=0; i<S.size(); i++) {
        if (S[i] != T[i]) {
            string temp = S.substr(0,i) + S.substr(i+1,S.size());
            if (temp.compare(T)==0) {
                return S[i];
            }else {return NULL;}
        }
        if (i == S.size()-1) {
            string temp = S.substr(0, S.size()-1);
            if (temp.compare(T)==0){
                return T[i];
            } else {return NULL;}
        }
    }
    return NULL;
}
void swap(string &S, int i, int j) {
    char temp = S[i];
    S[i] = S[j];
    S[j] = temp;
}
string checkSwap(string &S, string &T) {
    string ret = "";
    if (S.size() != T.size()){return ret;}
    for (unsigned int i=0; i<S.size()-1; i++) {
        swap(S,i,i+1);
        if (S.compare(T)==0) {
            return ret + S[i+1] + ' ' + S[i];
        } else {swap(S,i,i+1);}
    }
    return ret;
}

string solution(string &S, string &T) {
    // write your code in C++14 (g++ 6.2.0)
    if (S.compare(T) == 0){return "EQUAL";}
    
    char res = checkInsert(S,T);
    string func = "INSERT ";
    if (res != NULL){ return func + res;}
    
    res = checkRemove(S,T);
    func = "REMOVE ";
    if (res != NULL){ return func + res;}
    
    string res2 = checkSwap(S,T);
    func = "SWAP ";
    if (!res2.empty()){ return func + res2;}
    
    return "IMPOSSIBLE";
}
