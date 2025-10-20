// Using recursion + Memoization
class Solution {
private:
vector<int> price;
vector<vector<int>> special;

map<vector<int>,int> dp;
int solve(vector<int>needs){
    // base case

    if (accumulate(needs.begin(), needs.end(), 0) == 0) {
            return 0;
    }

    if(dp.count(needs)) return dp[needs];

    // buy all the items individually without offer
    int totalPrice=0;
    for(int i=0;i<needs.size();i++){
        totalPrice+=(needs[i]*price[i]);
    }


    // dont buy individually apply offers
    for(int i=0;i<special.size();i++){
        bool canApply=true;
        vector<int> new_needs = needs;
        for(int j=0;j<needs.size();j++){
            if(special[i][j]>needs[j]){
                canApply=false;
                break;
            }
            new_needs[j] = needs[j] - special[i][j];
        }

        if(!canApply) continue;

        int offer_price = special[i][needs.size()];
        int cost_with_offer = offer_price + solve(new_needs);
        totalPrice = min(totalPrice, cost_with_offer);
    }

    return  dp[needs]=totalPrice;
}
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price=price;
        this->special=special;

        return solve(needs);
    }
};




// Brute force : using Recursion : 64 / 65 testcases passed

class Solution {
private:
vector<int> price;
vector<vector<int>> special;

int solve(vector<int>needs){
    // base case

    if (accumulate(needs.begin(), needs.end(), 0) == 0) {
            return 0;
    }

    // buy all the items individually without offer
    int totalPrice=0;
    for(int i=0;i<needs.size();i++){
        totalPrice+=(needs[i]*price[i]);
    }


    // dont buy individually apply offers
    for(int i=0;i<special.size();i++){
        bool canApply=true;
        vector<int> new_needs = needs;
        for(int j=0;j<needs.size();j++){
            if(special[i][j]>needs[j]){
                canApply=false;
                break;
            }
            new_needs[j] = needs[j] - special[i][j];
        }

        if(!canApply) continue;

        int offer_price = special[i][needs.size()];
        int cost_with_offer = offer_price + solve(new_needs);
        totalPrice = min(totalPrice, cost_with_offer);
    }

    return totalPrice;
}
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price=price;
        this->special=special;

        return solve(needs);
    }
};
