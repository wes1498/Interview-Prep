#include <iostream>
#include <cassert> 

using namespace std;

// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    if(head==NULL || head->next==NULL){return head;}
    ListNode* less_head = new ListNode(-1);
    ListNode* less_iter=less_head;
    ListNode* greater_head = new ListNode(-1);
    ListNode* greater_iter=greater_head;
    
    while(head){
        if(head->val<x){
            less_iter->next=head;
            less_iter=less_iter->next;
        }else{
            greater_iter->next=head;
            greater_iter=greater_iter->next;
        }
        head=head->next;   
    }
    less_iter->next=greater_head->next;
    greater_iter->next=NULL;
    less_head=less_head->next;
    return less_head;
}

int main() {
    ListNode *head = new ListNode;
    head->val=1;
    ListNode *head2 = new ListNode;
    head2->val=1;
    head->next=head2;
    head2->next=NULL;

    ListNode *head3 = new ListNode;
    head3->val=1;
    ListNode *head4 = new ListNode;
    head4->val=1;
    head3->next=head4;
    head4->next=NULL;
    assert(partition(head,2)==head3);
    return 0;
}