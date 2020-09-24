#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

string addSpace(int between_space) {
    string space = "";
    for(int i=1; i<=between_space; i++)
        space += ' ';
    return space;
}
string reorderSpaces(string text) {
    
    int space_count = 0, word_count = 0, end_space, between_space;
    string new_string = "";
    vector<string> words;
    
    for(int i = 0; i < text.size(); i++) {
        if(text[i] == ' '){space_count++;}
    }
    for(int i=0; i < text.size(); i++) {
        if(text[i] != ' '){
            word_count++;
            size_t next_space = text.substr(i).find(' ') != std::string::npos ? text.substr(i).find(' ') : text.size();
            words.push_back(text.substr(i,next_space));
            i += next_space; 
        }
    }
    if(space_count == 0 || word_count == 0){return text;}
    
    if(word_count > 1){
        end_space = space_count % (word_count - 1);
        between_space = space_count / (word_count -1);
    } else {
        end_space = space_count;
        between_space = 0;
    }
    
    for(auto word : words) {
        new_string += word + addSpace(between_space);
    }
    new_string = new_string.substr(0,new_string.size() - between_space);
    new_string += addSpace(end_space);
    cout << space_count << " " << word_count << endl;
    
    return new_string;
}

int main() {
    assert(reorderSpaces("  this   is  a sentence ") == "this   is   a   sentence");
    assert(reorderSpaces(" practice   makes   perfect") == "practice   makes   perfect ");
    assert(reorderSpaces("hello   world") == "hello   world");
    return 0;
}