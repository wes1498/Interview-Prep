#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node* flatten(Node* head) {
    Node* _head = head;
    while(_head) {
        if(_head->child) {
            Node* cpy = _head->next;
            _head->next = flatten(_head->child);
            _head->next->prev = _head;
            _head->child = NULL;
            while(_head->next){
                _head = _head->next;
            }
            _head->next = cpy;
            if(cpy) {
                cpy->prev = _head;
            }
        }
        _head=_head->next;
        
    }
    return head;
}

int main() {
    return 0;
}