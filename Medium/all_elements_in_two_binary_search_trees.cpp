#include <iostream>
#include <vector>
#include <stack>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

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

class Solution {
private:
    vector<int> result;
public:
    Solution() = default;
    void inOrder(TreeNode* root, vector<int>& bst) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            bst.push_back(curr->val);
            curr = curr->right;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> bst_1;
        vector<int> bst_2;
        inOrder(root1,bst_1);
        inOrder(root2,bst_2);
        
        int i=0,j=0;
        while(i<bst_1.size() && j<bst_2.size()) {
            if(bst_1[i] < bst_2[j]){
                result.push_back(bst_1[i]); i++;
            } else if (bst_1[i] == bst_2[j]){
                result.push_back(bst_1[i]);
                result.push_back(bst_2[j]);
                i++; j++;
            } else {
                result.push_back(bst_2[j]); j++;
            }
        }
        if(i == bst_1.size() && j<bst_2.size()) {
            while(j<bst_2.size()){result.push_back(bst_2[j]);j++;}
        }
        if(j == bst_2.size() && i<bst_1.size()) {
            while(i<bst_1.size()){result.push_back(bst_1[i]);i++;}
        }
        return result;
        
    }
};

int main() {
    return 0;
}