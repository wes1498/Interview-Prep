#include <iostream>
#include <vector>

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> last_index(26,-1),result;
    
    for(int i = 0; i < S.size(); i++) {
        last_index[S[i]-'a'] = i;
    }
    int index = 0,maxx = -1;
    string partition = "";
    while(index < S.size()) {
        maxx = max(maxx, last_index[S[index] - 'a']);
        if(index == maxx) {
            partition += S[index];
            result.push_back(partition.size());
            partition = "";
            index++;
            continue;
        }
        partition += S[index];
        index++;
    }
    return result;   
}

int main() {
    vector<int> result = {9,7,8};
    assert(partitionLabels("ababcbacadefegdehijhklij") == result);
    return 0;
}