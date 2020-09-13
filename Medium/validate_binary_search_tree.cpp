#include <iostream>
#include <vector>
#include <stack>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:

//      2
//     / \
//    1   3

// Input: [2,1,3]
// Output: true

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root) {
    vector<int> temp;
    if(root == NULL){return true;}
    
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(!s.empty() || curr != NULL) {
        while(curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        temp.push_back(curr->val);
        curr = curr->right;
    }
    for(int i=0; i<temp.size()-1; i++) {
        if(temp[i] >= temp[i+1]){return false;}
    }
    return true;
}

int main() {
    assert(isValidBST(NULL) == true);
    return 0;
}