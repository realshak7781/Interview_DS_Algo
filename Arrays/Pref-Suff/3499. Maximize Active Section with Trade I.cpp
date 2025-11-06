class Solution {
private:
bool allZeroes(string& s) {
        for (char c : s) {
            if (c == '1') return false;
        }
        return true;
    }
public:
    int maxActiveSectionsAfterTrade(string s) {
        // helpful test cases
        // 0100111000
        // 00110011100

        if(allZeroes(s)){
            return 0;
        }

        vector<int> result;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
               result.push_back(0);
            }
            else{
                int k=i;
                int count=0;

                while(k<s.length()&& s[k] == '1'){
                   count++;
                    k++;
                }

               result.push_back(count);
                i = k - 1; 
            }
        }

        // now cur is : 00200300
        // convert to vector
        // then we will count prefic and suffic to count the no fo zeroes on eft and right side of non zero elem

        vector<int> suff(result.size(),-1);
        vector<int> pref(result.size(),-1);

        int count=0;
        for(int i=0;i<result.size();i++){
            if(result[i]==0) count++;
            else{
                pref[i]=count;
                count=0;
            }
        }

        count=0;
        for(int i=result.size()-1;i>=0;i--){
            if(result[i]==0) count++;
            else{
                suff[i]=count;
                count=0;
            }
        }


        int totalOnes=0;
        for(int i=0;i<result.size();i++){
            if(result[i]==0) continue;

            totalOnes+=result[i];
        }

        int maxOnes=totalOnes;
        for(int i=0;i<result.size();i++){
            if(result[i]==0) continue;

            
            if(pref[i]>0 && suff[i]>0){
                int gain=totalOnes+pref[i]+suff[i];
                maxOnes=max(maxOnes,gain);
            }
            
        }

        return maxOnes;
    }
};
