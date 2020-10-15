#include <iostream>
#include <vector>

using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* l11=l1,*l22=l2;
    ListNode* head = NULL, *temp, *temp1;
    while(l11 || l22) {
        int x = l11 ? l11->val : 0;
        int y = l22 ? l22->val : 0;
        int sum = x + y + carry;
        carry = sum/10;
        temp1 = new ListNode(sum%10);
        if(head == NULL) {
            head = temp1;
            temp = temp1;
        } else {
            temp->next = temp1;
            temp = temp1;
        }
        
        l11= l11 ? l11->next : NULL;
        l22= l22 ? l22->next : NULL;
    }
    if(carry == 1) {
        temp1 = new ListNode(1);
        temp->next = temp1;
        temp=temp1;
    }
    return head;
        
}

int main () {
    return 0;
    
}