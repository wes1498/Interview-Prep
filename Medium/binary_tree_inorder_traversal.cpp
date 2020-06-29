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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }

    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

int main()
{
    vector<int> res;
    assert(inorderTraversal(NULL) == res);
    return 0;
}