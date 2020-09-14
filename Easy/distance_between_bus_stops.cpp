#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int i = start, n = distance.size();
    int clock=0,anticlock=0;
    while(i != destination) {
        if(i >= n){
            i = 0;
            continue;
        }
        clock+=distance[i];
        i++;
        
    }
    i = destination;
    while(i != start) {
        if(i >= n) {
            i = 0;
            continue;
        }
        anticlock+=distance[i];
        i++;
        
    }
    return min(clock,anticlock);
}

int main() {
    vector<int> distance{1,2,3,4};
    assert(distanceBetweenBusStops(distance, 0, 3) == 4);
    return 0;
}