// optimal:
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> res;

        vector<int> vis(n,false);
        for(int i=0;i<n;i++){
            if(nums[i]!=key) continue;

            // expand lefft and right
            if(!vis[i])res.push_back(i);
            int j=i-1;
            int m=i+1;

            while(j>=0 && (i-j)<=k){
                if(!vis[j])res.push_back(j);
                vis[j]=true;
                j--;
            }

            while(m<n && (m-i)<=k){
                if(!vis[m])res.push_back(m);
                vis[m]=true;
                m++;
            }
            vis[i]=true;
        }

        sort(res.begin(),res.end());

        return res;
    }
};

//BRUTE FORCE SOLUTION:
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> res;

        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[j]==key && abs(i-j)<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());

        return res;
    }
};
