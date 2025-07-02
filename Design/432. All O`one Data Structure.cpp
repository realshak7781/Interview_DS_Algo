// optimal: map + dll

struct Node{
    int count;
    unordered_set<string> keys;
    Node* next;
    Node* prev;
    Node(int c){
        count=c;
        next=nullptr;
        prev=nullptr;
    }
};

class AllOne {
private:
unordered_map<string,Node*> mp;
Node*head;
Node*last;    
public:
    AllOne() {
        head=new Node(0);
        last=head;
    }

    void addNode(Node*prevNode,int cnt){
        Node *newNode=new Node(cnt);
        newNode->next=prevNode->next;
        newNode->prev=prevNode;

        if(prevNode->next!=nullptr){
            newNode->next->prev=newNode;
        }
        prevNode->next=newNode;

        if(prevNode==last){
            last=newNode;
        }
    }

    void removeNode(Node*node){
        node->prev->next=node->next;

        if(node->next!=nullptr){
            node->next->prev=node->prev;
        }

        if(last==node){
            last=node->prev;
        }

        delete node;
    }
    
    void inc(string key) {
        if(!mp.count(key)){
            // key doesnt exist --> first entry
            // check if there exists a node with count=1;

            if(head->next==nullptr || head->next->count!=1){
                addNode(head,1);
            }
            head->next->keys.insert(key);
            mp[key]=(head->next);
        }
        else{
            // key exists with some count
            Node *curNode=mp[key];
            int curCnt=curNode->count;

            if(curNode->next==nullptr || curNode->next->count!=curCnt+1){
                // means 2->5 , make it 2->3->5
                addNode(curNode,curCnt+1);
            }

            curNode->next->keys.insert(key);
            mp[key]=curNode->next;
            curNode->keys.erase(key);

            if(curNode->keys.empty()){
                removeNode(curNode);
            }
        }
    }
    
    void dec(string key) {
        Node*curNode=mp[key];
        int curCnt=curNode->count;

        if(curCnt==1){
            mp.erase(key);
        }else{
            if(curNode->prev->count!=(curCnt-1)){
                addNode(curNode->prev,curCnt-1);
            }

            curNode->prev->keys.insert(key);
            mp[key]=curNode->prev;
        }

        curNode->keys.erase(key);
        if(curNode->keys.empty()){
            removeNode(curNode);
        }
    }
    
    string getMaxKey() {
        if(last==head){
            return "";
        }

        return *(last->keys.begin());
    }
    
    string getMinKey() {
        if(head->next==nullptr) return "";

        return *(head->next->keys.begin());
    }
};





// Better:

struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

class AllOne {
private:
    unordered_map<string, int> mp;
    multiset<pair<string, int>, cmp> ms;

public:
    AllOne() {}

    void inc(string key) {
        if (mp.count(key)) {
            int oldCnt = mp[key];
            ms.erase(ms.find({key, oldCnt}));
            mp[key]++;
            ms.insert({key, mp[key]});
        } else {
            mp[key] = 1;
            ms.insert({key, 1});
        }
    }

    void dec(string key) {
        if (!mp.count(key)) return;

        int oldCnt = mp[key];
        ms.erase(ms.find({key, oldCnt}));

        mp[key]--;
        if (mp[key] == 0) {
            mp.erase(key);
        } else {
            ms.insert({key, mp[key]});
        }
    }

    string getMaxKey() {
        if (ms.empty()) return "";
        return ms.rbegin()->first;
    }

    string getMinKey() {
        if (ms.empty()) return "";
        return ms.begin()->first;
    }
};



//BRUTE FORCE : O(N^2)
class AllOne {
private:
unordered_map<string,int> mp; 
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0) mp.erase(key);
    }
    
    string getMaxKey() {
        string maxi="";
        int maxCnt=-1;
        for(auto &it:mp){
            if(it.second>maxCnt){
                maxCnt=it.second;
                maxi=it.first;
            }
        }

        return maxi;
    }
    
    string getMinKey() {
        string mini="";
        int minCount=1e9;

        for(auto &it:mp){
            if(it.second<minCount){
                minCount=it.second;
                mini=it.first;
            }
        }

        return mini;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
