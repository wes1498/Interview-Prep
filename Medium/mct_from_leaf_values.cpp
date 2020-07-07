#include <iostream>
#include <vector>
#include <stack>
#include <cassert> 

using namespace std;

// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

// Example 1:

// Input: arr = [6,2,4]
// Output: 32
// Explanation:
// There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

//     24            24
//    /  \          /  \
//   12   4        6    8
//  /  \               / \
// 6    2             2   4

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