

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // problem is simple : we need to find the longest window of subarray with atmost two distinct elements

        int n=fruits.size();
        int i=0,j=0;

        unordered_map<int,int> freq;

        int res=0;
        while(j<n){
            int type=fruits[j];
            freq[type]++;
            // gives the type of fruit we are picking : we can only pick two distinct types not more than that

            // check if there are more than one type:

            while(freq.size()>2){
                freq[fruits[i]]--;

                if(freq[fruits[i]]==0){
                    freq.erase(fruits[i]);
                }
                i++;
            }

            res=max(res,j-i+1);
            j++;
        }

        res=max(res,j-i);

        return res;
    }
};
