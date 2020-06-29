#include <iostream>
#include <vector>
#include <stack>

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

int kthSmallest(TreeNode* root, int k) {
    vector<int> temp;
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
        if(temp.size() == k) {return curr->val;}
        curr = curr->right;
    }
    return 0;
}

int main() {
    assert(kthSmallest(NULL,1) == 0);
    return 0;
}