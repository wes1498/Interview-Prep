#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

void flatten(TreeNode* root) {
    vector<int> temp;
    if(root == NULL) {return;}
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        temp.push_back(curr->val);
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
    TreeNode* copy = root;
    for(int i = 0; i < temp.size(); i++) {
        copy->left = NULL;
        copy->val = temp[i];
        if(copy->right == NULL && i != temp.size()-1){
            copy->right = new TreeNode(0);
        }
        copy = copy->right;
    }
}

int main() {
    return 0;
}