#include<iostream>

using namespace std;

int foo (int n, int c) {
    if (n==0) {
        return 1;
    }
    int x =0;
    for (int i=0; i<c; i++) {
        x+=foo(n-1,c);
    }
    return x;
}
int main() {
    int x =foo(2,3);
    cout<< x;
    return 0;
}