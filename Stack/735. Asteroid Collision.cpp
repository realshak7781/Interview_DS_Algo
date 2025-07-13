
// stack based approach : O(n) time and O(n) space
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int cur=asteroids[i];
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && cur<0){
                if(st.top()==abs(cur)){
                    st.pop();
                    destroyed=true;
                    break;
                }
                else if(st.top()> abs(cur)){
                    destroyed=true;
                    break;
                }
                else{
                    st.pop();
                }
            }

            if(!destroyed) st.push(cur);
        }


        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());st.pop();
        }

        reverse(res.begin(),res.end());


        return res;
    }
};

// vector<based > approach :O(n) and space : O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();

        vector<int> res;

        for(int i=0;i<n;i++){
            int cur=asteroids[i];
            bool destroyed=false;
            while(!res.empty() && res.back()>0 && cur<0){

                if(res.back()==abs(cur)){
                    res.pop_back();
                    destroyed=true;
                    break;
                }
                else if(res.back()>abs(cur)){
                    destroyed=true;
                   break;
                }
                else{
                    res.pop_back();
                }
            }
           if(!destroyed) res.push_back(cur);
        }

        return res;
    }
};
