
// t.c : o(n) 
// s.c : o(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int num3=INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<num3) return true;
                //  a candidate for largest element
                // num2=largest=cur=nums[i];
                // second largest=num3= st.top()---> while(st.top()<=cur)

                while(!st.empty() && st.top()<nums[i]){
                    num3=st.top();
                    st.pop();
                }

                st.push(nums[i]);  
        }


        return false;
    }
};



// T.c: O(n^2)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        int min_i=INT_MAX;
        for(int j=0;j<n-1;j++){
            min_i=min(min_i,nums[j]);

            for(int k=j+1;k<n;k++){
                int kVal=nums[k];

                if(kVal<nums[j] && min_i<kVal) return true;
            }
        }

        return false;
    }
};

// brute force : O(n^3) 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[k]>nums[i] && nums[k]<nums[j]) return true;
                }
            }
        }

        return false;
    }
};
