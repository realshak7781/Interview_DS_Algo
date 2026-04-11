
// Time :O(n*m)
// space : O(n+m)
class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int len=m+n-1;

        vector<bool> lockedIdx(len,false);

        string word="";
        for(int i=0;i<len;i++) word+='$';

        // first process ALL 'T'
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){

                for(int j=0;j<m;j++){
                    char filling=str2[j];

                    if(word[i+j]=='$'){
                        word[i+j]=filling;
                    }
                    else if(word[i+j]!=filling) return "";

                    lockedIdx[i+j]=true;
                }
            }
        }

        // fill all places that have '$' with an a
        for(int k=0;k<len;k++){
            if(word[k]=='$'){
                word[k]='a';
            }
        }



        // lets process 'F' now
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                string sub=word.substr(i,m);
                if(sub!=str2) continue;

                // now they are equal
                // we need to find the first Index from right side which is unlocked not in locked Idx
                // try from a to z there 
                // and put that idx into locked one

                int j=i+m-1;
                int idx=-1;
                while(j<len && j>=i){
                    if(lockedIdx[j]==false){
                        idx=j;
                        break;
                    }
                    j--;
                }

                if(idx==-1) return "";

                lockedIdx[idx]=true;

                bool replaced=false;
                for(char c='a';c<='z';c++){
                    // try every possible char there
                    if(c!=str2[idx-i]){
                        replaced=true;
                        word[idx]=c;
                        break;
                    }
                }

                if(!replaced) return "";
            }
        }
        return word;
    }
};
