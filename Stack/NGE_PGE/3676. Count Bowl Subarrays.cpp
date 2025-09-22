using ll=long long;
class Solution {
private:
vector<ll> getRightMax(vector<int>&nums){
    int n=nums.size();
    vector<ll> res(n,-1);

    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int curElem=nums[i];

        while(!st.empty() && curElem>=st.top()) st.pop();

        if(!st.empty()){
            res[i]=st.top();
        }

        st.push(curElem);
    }

    return res;
}

vector<ll> getLeftMax(vector<int>&nums){
    int n=nums.size();
    vector<ll> res(n,-1);

    stack<int> st;
    for(int i=0;i<n;i++){
        int curElem=nums[i];

        while(!st.empty() && curElem>=st.top()) st.pop();

        if(!st.empty()){
            res[i]=st.top();
        }

        st.push(curElem);
    }

    return res;
}
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<ll>leftMax=getLeftMax(nums);
        vector<ll>rightMax=getRightMax(nums);


        ll bowls=0;

        for(int i=1;i<n-1;i++){
            // treat the cur element as the max element in between

            ll maxi=nums[i];
            ll mini=min(leftMax[i],rightMax[i]);

            if(mini>maxi) bowls++;
        }

        return bowls;
    }
};
