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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }

    vector<int> temp;

    queue<TreeNode *> bfs, q;
    bfs.push(root);
    while (!bfs.empty())
    {
        swap(q, bfs);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current)
            {
                temp.push_back(current->val);
                bfs.push(current->left);
                bfs.push(current->right);
            }
        }
        if (!temp.empty())
        {
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> res;
    assert(levelOrder(NULL) == res);
    return 0;
}