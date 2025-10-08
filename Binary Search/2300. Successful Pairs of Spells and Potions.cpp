using ll=long long;
class Solution {
private:
int binarySearch(vector<int>&potions,ll spellSt,ll success){
    int size=potions.size();
    int low=0;
    int high=potions.size()-1;


    while(low<=high){
        int mid=low+(high-low)/2;

        ll potionSt=potions[mid];

        ll totalStrength=1LL*potionSt*spellSt;

        if(totalStrength>=success){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return size-low;
}
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();

        sort(potions.begin(),potions.end());

        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            ll spellStrength=spells[i];

            int count=binarySearch(potions,spellStrength,success);

            res[i]=count;
        }

        return res;
    }
};
