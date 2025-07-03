// DLL APPROACH:

struct Node{
    string url;
    Node*next;
    Node*prev;

    Node(string u){
        url=u;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
private:
Node *head;
Node*cur;    
public:
    BrowserHistory(string homepage) {
        cur=head=new Node(homepage);
    }
    
    void visit(string url) {
         Node* nextPtr=cur->next;
        if(nextPtr!=nullptr){
            cur->next=nullptr;
            nextPtr->prev=nullptr;
        }

        delete nextPtr;

        cur->next=new Node(url);
        cur->next->prev=cur;
        cur=cur->next;
    }
    
    string back(int steps) {
        while(cur!=head && steps>0){
            cur=cur->prev;
            steps--;
        }

        return cur->url;
    }
    
    string forward(int steps) {
        while(cur->next!=nullptr && steps>0){
            cur=cur->next;
            steps--;
        }

        return cur->url;
    }
};



//STACK BASED APPROACH:

class BrowserHistory {
private:    
stack<string> backwardSt;
stack<string> forwardSt;
public:
    BrowserHistory(string homepage) {
        backwardSt.push(homepage);
    }
    
    void visit(string url) {
        while(!forwardSt.empty()){
            forwardSt.pop();
        }
        backwardSt.push(url);
    }
    
    string back(int steps) {
        // the top of backward is current url i am in;
        while(backwardSt.size()>1 && steps>0){
            forwardSt.push(backwardSt.top());backwardSt.pop();
            steps--;
        }
        return backwardSt.top();
    }
    
    string forward(int steps) {
        while(!forwardSt.empty() && steps>0){
            backwardSt.push(forwardSt.top());forwardSt.pop();
            steps--;
        }

        return backwardSt.top();
    }
};
