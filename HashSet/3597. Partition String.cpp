class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.length();
        unordered_set<string> vis;
        int i=0;
        int j=0;

        string segment="";
        vector<string> res;
        while(j<n){
            segment+=s[j];
            if(!vis.count(segment)){
                // if current segment is fresh new then add to list and start a new segment:
                vis.insert(segment);
                res.push_back(segment);
                segment="";
                j++;
                i=j;
                continue;
            }

            // its a seen sgement, keep on extending it
            j++;
        }

        return res;
    }
};
