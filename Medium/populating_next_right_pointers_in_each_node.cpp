#include <iostream>
#include <unordered_map>
#include <cassert>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void connectNext(Node* root) {
        Node* curr_level = root;
        
        while(curr_level) {
            Node* curr = curr_level;
            while(curr && curr->left){
                curr->left->next = curr->right;
                if(curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr=curr->next;
            }
            curr_level = curr_level->left;
        }
    }
    Node* connect(Node* root) {
        connectNext(root);
        return root;
    }
};

int main() {
    return 0;
}