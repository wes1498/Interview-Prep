#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

string destCity(vector<vector<string>>& paths) {
    vector<string> sources;
    for(auto route : paths) {
        sources.push_back(route[0]);
    }
    string destination = "";
    for(auto route : paths) {
        if(find(sources.begin(),sources.end(),route[1]) == sources.end()) {
            destination += route[1];
        }
    }
    return destination;
}

int main() {
    vector<vector<string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    assert(destCity(paths) == "A");
    return 0;
}