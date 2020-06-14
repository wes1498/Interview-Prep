#include <iostream>
#include <cassert> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    //have a base pointer b_ptr; --return
    if(head==NULL){return head;}
    
    // Left list
    ListNode *curr = head;
    ListNode *leftTail = NULL;
    int i = 0;
    while(curr && i++ < m -1) 
    {
        leftTail = curr;
        curr = curr->next;   
    }
    if(m > 1){leftTail->next = NULL;}
    
    ListNode *rightHead = curr;
    ListNode *middleTail = curr;
    ListNode *middleHead = NULL;
    while(rightHead && i++ <= n )
    {
        curr = rightHead->next;
        rightHead->next = middleHead;
        middleHead = rightHead;
        rightHead = curr;
    }
    
    if(m > 1 ){leftTail->next = middleHead;}
    else{ head = middleHead;}
    middleTail->next = rightHead;
    return head;
}

int main() {
    ListNode *head = new ListNode;
    head->val=1;
    ListNode *head2 = new ListNode;
    head2->val=2;
    head->next=head2;
    head2->next=NULL;

    ListNode *second = new ListNode;
    second->val=2;
    ListNode *second2 = new ListNode;
    second2->val=1;
    second->next=second2;
    second2->next=NULL;

    assert(reverseBetween(head,1,2)==second);
    return 0;
}