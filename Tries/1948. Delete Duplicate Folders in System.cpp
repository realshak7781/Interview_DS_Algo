// LEETCODE POTD : 20 JULY 2025
// HEAVY USAGE OF DATA STRUCTURE 
// TEACHES A LOT ABOUT TRIE AND RECURSION

class Solution {
private:
struct Node{
    string val;
    string subFolder;
    unordered_map<string,Node*> children;
};

Node* getNode(string val){
    Node* newNode=new Node();
    newNode->val=val;
    newNode->subFolder="";

    return newNode;
}

void insert(Node*root,vector<string>&path){

    for(auto folder:path){
        if(!root->children.count(folder)){
            // subfolder not present
            root->children[folder]=getNode(folder);
        }

        root=root->children[folder];
    }
}


string populateNodes(Node*root,unordered_map<string,int> &subFolderMap){
    vector<pair<string,string>> p;
    for(auto &[childName,childNode]:root->children){
        string sub=populateNodes(childNode,subFolderMap);
        p.push_back({childName,sub});
    }

    sort(p.begin(),p.end());

    string completePath="";
    // this is the complete subFolderpath of current root;
    for(auto &[childName,childPath]:p){
        completePath+="("+childName+childPath+")";
    }

    root->subFolder=completePath;

    if(!completePath.empty()){
        subFolderMap[completePath]++;
    }

    return completePath;
}


void removeDuplicates(Node*root,unordered_map<string,int> &subFolderMap){

    for(auto it=root->children.begin();it!=root->children.end();){
        Node*child=it->second;
        string childName=it->first;
        if(!child->subFolder.empty() && subFolderMap[child->subFolder]>1){
            it=root->children.erase(it);
        }
        else{
            removeDuplicates(child,subFolderMap);
            ++it;
        }
    }
}

void constructTrie(Node *root,vector<string>&temp,vector<vector<string>>&res){
    
    for(auto &[name,childNode]:root->children){
        temp.push_back(name);
        res.push_back(temp);
        constructTrie(childNode,temp,res);
        temp.pop_back();
    }
}
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node *root=getNode("/");

        for(auto path:paths){
            insert(root,path);
            // construction of trie
        }

        unordered_map<string,int> subFolderMap;
        // count the frequency of duplicate folders;

        populateNodes(root,subFolderMap);

        removeDuplicates(root,subFolderMap);

        vector<string> temp;
        vector<vector<string>> res;
        constructTrie(root,temp,res);

        return res;
    }
};


