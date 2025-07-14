class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i=0;i<operations.size();i++){
            string cur=operations[i];

            if(cur=="+"){
                if(st.size()>=2){
                    int top1=st.top();st.pop();
                    int top2=st.top();
                    st.push(top1);
                    st.push(top1+top2);
                }
            }
            else if(cur=="D"){
                if(!st.empty())st.push(st.top()*2);
            }
            else if(cur=="C"){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(stoi(cur));
            }
        }

        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }


        return res;
    }
};
