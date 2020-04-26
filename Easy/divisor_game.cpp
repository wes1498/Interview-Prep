#include<iostream>
#include <vector>
#include <cassert> 

using namespace std;

bool divisorGame(int N) {
    if (N==1){return false;}
    if (N==2){return true;}
    vector<int> soln(N+1,0);
    soln[1]=0;
    soln[2]=1;
    for(int i=3; i<=N; i++){
        for(int j=1; j<=i/2&&i%j==0; j++) {
            if (soln[i-j]==0){
                soln[i]=1;
            }
        }
    }
    return soln[N]==1;
        
}
int main() {
    assert(divisorGame(1)==false);
    assert(divisorGame(2)==true);
    assert(divisorGame(3)==false);
    assert(divisorGame(4)==true);
    return 0;
}
