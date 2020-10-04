#include <iostream>
#include <vector>
#include <string>

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
 
class Solution {
private:
    vector<TreeNode*> sorted;
public:
    void addToList(TreeNode* root) {
        if(root->left){addToList(root->left);}
        sorted.push_back(root);
        if(root->right){addToList(root->right);}
    }
    
    TreeNode* balanceBSTUtil(int l, int r) {
        if(l >= r) {return NULL;}
        int mid = (l+r)/2;
        TreeNode* root = sorted[mid];
        root->left = balanceBSTUtil(l,mid);
        root->right = balanceBSTUtil(mid+1,r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root){return root;}
        addToList(root);
        return balanceBSTUtil(0,sorted.size());
    }
};

int main() {
    return 0;
}