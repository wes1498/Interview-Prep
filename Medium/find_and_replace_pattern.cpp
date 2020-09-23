#include <iostream>
#include <vector>
#include <string>
#include <stack>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<int> encode_word(string word) {
    vector<int> encoded;
    // if a character was previously visited, you need to recall the
    // characters mapped sequence value
    unordered_map<char,int> sequence;
    int step = 0;
    for(int i = 0; i < word.size(); i++) {
        if(sequence.find(word[i]) != sequence.end()){
            encoded.push_back(sequence[word[i]]);
        } else {
            step++;
            encoded.push_back(step);
            sequence[word[i]] = step;
        }
    }
    return encoded;
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    // Goal: convert string pattern in to some encoded sequence so 
    //       that when you convert each word, it matches the encoded sequence exactly
    // eg. "abb" -> 122 (any word with this numerical sequence is true permutation)
    //     "cdd" -> 122
    // store sequence in a list
    vector<string> result;
    vector<int> encoded_pattern = encode_word(pattern);
    
    for(auto word : words) {
        if(encode_word(word) == encoded_pattern){result.push_back(word);}
    }
    return result;
}

int main() {
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    assert(findAndReplacePattern(words,"abb") == {"mee","aqq"});
    return 0;
}