class Solution {
private:
string res;    
int createMask(string &s){

    int mask=0;
    for(char c:s){
        int idx=c-'a';
        if(mask &(1<<idx)) return -1;
        mask|=(1<<idx);
    }

    return mask;
}

void backTrack(int prevMask,int idx,string temp,int n,vector<int>&masks,vector<string>&arr){
    if(idx>=n){
        if(temp.size()>res.size()){
            res=temp;
        }
        return;
    }

    // skip
    backTrack(prevMask,idx+1,temp,n,masks,arr);

    if(masks[idx]!=-1 && (prevMask & masks[idx])==0){
        backTrack(prevMask|masks[idx],idx+1,temp+arr[idx],n,masks,arr);
    }
}
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int> masks(n);

        for(int i=0;i<n;i++){
            masks[i]=createMask(arr[i]);
        }

        res="";
        string temp="";
        backTrack(0,0,temp,n,masks,arr);

        return res.size();
    }
};
