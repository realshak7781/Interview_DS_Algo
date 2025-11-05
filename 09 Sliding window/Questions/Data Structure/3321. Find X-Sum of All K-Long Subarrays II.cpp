using p=pair<long long,long long>;
using ll=long long;
class Solution {
private:
ll sum;
int x;
multiset<p> top;
multiset<p> bot;
unordered_map<int,int> freq;



// Time : 
void insertInSet(const p &pr){

    if(top.size()<x || pr > *top.begin()){
        sum+=(1LL*pr.first*pr.second);
        top.insert(pr);


        if(top.size()>x){
            auto smallest=*top.begin();
            sum-=(1LL*smallest.first*smallest.second);

            top.erase(smallest);
            bot.insert(smallest);
        }
    }
    else{
        bot.insert(pr);
    }
}


void removeFromSet(const p &pr){

    if(top.find(pr)!=top.end()){
        sum-=(1LL*pr.first*pr.second);

        top.erase(pr);

        // balancing'
        if(!bot.empty()){
            // size of top becomes less than x
            auto largest=*bot.rbegin();
            bot.erase(largest);

            top.insert(largest);
            sum+=(1LL*largest.first*largest.second);
        }
    }
    else{
        bot.erase(pr);
    }
}
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        this->x=x;
        int n=nums.size();
        for(int i=0;i<k;i++) freq[nums[i]]++;
        for(auto it:freq) insertInSet({it.second,it.first});

        vector<ll> res(n-k+1,0);
        res[0]=sum;


        for(int i=1;i<(n-k+1);i++){
            int outIdx=i-1;
            int inIdx=i+k-1;

            if(freq[nums[inIdx]]>0){
                removeFromSet({freq[nums[inIdx]],nums[inIdx]});
            }

            freq[nums[inIdx]]++;
            insertInSet({freq[nums[inIdx]],nums[inIdx]});

            removeFromSet({freq[nums[outIdx]],nums[outIdx]});
            freq[nums[outIdx]]--;

            if(freq[nums[outIdx]]>0){
                insertInSet({freq[nums[outIdx]],nums[outIdx]});
            }

            res[i]=sum;
        }

        return res;
    }
};
