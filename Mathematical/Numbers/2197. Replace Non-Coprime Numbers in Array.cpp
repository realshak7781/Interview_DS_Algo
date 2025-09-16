class Solution {
private:
    int getGcd(int a, int b) {
        if (b == 0)
            return a;

        return getGcd(b, a % b);
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // the first goal was to efficiently implement the dynamic deletion of
        // two non coprime adjacent elements and then the insertion of their lcm
        // since there is an adjacent nature to elements we can use stack :
        // since top of stack is always going to be the adjacent element for the
        // coming current element

        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];

            while(!st.empty()) {
                int b = st.top();
                int gcd = getGcd(max(a, b), min(a, b));

                if(gcd>1){
                    st.pop();
                    int lcm=(long long)a*b/gcd;
                    a=lcm;
                }
                else{
                    break;
                }
            }

            st.push(a);
        }

        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
