
// using hashing
class FindSumPairs {
vector<int>nums1,nums2;
unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;

        for(int val:nums2)freq[val]++;
    }
     
    void add(int index, int val) {
        if(index>=nums2.size()) return;
        int oldVal=nums2[index];
        freq[oldVal]--;
        nums2[index]+=val;
        int newVal=nums2[index];
        freq[newVal]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<nums1.size();i++){
           int n2=tot-nums1[i];
           cnt+=(freq[n2]);
        }

        return cnt;
    }

};




//BRUTE FORCE : SORTING + BINARY SEARCH : TLE
class FindSumPairs {
vector<int>nums1,nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
    }
    
    void add(int index, int val) {
        if(index>=nums2.size()) return;

        nums2[index]+=val;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<nums1.size();i++){
            int n2=tot-nums1[i];
            cnt+=(getCount(nums2,n2));
        }

        return cnt;
    }


    int getCount(vector<int> nums2,int n2){
        sort(nums2.begin(),nums2.end());
        int lb=lower_bound(nums2.begin(),nums2.end(),n2)-nums2.begin();
        int ub=upper_bound(nums2.begin(),nums2.end(),n2)-nums2.begin();

        int count=ub-lb;
        return count;
    }
};

