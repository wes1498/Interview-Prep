#include <iostream>
#include <stack>

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


int getSum(TreeNode* root){
    int sum = 0;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr || !s.empty()) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        sum += curr->val;
        curr = curr->right;
    }
    return sum;
}

TreeNode* convertBST(TreeNode* root) {
    int sum = getSum(root), traverseSum = 0;

    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr || !s.empty()) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        int temp = curr->val;
        curr->val = sum - traverseSum;
        traverseSum += temp;
        curr = curr->right;
    }
    return root;
}

int main() {
    
    return 0;
}