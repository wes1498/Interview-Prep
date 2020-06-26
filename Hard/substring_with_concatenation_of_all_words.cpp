#include <iostream>
#include <cassert> 
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if(s.empty() || words.empty()){return result;}
    
    int window_size=0;
    int word_size=words[0].size();
    // Store occurrences of word in words[] inside table
    unordered_map<string, int> table;
    for(auto word : words) {
        window_size+=word.size();
        table[word]++;
    }

    unordered_map<string, int> copy(table);
    
    if(s.length() < window_size){return result;}
    
    int begin=0, end=0, counter=0;

    for(int i=0; i<word_size; i++) {
        begin=i, end=i, counter=0;
        table=copy;

        while(end+word_size-1 < s.length()){
            string last_word = s.substr(end, word_size);
            
            if(table.count(last_word) == 1){
                table[last_word]--;
                if(table[last_word] == 0) counter++;
            }

            if(end+word_size-begin == window_size){
                if(counter == table.size()){
                    result.push_back(begin);
                } 

                string first_word = s.substr(begin, word_size);
                
                if(table.count(first_word) == 1){
                    table[first_word]++;
                    if(table[first_word] > 0) counter--;
                }

                begin += word_size;
            }

            end += word_size;
        }
    }
    return result;
}

int main() {
    vector<string> words = {"foo", "bar"};
    vector<int> result;
    result.push_back(0);
    result.push_back(9);
    assert(findSubstring("barfoothefoobarman", words) == result);
    if(findSubstring("barfoothefoobarman", words) == result) {
        printf("success!\n");
    }
    return 0;
}