
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){return new TreeNode(val);}
    TreeNode* node = root;
    TreeNode* new_node = new TreeNode(val);
    while(node) {
        if(node->val < val) {
            if(!node->right){node->right = new_node; break;}
            else{node = node->right;}
        } else {
            if(!node->left){node->left = new_node; break;}
            else{node = node->left;}
        }
    }
    return root;
}
};