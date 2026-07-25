// M- No of words in query
// N = number of words in wordsContainer
// Lcontainer=max len of word in container
// Lquery=max len of word in query

// TIME : O(N*Lcontainer + M*Lquery))
// SPACE : O(N*Lcontainer + M)


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminalNode;
    int minWordIdx;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isTerminalNode=false;
        minWordIdx=-1;
    }


    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
};


class Trie{
    public:
    TrieNode *root;

    Trie(){
        root=new TrieNode('\0');
    }

    ~Trie() {
        delete root;
    }
    void insertUtil(TrieNode *root,int curIdx,const string &word,const vector<string> &wordsContainer,int wordIdx){

        if(root->minWordIdx==-1){
            root->minWordIdx=wordIdx;
        }
        else{
            // the letter in the node should come from a string which is lesser in length or if equal should be present earlier in wordcontainer

            int curBestLen=wordsContainer[root->minWordIdx].length();
            int newWordLen=word.length();

            if(curBestLen>newWordLen){
                root->minWordIdx=wordIdx;
            }
        }


        if(curIdx==word.length()){
            root->isTerminalNode=true;
            return;
        }

        int charIdx=word[curIdx]-'a';
        TrieNode*child;

        if(root->children[charIdx]){
            child=root->children[charIdx];
        }
        else{
            child=new TrieNode(word[curIdx]);
            root->children[charIdx]=child;
        }

        insertUtil(child,curIdx+1,word,wordsContainer,wordIdx);
    }


    void insertWord(int wordIdx, const vector<string> &wordsContainer){
        insertUtil(root,0, wordsContainer[wordIdx],wordsContainer,wordIdx);
    }

    int searchWordIdx(const string &query){
        TrieNode*cur=root;

        for(char ch:query){

            if(cur->children[ch-'a']==nullptr){
                break;
            }
            else{
                cur=cur->children[ch-'a'];
            }
        }

        return cur->minWordIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        for(auto &s:wordsContainer){
            reverse(s.begin(),s.end());
        }

        for (auto &q : wordsQuery) {
            reverse(q.begin(), q.end());
        }

        Trie t;

        for(int i=0;i<wordsContainer.size();i++){
            t.insertWord(i,wordsContainer);
        }
        
        vector<int> res;
        for(string &q:wordsQuery){
            res.push_back(t.searchWordIdx(q));
        }

        return res;
    }
};
