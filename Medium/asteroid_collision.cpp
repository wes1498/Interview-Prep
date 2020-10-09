#include <iostream>
#include <stack>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> left;
    vector<int> result;
    for(int i=asteroids.size() -1; i>=0; i--) {
        if(asteroids[i] > 0) {
            bool destroyed = false;
            while(!left.empty()) {
                if(abs(left.top()) >= asteroids[i]) {
                    if(abs(left.top()) == asteroids[i]) {
                        left.pop();
                        destroyed = true;
                    }
                    break;
                } else {left.pop();}
            }
            if(left.empty() && !destroyed){result.push_back(asteroids[i]);}
            
        }
        else{left.push(asteroids[i]);}
    }
    vector<int>temp;
    while(!left.empty()) {
        temp.push_back(left.top());
        left.pop();
    }
    reverse(temp.begin(), temp.end());
    for(auto c : temp) {
        result.push_back(c);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> asteroids = {-9,5,-5,6,-8,8,-4};
    vector<int> result = {-9,-8,8};
    assert(asteroidCollision(asteroids) == result);
    return 0;
}