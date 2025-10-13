// USING O(1) SPACE 
class Solution {
private:
bool check(string &s1,string &s2){
    vector<int> freq(26,0);

    int i=0,j=0;

    while(i<s1.length() || j<s2.length()){
        if(i<s1.length()){
            freq[s1[i]-'a']++;
            i++;
        }

        if(j<s2.length()){
            freq[s2[j]-'a']--;
            j++;
        }
    }

    for(int i=0;i<26;i++){
        if(freq[i]<0 || freq[i]>0) return false;
    }

    return true;
}
public:
    vector<string> removeAnagrams(vector<string>& words) {
       int n=words.size();

       vector<string> res;

       for(int i=0;i<n;i++){
          string ang=words[i];

          if(res.empty()){
            res.push_back(ang);
          }
          else{
            if(!check(ang,res.back())){
                res.push_back(ang);
            }
          }
       }

       return res;
    }
};



// without stack + a little clean code:
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       int n=words.size();

       vector<string> res;

       for(int i=0;i<n;i++){
          string ang=words[i];

          if(res.empty()){
            res.push_back(ang);
          }
          else{
            string prev=res.back();
            sort(begin(prev),end(prev));
            string sortedAng=ang;
            sort(sortedAng.begin(),sortedAng.end());

            if(sortedAng!=prev){
                res.push_back(ang);
            }
          }
       }

       return res;
    }
};


// Space brute forced + Not clean code : Accepted
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> st;

        for(int i=0;i<words.size();i++){
            string ang=words[i];

            if(st.empty()){
                st.push(ang);
            }
            else{
                string temp=ang;
                sort(begin(temp),end(temp));
                string top=st.top();
                sort(top.begin(),top.end());

                if(top==temp) continue;
                else st.push(ang);
            }
        }

        vector<string> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(begin(res),end(res));
        return res;
    }
};
