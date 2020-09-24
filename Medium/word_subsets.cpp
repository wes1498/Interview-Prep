#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<string> findSubsets(vector<string> A, vector<string> B) {
    vector<int> max_count_b(26,0);
    for(auto word_B : B) {
        vector<int> curr_count_b(26,0);
        for(auto ch : word_B) {
            curr_count_b[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(curr_count_b[i] != 0 && curr_count_b[i] > max_count_b[i]) {
                max_count_b[i] = curr_count_b[i];
            }
        }
    }
    vector<string> result;
    for(auto word_A : A) {
        vector<int> curr_count_a(26,0);
        for(auto ch : word_A) {
            curr_count_a[ch - 'a']++;
        }
        bool isUltimate = true;
        for(int i = 0; i < 26; i++) {
            if(max_count_b[i] != 0 && curr_count_a[i] < max_count_b[i]) {
                isUltimate = false;
                break;
            }
        }
        if(isUltimate){result.push_back(word_A);}
    }
    return result;
}

int main() {
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B = {"e","o"};
    vector<string> result = {"facebook","google","leetcode"};
    assert(findSubsets(A,B) == result);
    // vector<string> result = findSubsets(A,B);
    // for(auto a : result){
    //     cout<<a<<endl;
    // }
    return 0;
}