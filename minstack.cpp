#include<iostream>
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque


using namespace std;

std::stack<int> mystack;

void minPush(int x) {
  int temp;
  if(mystack.empty()) {
    mystack.push(x);
    temp = mystack.top();

  } else if(x < temp) {
    mystack.push(x);
    temp = mystack.top();
  } else {
    mystack.pop();
    mystack.push(x);
    mystack.push(temp);
  }
}


int main() {
  minPush(0);
  minPush(10);
  minPush(-2);

  std::cout << "This is the min: " << mystack.top() <<'\n';

  mystack.pop();
  mystack.pop();
  mystack.pop();

  return 0;

}
