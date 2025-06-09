//APPROACH 1 : USING SIMPLE RECURSION

class Solution {
private:
vector<string> helper(int n){
    if(n==1){
        return {"0","1"};
    }

    vector<string> temp=helper(n-1);

    vector<string> padded;

    for(int i=0;i<temp.size();i++){
        padded.push_back("0"+temp[i]);
    }

    for(int i=temp.size()-1;i>=0;i--){
        padded.push_back("1"+temp[i]);
    }
    return padded;
}    
public:
    vector<int> grayCode(int n) {
        vector<string> res=helper(n);

        vector<int> finalR;

        for(string &s:res){
            bitset<32> b(s);
            finalR.push_back(b.to_ulong());
        }

        return finalR;
    }
};
