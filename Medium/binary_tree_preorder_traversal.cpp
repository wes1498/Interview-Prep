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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        result.push_back(curr->val);
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
    return result;
}

int main()
{
    vector<int> result;
    assert(preorderTraversal(NULL) == result);
    return 0;
}