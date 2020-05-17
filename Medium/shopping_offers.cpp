#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

bool needsMet(vector<int>& needs) {
    int n=needs.size();
    for(int i=0; i<n; i++) {
        if (needs[i]){return false;}
    }
    return true;
}

bool canApplyOffer(vector<int>& offer,vector<int>& needs) {
    // if for each deal in offer, needs[i]-offer[i]>=0
    for(int i=0; i<needs.size(); i++) {
        if(needs[i]-offer[i]<0){return false;}
    }
    return true;   
}

void applyOffer(vector<int>& offer,vector<int>& needs, bool canApply, int& currentPrice){
    if(canApply){
        int i=0;
        for(; i<needs.size(); i++){
            needs[i]-=offer[i];
        }
        currentPrice+=offer[i];
    } else {
        int i=0;
        for(; i<needs.size(); i++){
            needs[i]+=offer[i];
        }
        currentPrice-=offer[i];
    }
}

int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int& lowestPrice, int currentPrice) {
    // check if all needs are met (aka needs[0:i]=0)
    // because we'll be decrementing needs at each offer placed
    if(needsMet(needs)){lowestPrice= min(lowestPrice, currentPrice);}
    
    // check each offer if it can be applied
    for(auto& offer: special){
        if(canApplyOffer(offer,needs)){
            applyOffer(offer,needs,true,currentPrice);
            dfs(price,special,needs,lowestPrice, currentPrice);
            applyOffer(offer,needs,false,currentPrice);       
        } else {
            int individualPrice=0;
            for(int i=0; i<needs.size(); i++){
                individualPrice+=needs[i]*price[i];
            }
            currentPrice+=individualPrice;
            lowestPrice = min(lowestPrice,currentPrice);
            currentPrice-=individualPrice;
        }
    }
    return lowestPrice;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    // check if needs are empty then return 0
    // calculate price if you were to purchase at price, and not use special
    // use dfs to check for each special, if you can: -- returns lowest price
        // 1. use the special
        // 2. apply the special
        // 3. check next if you can still use a new special
                // conforming to constraints: 
                    // - cannot over-purchase
                    // - minimize price
    // if you cant use special, fill remaining needs with individual costs
    int n=needs.size();
    if(n==0){return 0;}
    int lowestPrice=0;
    for(int i=0;i<n;i++){
        lowestPrice+=needs[i]*price[i];
    }
    return dfs(price,special,needs,lowestPrice, 0);
}

int main() {
    vector<int> price;
    price.push_back(2);
    price.push_back(5); 

    vector<vector<int>> special;
    vector<int> temp;
    temp.push_back(3);
    temp.push_back(0);
    temp.push_back(5);
    special.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(10);
    special.push_back(temp);

    vector<int> needs;
    needs.push_back(3);
    needs.push_back(2);

    assert(shoppingOffers(price,special,needs)==14);
    if(shoppingOffers(price,special,needs)==14){
        printf("Yippee! it worked but is not the quikest :/\n");
    }
    return 0;

     
}