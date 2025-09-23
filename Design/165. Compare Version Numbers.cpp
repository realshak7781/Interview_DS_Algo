class Solution {
private:
void generateToken(string &version,vector<int>&token){
    stringstream ss(version);
    string temp;

    while(getline(ss,temp,'.')){
        if(temp.empty()) continue;

        token.push_back(stoi(temp));
    }
}
public:
    int compareVersion(string version1, string version2) {
        vector<int> token1;
        generateToken(version1,token1);

        vector<int> token2;
        generateToken(version2,token2);

        int max_len=max(token1.size(),token2.size());
        token1.resize(max_len,0);
        token2.resize(max_len,0);

        int i=0;
        int j=0;

        while(i<token1.size() && j<token2.size()){
            if(token1[i]>token2[j]){
                return 1;
            }
            else if(token1[i]<token2[j]){
                return -1;
            }
            i++;
            j++;
        }

        return 0;
    }
};
