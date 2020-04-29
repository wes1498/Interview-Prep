#include <iostream>
#include <vector>
#include <stack>
#include <cassert> 

using namespace std;

int mctFromLeafValues(vector<int>& arr) {
    stack<int> stack;
    stack.push(INT_MAX);
    int result=0;
    for(int i=0; i<arr.size(); i++) {
        while(arr[i]>stack.top()){
            int temp = stack.top();
            stack.pop();
            result += temp * min(arr[i],stack.top());
        }
        stack.push(arr[i]);
        
    }
    while(stack.size()>=3){
        int temp = stack.top();
        stack.pop();
        result += temp * stack.top();
    }
    return result;
}

int main() {
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(15);
    arr.push_back(5);
    arr.push_back(2);
    assert(mctFromLeafValues(arr) == 175);
    
    return 0;
}