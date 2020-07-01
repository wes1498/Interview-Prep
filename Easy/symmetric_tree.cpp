#include <iostream>
#include <vector>
#include <queue>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root) {
    if (root == NULL) {return true;}
    
    TreeNode* null = new TreeNode(-1);
    queue<TreeNode*> left, right;
    left.push(root->left);
    right.push(root->right);
    
    while(!left.empty() && !right.empty()) {
        TreeNode* leftNode = left.front();
        TreeNode* rightNode = right.front();
        left.pop();right.pop();
        if((!leftNode && rightNode) || (!rightNode && leftNode)){return false;}
        if(leftNode && rightNode) {
            if(leftNode->val != rightNode->val) {return false;}
            left.push(leftNode->left);
            left.push(leftNode->right);
            right.push(rightNode->right);
            right.push(rightNode->left);
        }
    }
    return true;
}

int main() {
    assert(isSymmetric(NULL) == true);
    return 0;
}