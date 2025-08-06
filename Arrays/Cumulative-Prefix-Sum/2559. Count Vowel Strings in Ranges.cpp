class Solution {
bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;

    return false;
}    
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();

        vector<int> v_Start_End(n,0);

        for(int i=0;i<n;i++){
            // marking the words true which starts and ends with a vowel
            string s=words[i];
            int l=words[i].length();
            if(isVowel(s[0]) && isVowel(s[l-1])){
                v_Start_End[i]=1;
            }
        }

        // find the prefSum of this array to get range based count
        vector<int> prefSum(n,0);
        prefSum[0]=v_Start_End[0];

        for(int i=1;i<n;i++){
            prefSum[i]= prefSum[i-1] + v_Start_End[i];
        }


        vector<int> res;

        for(auto &it:queries){
            int l=it[0];
            int r=it[1];

            int count=prefSum[r]-(l>0?prefSum[l-1]:0);
            res.push_back(count);
        }

        return res;
    }
};
