using ll=long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // obs 1: if sum of frequencies of any element in both arrays is odd ,it is logically impossible to make them equal;

        // obs 2: the goal is to make frequencies of elements in both array same:

        // obs 3:choose the elements whose frequency is not same in both arrays:
        // they are possible candidates for a swap

        // when we swap between possible candidates : the count of swap eleemnts increases and decreases in both freq maps;

        // do sorting by values 

        // and the key point to solve the problem is doing indirect swapping using the min element

        // which minimises the cost and also results in the swap:
        // {1,100,100}
        // {2,200,200}

        unordered_map<int,int> freq;

        int minElem=INT_MAX;

        for(int cost:basket1){
            freq[cost]++;
            minElem=min(cost,minElem);
        }


         for(int cost:basket2){
            freq[cost]--;
            minElem=min(cost,minElem);
        }

        vector<int> finalCosts;

        for(auto&it:freq){
            int cost=it.first;
            int count=it.second;

            if(count&1){
                return -1;
            }

            if(count==0) continue;

            for(int i=1;i<=abs(count)/2;i++){
                finalCosts.push_back(cost);
            }
        }

        nth_element(begin(finalCosts),begin(finalCosts)+finalCosts.size()/2,end(finalCosts));

        ll res=0;

        for(int i=0;i<finalCosts.size()/2;i++){
            res+=min(finalCosts[i],minElem*2);
        }

        return res;
    }
};
