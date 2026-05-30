// TIME : O(NLOGN)
// SPACE: O(N) + O(N)

using ll=long long;
class Solution {
private:
    int binarySearch(int left, int right, const vector<long long>& vec, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (vec[mid] == target) {
                return mid;
            } else if (vec[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<ll>> idxMp;
        unordered_map<int,vector<ll>> pfMp;

        for(int i=0;i<n;i++){
            idxMp[nums[i]].push_back(i);
        }

        for(auto &it:idxMp){
            int val=it.first;
            auto &vec=it.second;

            pfMp[val].resize(vec.size());
            pfMp[val][0]=vec[0];

            for(int i=1;i<vec.size();i++){
                pfMp[val][i]=vec[i]+pfMp[val][i-1];
            }
        }

        vector<ll> res(n,0);
        for(int i=0;i<n;i++){
            int val=nums[i];
            auto &vec=idxMp[val];
            auto &prefVec=pfMp[val];

            int idx=binarySearch(0,vec.size()-1,vec,i);

            if(idx==-1) continue;

            int leftElemCnt=idx-0;
            int rightElemCnt=vec.size()-idx-1;

            ll leftAbsSum=(ll)leftElemCnt*i - (idx>0 ? prefVec[idx-1]:0);
            ll rightAbsSum=(prefVec[vec.size()-1]-prefVec[idx]) - ((ll)rightElemCnt*i);

            res[i]=leftAbsSum+rightAbsSum;
        }

        return res;
    }
};
