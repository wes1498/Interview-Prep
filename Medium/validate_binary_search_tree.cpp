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