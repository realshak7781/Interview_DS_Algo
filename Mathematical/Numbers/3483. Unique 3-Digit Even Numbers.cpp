class Solution {
private:
unordered_set<int> st;
vector<int> used;
void solve(int idx,vector<int>&digits,int num){

    if(idx<0){
        st.insert(num);
        return;
    }

    for(int i=0;i<digits.size();i++){
        if(used[i]) continue;
        if(idx==0 && digits[i]==0) continue;
      // avoiding leading zeroes
      
        int orgNum=num;
        num=pow(10,2-idx)*digits[i]+num;
        used[i]=true;
        solve(idx-1,digits,num);
        num=orgNum;
        used[i]=false;
    }
}
public:
    int totalNumbers(vector<int>& digits) {

        used.resize(digits.size(),false);

        for(int i=0;i<digits.size();i++){
            if(digits[i]%2==0 ){
                used[i]=true;
                solve(1,digits,digits[i]);
                used[i]=false;
            }
        }

        return st.size();
    }
};
