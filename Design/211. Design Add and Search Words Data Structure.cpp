// USING  A TRIE D.S.


struct TrieNode{
    char ch;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char c){
        ch=c;
        children.resize(26,nullptr);
        isTerminal=false;
    }
};


class Trie{
    public:
    TrieNode *root=new TrieNode('/');

    void insert(string word){
        TrieNode*node=root;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';

            if(!node->children[index]){
                node->children[index]=new TrieNode(word[i]);
            }
            node=node->children[index];
        }
        node->isTerminal=true;
    }

    bool searchUtil(int idx,TrieNode*root,const string &word){
        if(idx==word.length()){
            return root->isTerminal;
        }

        char cur=word[idx];

        if(cur=='.'){
            // try all children which are not null

            for(int i=0;i<26;i++){
                if(root->children[i]){
                    if(searchUtil(idx+1,root->children[i],word)) return true;
                }
            }
        }
        else{
            int index=cur-'a';
            if(!root->children[index]) return false;
            return searchUtil(idx+1,root->children[index],word);
        }

        return false;
    }


    bool search(string word){
        return searchUtil(0,root,word);
    }
};

class WordDictionary {
public:
    Trie*t;
    WordDictionary() {
        t=new Trie();
    }
    
    void addWord(string word) {
        t->insert(word);
    }
    
    bool search(string word) {
        return t->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


// O(1) AVERAGE : BRUTE FORCE

class WordDictionary {
private:
    unordered_set<string> vis;

public:
    WordDictionary() {
    }

    void addWord(string word) {
        if(vis.count(word)) return;
        vis.insert(word); 
    }

    bool search(string word) {
        int dotCnt = 0;
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                dotCnt++;
                if (idx1 == -1) {
                    idx1 = i;
                } else {
                    idx2 = i;
                    break; 
                }
            }
        }

        if (dotCnt == 0) {
            return vis.count(word);
        } else if (dotCnt == 1) {
            for (char c = 'a'; c <= 'z'; c++) {
                word[idx1] = c;
                if (vis.count(word)) return true;
            }
        } else if (dotCnt == 2) {
            for (char c1 = 'a'; c1 <= 'z'; c1++) {
                word[idx1] = c1;
                for (char c2 = 'a'; c2 <= 'z'; c2++) {
                    word[idx2] = c2;
                    if (vis.count(word)) return true;
                }
            }
        }

        return false;
    }
};
