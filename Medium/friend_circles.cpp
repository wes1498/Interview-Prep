#include <iostream>
#include <vector>
#include <stack>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.

int findCircleNum(vector<vector<int>>& M) {
    if(M.size() == 0) {return 0;}
    
    int n = M.size();
    int m = M[0].size();
    
    vector<vector<int>> adj_list;
    adj_list.resize(n);
    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(M[i][j] == 1 && i != j) {
                adj_list[i].push_back(j);
            }
        }
    }
    int ans=0;
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans++;
            s.push(i);
            while(!s.empty()) {
                int v = s.top();s.pop();
                if(!visited[v]){visited[v]=true;}
                for(auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i) {
                    if(!visited[*i]){s.push(*i);}
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> M;
    vector<int> temp{1,1,0};
    M.push_back(temp);
    M.push_back(temp);
    vector<int> temp1{0,0,1};
    M.push_back(temp1);

    assert(findCircleNum(M) == 2);

    return 0;
}