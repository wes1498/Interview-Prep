#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(),clips.end(),[](vector<int> a, vector<int> b) {
        return a[0]<b[0];
    });
    int n = clips.size();
    vector<int>dp(1000,100);
    int _max=clips[0][1];
    for(int i=1; i<n; i++) {
        if(_max<clips[i][0] && _max<T){return -1;}
        _max=max(_max,clips[i][1]);
    }
    if(clips[0][0] > 0 || _max < T){return -1;}
    
    for(int i=0; i<=clips[0][1]; i++){
        dp[i]=1;
    }
    dp[0]=0;
    
    for(int i=1; i<n; i++) {
        for(int j=clips[i][0]+1; j<=clips[i][1]; j++) {
            dp[j]=min(dp[j],1+dp[clips[i][0]]);
        }
    }
    return dp[T];
}

int main() {
    //clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
    vector<vector<int>> clips;
    vector<int>temp;
    temp.push_back(0);
    temp.push_back(2);
    clips.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(6);
    clips.push_back(temp);
    temp.clear();

    temp.push_back(8);
    temp.push_back(10);
    clips.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(9);
    clips.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(5);
    clips.push_back(temp);
    temp.clear();

    temp.push_back(5);
    temp.push_back(9);
    clips.push_back(temp);

    assert(videoStitching(clips,10)==3);
    return 0;
}