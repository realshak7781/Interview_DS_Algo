class Solution {
private:
set<vector<int>> vis;
vector<vector<int>> generateSplit(vector<int>&nums){
    int n=nums.size();

    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        vector<int> sub;
        for(int j=i;j<n;j++){

            vector<int> remArr;
            sub.push_back(nums[j]);

            for(int k=0;k<i;k++){
                remArr.push_back(nums[k]);
            }

            for(int k=j+1;k<n;k++){
                remArr.push_back(nums[k]);
            }

            for(int pos=0;pos<=remArr.size();pos++){
                vector<int> temp=remArr;

                temp.insert(temp.begin()+pos,sub.begin(),sub.end());

                if(!vis.count(temp)){
                    res.push_back(temp);
                }
            }
        }
    }

    return res;
}
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<pair<vector<int>,int>> q;

        q.push({nums1,0});
        vis.insert(nums1);


        while(!q.empty()){
            auto topVec=q.front().first;
            int steps=q.front().second;

            q.pop();
            if(topVec==nums2) return steps;

            vector<vector<int>> gen=generateSplit(topVec);

            for(auto it:gen){
                if(!vis.count(it)){
                    q.push({it,steps+1});
                    vis.insert(it);
                }
            }
        }


        return -1;
    }
};
