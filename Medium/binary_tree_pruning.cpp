#include <iostream>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;
  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

bool postOrder(TreeNode* root) {
    if(!root){return false;}
    bool left_subtree = postOrder(root->left);
    if(!left_subtree){root->left = NULL;}
    bool right_subtree = postOrder(root->right);
    if(!right_subtree){root->right = NULL;}
    if(right_subtree || left_subtree || root->val) {return true;}
    
    return false;
}

TreeNode* pruneTree(TreeNode* root) {
    if(!root) {return NULL;}
    if(!postOrder(root)){return NULL;}
    return root;
}
int main() {

    return 0;
}