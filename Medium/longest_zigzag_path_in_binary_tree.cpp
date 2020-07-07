#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right then move to the right child of the current node otherwise move to the left child.
// Change the direction from right to left or right to left.
// Repeat the second and third step until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
int longestZigZagUtil(TreeNode* root, int r,int &ans,int cur){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        ans=max(ans,cur);
        return max(ans,cur);
    }
    if(r){
        ans=max(ans,cur);
        longestZigZagUtil(root->right,1,ans,1);
        longestZigZagUtil(root->left,0,ans,cur+1);
    }
    else{
        ans=max(ans,cur);
        longestZigZagUtil(root->left,0,ans,1);
        longestZigZagUtil(root->right,1,ans,cur+1);  
        
    }
    return ans;
}

int longestZigZag(TreeNode* root) {
    if(root==NULL){return 0;}
    int an=0;
    return max(longestZigZagUtil(root->right,1,an,1),longestZigZagUtil(root->left,0,an,1));
}


int main(){
    TreeNode* root;
    root->val=1;
    root->left=NULL;
    root->right=NULL;

    assert(longestZigZag(root)==0);
    return 0;
}