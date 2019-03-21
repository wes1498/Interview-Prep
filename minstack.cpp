#include<iostream>
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque


using namespace std;

/**
Chapter 3
Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum eiement? Push, pop and min should ail operate in 0(1 ) time.
**/ 

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
