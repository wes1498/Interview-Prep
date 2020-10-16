#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1,s2;
    while(l1){
        s1.push(l1->val);
        l1=l1->next;
    }
    while(l2){
        s2.push(l2->val);
        l2=l2->next;
    }
    ListNode* head = NULL, *temp, *temp1;
    int carry = 0;
    vector<int> result;
    while(!s1.empty() || !s2.empty()) {
        int x = 0,y=0;
        if(!s1.empty()){x = s1.top(); s1.pop();}
        if(!s2.empty()){y = s2.top(); s2.pop();}
        int sum = x + y + carry;
        carry = sum/10; // get new carry
        result.push_back(sum%10);
    }
    if(carry == 1) {
        result.push_back(1);   
    }
    for(int i = result.size()-1; i>=0; i--){
        temp1 = new ListNode(result[i]);
        if(head == NULL) {
            head = temp1;
            temp = temp1;
        } else {
            temp->next = temp1;
            temp = temp1;
        }
    }
    return head;
}

int main() {
    return 0;
}