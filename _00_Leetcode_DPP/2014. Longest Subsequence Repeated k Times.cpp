class Solution {
private:
int maxLen;
string res;  
vector<bool> candidates; 
unordered_map<int,int> freq; 
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.length();
        maxLen=n/k;
        res="";
        
        for(char c:s) freq[c-'a']++;

        // take only those chars whose freq is >=k
        candidates=vector<bool>(26,false);
        for(auto it:freq){
            if(it.second>=k){
                candidates[it.first]=true;
            }
        }
        // now for the result string count(candidate char)/k will be used 4
        for(int i=0;i<26;i++){
            if(candidates[i]){
                freq[i]/=k;
            }
        }

        // find all possible subsequences from the candidates and check if seq*k is subsequence in s while keeping len of seq<=maxLen

        for(int len=maxLen;len>=0;len--){
            string cur="";
            if(generateSub(s,k,cur,len)){
                return res;
            }
        }

        return res;
    }

    private:

    bool isSubsequence(string &s,int k,string &sub){
        int i=0;
        int j=0;
        int n=s.length();
        int L=sub.length();

        while(i<n && j<k*L){
            if(s[i]==sub[j%L]) j++;

            i++;
        }

        return j==k*L;
    }
    bool generateSub(string &s,int k,string cur,int reqLen){

        if(cur.length()==reqLen){
            if(isSubsequence(s,k,cur)){
                res=cur;
                return true;
            }
            return false;
        }
        for(int i=25;i>=0;i--){
            if(!candidates[i] || freq[i]==0) continue;

            char ch='a'+i;
            freq[i]--;

            if(generateSub(s,k,cur+ch,reqLen)){
                return true;
            }
            freq[i]++;
        }
        return false;
    }
};
