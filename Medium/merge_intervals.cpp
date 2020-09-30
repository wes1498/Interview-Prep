#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //[1,3] [2,6]
    // overlapping occurs when it[i][0] < it[i-1][1]
    // add first interval to result list
    // for each interval
    // keep a range calculator for each time you want to merge an interval
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    if(intervals.size() == 0) {return result;}
    vector<int> interval = intervals[0];
    for(auto it : intervals) {
        if(it[0] <= interval[1]) {
            interval[1] = max(it[1],interval[1]);
        } else {
            result.push_back(interval);
            interval = it;
        }
    }
    result.push_back(interval);
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result  = {{1,6},{8,10}, {15,18}};
    assert(merge(intervals) == result);
    return 0;
}