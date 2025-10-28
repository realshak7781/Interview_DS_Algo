struct TrieNode{
    char ch;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char a){
        ch=a;
        isTerminal=false;
        children.resize(26,nullptr);
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
    }


    void insertUtil(TrieNode*root,string s){
        if(s.length()==0){
            root->isTerminal=true;
            return;
        }

        char ch=s[0];
        TrieNode*child;
        if(root->children[ch-'a']){
            child=root->children[ch-'a'];
        }
        else{
            child=new TrieNode(ch);
            root->children[ch-'a']=child;
        }

        insertUtil(child,s.substr(1));
    }

    void insert(string s){
        insertUtil(root,s);
    }
};

class Solution {
private:
Trie t;
unordered_map<int,int> dp;
bool solve(int start,string s){
    if(start>=s.length()){
        return true;
    }

    if(dp.count(start)) return dp[start];
    TrieNode*root=t.root;

    bool res=false;
    for(int split=start;split<s.length();split++){
        TrieNode*child=root->children[s[split]-'a'];

        if(!child){
            break;
        }

        if(child->isTerminal && solve(split+1,s)){
            res=true;
            break;
        }

        root=child;
    }

    return dp[start]=res;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    
        for(string s:wordDict){
            t.insert(s);
        }

        return solve(0,s);
    }
};
