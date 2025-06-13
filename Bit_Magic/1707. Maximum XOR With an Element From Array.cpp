struct TrieNode {
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* pCrawl = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!pCrawl->children[bit]) {
                pCrawl->children[bit] = new TrieNode();
            }
            pCrawl = pCrawl->children[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* pCrawl = root;
        int maxXorVal=0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            int oppositeBit=1-bit;

            if(pCrawl->children[oppositeBit]){
                // opposite bit present and can take it
                maxXorVal=(maxXorVal<<1)|oppositeBit;
                pCrawl=pCrawl->children[oppositeBit];
            }else{
                // opposite bit not present so cannot take it
                maxXorVal=(maxXorVal<<1)|bit;
                pCrawl=pCrawl->children[bit];
            }
        }

        return maxXorVal;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> sortedQuery;
        for(int i=0;i<queries.size();i++){
            sortedQuery.push_back({queries[i][0],queries[i][1],i});
        }

        sort(sortedQuery.begin(),sortedQuery.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        sort(nums.begin(), nums.end());

        Trie t;

        int i=0;
        int n=nums.size();
        vector<int> res(queries.size(),-1);
        int j=0;
        for(int i=0;i<sortedQuery.size();i++){
            int m=sortedQuery[i][1];
            int idx=sortedQuery[i][2];
            int x=sortedQuery[i][0];

            while(j<n && nums[j]<=m){
                t.insert(nums[j]);
                j++;
            }

              if (j > 0) {
                int best = t.findMaxXor(x);
                res[idx] = best^x;
            }
        }

        return res;
    }
};
