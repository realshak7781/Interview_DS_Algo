


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
