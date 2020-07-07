#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

// You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have varied lengths.

// Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

// Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.

 

// Example 1:

// Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
// Output: 3
// Explanation: 
// We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
// Then, we can reconstruct the sporting event as follows:
// We cut [1,9] into segments [1,2] + [2,8] + [8,9].
// Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].

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