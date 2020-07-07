#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// Given an integer array arr and an integer k, modify the array by repeating it k times.

// For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

// Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

// As the answer can be very large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: arr = [1,2], k = 3
// Output: 9
// Example 2:

// Input: arr = [1,-2,1], k = 5
// Output: 2

int kConcatenationMaxSum(vector<int>& arr, int k) {
    int M = 1000000007; 
    if(arr.size()==0){return 0;}
    
    long long answer=0;
    long long sum = accumulate(arr.begin(),arr.end(),0)%M;
    
    // Kadanes Algorithm for k=1
    long long max_so_far=0;
    for(int i=0;i<arr.size(); i++) {
        max_so_far += arr[i];
        if(max_so_far>=M){
            max_so_far%=M;
        }
        if(max_so_far<0) {
            max_so_far=0;
        } else {
            answer = max(answer,max_so_far);
        }
    }
    
    if(k==1){return answer%M;}
    
    long long answer2 = answer;
    // try with 2 arrays concatenated
    for(int i=0;i<arr.size(); i++) {
        max_so_far += arr[i];
        if(max_so_far>=M){
            max_so_far%=M;
        }
        if(max_so_far<0) {
            max_so_far=0;
        } else {
            answer = max(answer,max_so_far);
        }
    }
    //compute three values that can possibly be the answers
    long long res = max(answer, answer2);
    if(sum > 0)
        res = max(res, ((answer + ((sum * (k-2))%M))%M));
        
    //return the answer
    return res;
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    if (kConcatenationMaxSum(arr,3)==9) {
        printf("Max sum subarray of k times is 9\n");
    }
    assert(kConcatenationMaxSum(arr,3)==9);
    return 0;
}